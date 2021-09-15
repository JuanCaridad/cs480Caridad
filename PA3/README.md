# PA3: Moons

This program will have a multi-colored cube spin around a center axis and orbit around a point, as well as another multi-colored cube spining around the first cube like a moon. Using the keyboard, you can select either the bigger cube(planet) or the smaller cube(moon), which will allow mouse and keyboard interactions to reverse the orbit and pause/unpause the object.

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

### Command-Line Instructions
After running the cmake command use this in the terminal to run the program:
```bash
./Tutorial -v vert.glsl -f frag.glsl
```

### Keyboard-and-Mouse Instructions
When the program begins to reverse, pause and unpause and object, the user must first select which object. <br />
Select Planet - 1(not the numpad) <br />
Select Moon - 2(not the numpad) <br />

After selecting the object now the controls below are usable: <br />
Reverse Orbit - A or Left Mouse Button <br />
Pause and Unpause Orbit - D or Right Mouse Button <br />
Reverse Spin - W <br />
Pause and Unpause Spin - S <br />
