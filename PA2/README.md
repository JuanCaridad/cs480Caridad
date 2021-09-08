# PA2: Interaction

This program will have a multi-colored cube spin around a center axis and orbit around a point. Using keyboard and mouse interaction, the cube will be able to reverse both spin and orbit, while also pausing and unpausing the spin and orbit.

### CMake Instructions
The building of the project is done using CMake, installation with apt-get or brew may be necessary. Later use with CMake and Shader files will be require the copy of a directory where those files are stored (ex. shaders). To do this in the ```add_custom_target``` function place 
```cmake
COMMAND ${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/shaders/ ${CMAKE_CURRENT_BINARY_DIR}/shaders
```

```bash
mkdir build
cd build
cmake ..
make
./Tutorial
```

###Command Line Instructions
After running the cmake command use this in the terminal to run the program:
```bash
./Tutorial -v vert.glsl -f frag.glsl
```

###Keyboard and Mouse Instructions

Reverse Orbit - A or Left Mouse Button <br />
Pause and Unpause Orbit - D or Right Mouse Button <br />
Reverse Spin - W <br />
Pause and Unpause Spin - S <br />
