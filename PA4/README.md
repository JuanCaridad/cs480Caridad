# PA4: Object Loader

This program will be able to load in any object using an object loader that was created. This object was created from blender, and should be able to load in.

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

