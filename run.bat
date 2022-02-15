@echo off

cl.exe  "-ID:\Codes\Research\cpp\finProj\GLFW" "-ID:\Codes\Research\cpp\finProj\GL" "-ID:\Codes\Research\cpp\finProj\GLM" "-ID:\Codes\Research\cpp\finProj\Ext"  /Zi /EHsc Main.cpp CSVReader.cpp Mesh.cpp Shader.cpp Window.cpp MiscFunc.cpp /Fe:"./bin/x64/" /Fo:"./bin/x64/obj"\ /link /LIBPATH:"D:\Codes\Research\cpp\finProj\Ext" glfw3.lib glew32s.lib opengl32.lib shell32.lib user32.lib kernel32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib  ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib msvcrt.lib msvcmrt.lib 
cd "./bin/x64/" && start  Main.exe
cd "./" 
popd