#include "LightManager.h"
#include "EventHandler.h"

LightManager* LightManager::instance = nullptr;


LightManager::LightManager()
{
}


LightManager::~LightManager()
{
}

void LightManager::SetupSimpleLighting()
{
	glLightModeli(GL_LIGHT_MODEL_AMBIENT, 1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightColor);
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.7);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.01);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
}

void LightManager::ApplyLighting()
{
	static GLfloat lightPosition[4];
	lightPosition[0] = 0.0f;
	lightPosition[1] = 0.0f;
	lightPosition[2] = 0.0f;
	lightPosition[3] = 0.0f;

	static GLfloat lightdirection[4];
	lightPosition[0] = 0.0f;
	lightPosition[1] = 0.0f;
	lightPosition[2] = -1.0f;
	lightPosition[3] = 1.0f;

	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lightdirection);
}

void LightManager::UpdateL()
{
	
	
	if (EventHandler::events[ControlsEvents::UP_PRESSED])
	{
		
		if (lightColor[0] < 1.0f)
		{
			lightColor[0] += 0.1f;
			lightColor[1] = 0.0f;
		}
		else if (lightColor[1] <1.0f)
		{
			lightColor[1] += 0.1f;
			lightColor[2] = 0.0f;

		}
		else if (lightColor[2] < 1.0f)
		{
			lightColor[2] += 0.1f;
			lightColor[0] = 0.0f;
		}
		
		
		
		std::cout << "Up pressed";
		//lightColor[3] += 0.1f;
	}

	if (EventHandler::events[ControlsEvents::DOWN_PRESSED])
	{
		lightColor[0] -= 0.1f;
		lightColor[1] -= 0.1f;
		lightColor[2] -= 0.1f;
		lightColor[3] -= 0.1f;
	}
}