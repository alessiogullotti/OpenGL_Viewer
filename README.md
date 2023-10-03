# OpenGLViewer
The goal of this project is the implementation of a OpenGl Viewer for 3D models. It was developed based on the approach used on the book [ LearnOpenGL](https://learnopengl.com/) by Joey de Vries.
It gives you the possibility to load one file(I tested only with obj format) and its relative textures and create a window to show your rendered model. Camera can be moved using keyboards and mouse.

## Customization
Customization can be done in the Main.cpp file including:
* Camera parameters
* Starting window size
* Change directional light parameters
* Path to file to import



Video Example: https://youtu.be/yuVrAzU-nGY


# Notes
Add to additional includes the Libraries/include folder and to additional libraries the Libraries/lib.
Add also to the linker opengl32.lib


