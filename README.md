# ArduinoWithOpenGL

This Project usese Simple OpenGL implementation to render the data points passed over Serial Port from Arduino sensors. For this project, Arduino is connected to a Servo based HC-SR04 sensor connected to a pan-tilt mechanism. 


## CustomFunction Folder

1. The Includes folder consists of some of the custom functions such as CSV Reader (taken from the internet, don't remember the source. If i come close to the source, I will add the link).
2. The other files consist nothing but functions which will read the shader file, the Mesh Rendered etc. 

## Ext folder

This folder consists of glew32s.lib and glew32.lib files.

## GL 

Consists of GL library

## GLFW

Consists of GLFW library

## GLM

Consists of GLM Library

## Shader 

Consists of Shader files.

## Read.py 

Consists of the code which takes in data from Serial bus and saves it in form of csv.

## Run.Bat 
Works and only runs if you use VC++ and use VSCode with x64 Native Dev Console of Visual Studio.


# How to Run?

1. On Arduino Run your code of gathering data, and give it a delay of 4000 ms, for the sensor to caliberate and the python code to run. 
2. Just after you run Arduino Code, and Run "read.py" let it do the work.
3. after the data is collected, use Run.bat to work.

PS: Do learn how to setup a dev env for OpenGL.
