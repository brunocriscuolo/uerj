# How to run OpenGL codes
These commands will help you install, compile and run  
your C or C++ code with OpenGL in Ubuntu Linux environment  

##### Install OpenGL and GLUT
`sudo apt-get install freeglut3 freeglut3-dev`
##### Compile and run cpp sample
`g++ sample.cpp -o sample -lglut -lGLU -lGL -lm`
##### Compile and run c sample
`gcc sample.c -o sample -lglut -lGLU -lGL -lm`
