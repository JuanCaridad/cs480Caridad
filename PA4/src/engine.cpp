#include "engine.h"

Engine::Engine(string name, int width, int height)
{
  m_WINDOW_NAME = name;
  m_WINDOW_WIDTH = width;
  m_WINDOW_HEIGHT = height;
  m_FULLSCREEN = false;
}

Engine::Engine(string name)
{
  m_WINDOW_NAME = name;
  m_WINDOW_HEIGHT = 0;
  m_WINDOW_WIDTH = 0;
  m_FULLSCREEN = true;
}

Engine::~Engine()
{
  delete m_window;
  delete m_graphics;
  m_window = NULL;
  m_graphics = NULL;
}

bool Engine::Initialize(std::string vert, std::string frag, std::string obj)
{
  // Start a window
  m_window = new Window();
  if(!m_window->Initialize(m_WINDOW_NAME, &m_WINDOW_WIDTH, &m_WINDOW_HEIGHT))
  {
    printf("The window failed to initialize.\n");
    return false;
  }

  // Start the graphics
  m_graphics = new Graphics();
  if(!m_graphics->Initialize(m_WINDOW_WIDTH, m_WINDOW_HEIGHT, vert, frag, obj))
  {
    printf("The graphics failed to initialize.\n");
    return false;
  }

  // Set the time
  m_currentTimeMillis = GetCurrentTimeMillis();

  // No errors
  return true;
}

void Engine::Run()
{
  m_running = true;

  while(m_running)
  {
    // Update the DT
    m_DT = getDT();

    // Check the keyboard input
    while(SDL_PollEvent(&m_event) != 0)
    {
      Keyboard();
    }

    // Update and render the graphics
    m_graphics->Update(m_DT);
    m_graphics->Render();

    // Swap to the Window
    m_window->Swap();
  }
}

void Engine::Keyboard()
{
  if(m_event.type == SDL_QUIT)
  {
    m_running = false;
  }
  else if (m_event.type == SDL_KEYDOWN)
  {
    //select which object you want to move
    switch(m_event.key.keysym.sym)
    {
    	case SDLK_1:
    		selection = m_graphics->planet;
    		break;
    	case SDLK_2:
    		selection = m_graphics->moon;
    		break;
    	case SDLK_0:
    		selection = nullptr;
    		break;
    	default:
    		break;
    }
    if(selection != nullptr)
    {
    	// handle key down events here
	switch(m_event.key.keysym.sym)
	{
		case SDLK_ESCAPE:
	    		m_running = false;
	    		break;
	    	case SDLK_a:
	    		selection->rev_Orbit = !(selection->rev_Orbit); //reverse the orbit
	    		break;
	    	case SDLK_d:
	    		selection->pauseOrbit = !(selection->pauseOrbit); //pause the orbit
	    		break;
	    	case SDLK_w:
	    		selection->rev_Spin = !(selection->rev_Spin); //reverse the spin
	    		break;
	    	case SDLK_s:
	    		selection->pauseSpin = !(selection->pauseSpin); //pause the spin
	    		break;
	    	default:
	    		break;
	}
    }
  }
  else if(m_event.type == SDL_MOUSEBUTTONDOWN)
  {
  	if(selection != nullptr)
  	{
  	  //handle mouse button events here
  	  switch(m_event.button.button)
  	  {
  	  	  case SDL_BUTTON_LEFT:
  			  selection->rev_Orbit = !(selection->rev_Orbit); //reverse the orbit
  			  break;
  		  case SDL_BUTTON_RIGHT:
  		 	  selection->pauseOrbit = !(selection->pauseOrbit); //pause the orbit
  			  break;
  		  default:
  			  break;
  	  }
  	}
  }

}

unsigned int Engine::getDT()
{
  long long TimeNowMillis = GetCurrentTimeMillis();
  assert(TimeNowMillis >= m_currentTimeMillis);
  unsigned int DeltaTimeMillis = (unsigned int)(TimeNowMillis - m_currentTimeMillis);
  m_currentTimeMillis = TimeNowMillis;
  return DeltaTimeMillis;
}

long long Engine::GetCurrentTimeMillis()
{
  timeval t;
  gettimeofday(&t, NULL);
  long long ret = t.tv_sec * 1000 + t.tv_usec / 1000;
  return ret;
}
