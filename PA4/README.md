# PA3: Moons

This program will have a multi-colored cube spin around a center axis and orbit around a point, as well as another multi-colored cube spining around the first cube like a moon. Using the keyboard, you can select either the bigger cube(planet) or the smaller cube(moon), which will allow mouse and keyboard interactions to reverse the orbit and pause/unpause the object.

### CMake Instructions
The building of the project is done using CMake, installation with apt-get or brew may be necessary. Later use with CMake and Shader files will be require the copy of a directory where those files are stored (ex. shaders). To do this in the ```add_custom_target``` function place 

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
./Tutorial -v vert.glsl -f frag.glsl -o board.obj
```

