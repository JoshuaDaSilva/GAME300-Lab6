#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// for loading sprites
#include "Utils.h"
#include "SDLHelper.h"

#define TINYOBJLOADER_IMPLEMENTATION

#include "SDL.h"

#include "GamePlayManager.h"
#include "ShaderManager.h"

// new OpenGL/GLEW headers:
//#define GL3_PROTOTYPES 1
#include "glew.h"

#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   600

// Our opengl context handle
SDL_GLContext GLContext;
SDL_Window *window;

// GameState
bool GameRunning = true;

int main(int argc, char *argv[])
{
	srand(time(NULL));

	if (!SDLHelper::Init())
	{
		return false;
	}

	// this will run for 1500ms before allowing input
	SDLHelper::DisplaySplashScreen();

	glEnable(GL_DEPTH_TEST);

	ShaderManager::GetInstance()->LoadShaders();
	GamePlayManager::GetInstance()->InitGameplay();

	// Main game loop
	while (GameRunning) 
	{
		// the order of everything within this loop is very important.
		// handle button events
		GameRunning = EventHandler::Update();
		// pause to control framerate
		SDL_Delay(3);

		//glClearColor(0.0, 0.0, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		  
		static const GLfloat color[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		glClearBufferfv(GL_COLOR, 0, color);
		glUseProgram(0);


		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glFrustum(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1000.0f);

		glMatrixMode(GL_MODELVIEW);
		
		GamePlayManager::GetInstance()->Update();
		SDL_GL_SwapWindow(SDLHelper::GetWindow());
	}

	ShaderManager::GetInstance()->Shutdown();
	SDL_Quit();

	return true;
}