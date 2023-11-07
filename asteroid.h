#ifndef ASTEROID_CLASS_H
#define ASTEROID_CLASS_H

#include"../../Libraries/include/glad/gl.h"
#include "rgb.h"
#include<cmath>
#include"rendererItems.h"

class Asteroid {
public:
	Asteroid(float x, float y, float radius);
	const int numCircleVertices = 8;
	float circleRadius;

	float centerX;
	float centerY;
	Rgb color;

	static const int ASTEROID_VERTICES = 40;
	static const int ASTEROID_INDICES = 8;
	GLfloat vertices[ASTEROID_VERTICES];
	GLuint indices[ASTEROID_INDICES];
	void getVertices(float x, float y, float radius);
	void setColor();
	RendererItems rendererItems;
	void preRender();
};

#endif