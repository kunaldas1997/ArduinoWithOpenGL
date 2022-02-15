#version 460 core

in float vCol[];
out vec4 color;
void main()
{
	for(int i =0; i<sizeof(vCol)-1;++i)
	{
		if(vCol[i] <= 0.1)
		{
			color = vec4(1.0, 1.0, 1.0, 1.0);
		}
		else
		{
			color = vec4(0.3, 0.1, 0.2.1.0);
		}
	}
	
	
}