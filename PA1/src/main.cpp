#include <iostream>
#include <cstring>

#include "engine.h"

int main(int argc, char **argv)
{	
	std::string vert;
	std::string frag;
	
	int arg = 2;
	if(argc > 1)
	{
		while(arg <= argc)
		{
			if(arg + 1 <= argc && strcmp(argv[arg - 1], "-v") == 0)
			{
				vert = argv[arg];
				arg += 2;
			}
			else if(arg + 1 <= argc && strcmp(argv[arg - 1], "-f") == 0)
			{
				frag = argv[arg];
				arg += 2;
			}
			else
			{
				arg++;
			}
		}
	}
	
	// Start an engine and run it then cleanup after
	Engine *engine = new Engine("Tutorial Window Name", 800, 600);
	if(!engine->Initialize(vert, frag))
	{
  		printf("The engine failed to start.\n");
  		delete engine;
		engine = NULL;
		return 1;
	}
	engine->Run();
	delete engine;
	engine = NULL;
	return 0;
}
