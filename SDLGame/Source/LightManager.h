#pragma once

// new OpenGL/GLEW headers:
#define GL3_PROTOTYPES 1
#include "glew.h"
#include "vmath.h"
#include "Math.h"
#include "iostream"
#include "Vector"

class LightManager
{
public:
	static LightManager* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new LightManager();
		}
		return instance;
	}

	void SetupSimpleLighting();
	void ApplyLighting();

	void UpdateL();

	GLfloat lightColor[4] = { 0.6f, 0.7f, 0.8f, 1.0f };
private:

	LightManager();
	~LightManager();

	
	

	static LightManager* instance;
};

