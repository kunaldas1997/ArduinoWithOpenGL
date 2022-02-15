#include "includes.h"
#include <cmath>


//	For Switching to Nvidia Optimus in Laptops.
extern "C" {
	_declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
}



/* Global Declaration Space */
std::vector<Mesh*> meshModel;
std::vector<Shader> shaderList;
CSVReader csv;
MiscFunc misc;


static const char* vShader = "Shader/vertex.vert";
static const char* fShader = "Shader/fragment.frag";
// static const char* gShader = "Shader/geometry.geom";
// static const char* gFShader = "Shader/geofragment.frag";


bool direction = true;

float angle = 30.0f;
float tri_offset = 0.0f;

float tri_max_offset = 0.1f;
float tri_increment = 10.9f;

bool sizeDirection = true;
float curSize = 0.4f;
float maxSize = 0.8f;
float minSize = 0.1f;

const float radians = 3.14159265f / 180.0f;


std::vector<std::vector<int>> dataInt; // final data array
std::map<std::map<float, float>, float> mapData;
std::vector<float> vertices;
std::vector<unsigned int> indices;


/* Global Declaration Space */



/* Global Functions */



void csvData()
{
	std::string filename = "test.txt";
	dataInt = csv.ReadCSV(filename);

}


void createVertexMatrix()
{

	// getting max value from the data
	int x_val = dataInt[dataInt.size() - 1][2];
	int y_val = dataInt[dataInt.size() - 1][1];
	int val = dataInt[0][0];


	for (int i = 1; i < dataInt.size(); ++i)
	{
		if (dataInt[i][0] > val)
		{
			val = dataInt[i][0];
		}
	}

	// dataMap
	for (int i = 0; i < dataInt.size(); ++i)
	{
		std::map<float, float> tmp;
		float tmpVal = 0;
		for (int j = 0; j < dataInt[0].size(); ++j)
		{
			//	(int)<y,x> -> (float)<x,y>
			tmp.insert({ misc.FloatConv(dataInt[i][dataInt[0].size() - 1]) / misc.FloatConv(x_val) , misc.FloatConv(dataInt[i][dataInt[0].size() - 2]) / misc.FloatConv(y_val) });
			

			//	(int)val -> (float)val
			tmpVal = misc.FloatConv(dataInt[i][0]) / misc.FloatConv(val);
			

		}
		mapData.insert({ tmp, tmpVal});

		
	}


	for (auto& i : mapData)
	{
		for (auto& j : i.first)
		{
			vertices.push_back(j.second);
			vertices.push_back(j.first);
			vertices.push_back(0.0f);
			vertices.push_back(i.second);
		}

		
		
	}

	

	for (int i = 0; i < vertices.size(); ++i)
	{
		indices.push_back(i);

	}

}

void CreateObjects()
{
	/*unsigned int indices[] =
	{
		0,3,1,
		1,3,2,
		2,3,0,
		0,1,2
	};*/

	/*float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.3f, -0.5f, 1.0f,
		0.0f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f
	};*/

	
	Mesh* obj = new Mesh();
	obj->CreateMesh(vertices);
	meshModel.push_back(obj);
}

void CreateShader()
{
	Shader* shader = new Shader();
	shader->CreateShaderFromFile(vShader, fShader);
	shaderList.push_back(*shader);
}
/* Global Functions */

Window window;

int main()
{
	//	initialize Window
	window = Window(800, 800);
	window.initialize();

	csvData();
	createVertexMatrix();

	glm::mat4 projection = glm::mat4(1.0f);
	CreateObjects();
	CreateShader();

	unsigned int uniformModel = 0, uniformProjection = 0;
	//	 loop until window closes
	while (!window.getWindowClose())
	{

		glfwPollEvents();
		//	 clear window color
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);




		//	clear either color buffer bit or depth buffer bit
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		shaderList[0].UseShader();
		uniformModel = shaderList[0].GetModel();
		uniformProjection = shaderList[0].GetProjectionLocation();

		angle += 0.5f;
		if (angle >= 360)
		{
			angle -= 360;
		}


		glm::mat4 model(1.0f);
		model = glm::translate(model, glm::vec3(-1.0f, -1.0f, -5.0f));

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));

		meshModel[0]->RenderMesh();

		glUseProgram(0);
		window.swapBuffers();
	}


	return 0;
}