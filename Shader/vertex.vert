#version 460 core
in vec4 pos;
uniform mat4 model;
uniform mat4 projection;
out float point; 

void main()
{
    gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);
    point = pos[3];
    
}