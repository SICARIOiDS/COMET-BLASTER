#include "./Headers/asteroid.h"

Asteroid::Asteroid(float x, float y, float radius){
this->getVertices(x, y, radius);
color.set(1.0f, 0.0f, 0.07f);
this->setColor();
}

void Asteroid::getVertices(float x, float y, float radius) {
	float circleRadius = radius;
	float centerX = x; // Custom x-coordinate for the center of the circle
	float centerY = y; // Custom y-coordinate for the center of the circle
	// Calculate the circle vertices around the custom center position
	for (int i = 0; i < 8; ++i) {
		float angle = 2 * 3.14f * static_cast<float>(i) / 8;
		vertices[i * 5] = x + radius* cos(angle);  // x-coordinate
		vertices[i * 5 + 1] =y + radius * sin(angle);  // y-coordinate
		
	}
	// Define indices for the circle vertices
	
	for (int i = 0; i < 8; ++i) {
		indices[i] = i;
	}
}

void Asteroid::setColor() {
	for (int i = 0; i < 8; ++i) {
		vertices[i * 5 + 2] = color.red; // Red color
		vertices[i * 5 + 3] = color.green; // Green color
		vertices[i * 5 + 4] = color.blue; // Blue color
	}
}
void Asteroid::preRender(){
VAO VAO2;
rendererItems.VAOs =VAO2;

rendererItems.VAOs.Bind();

// Generates Vertex Buffer Object and links it to vertices
VBO VBO2(vertices, sizeof(vertices));
// Generates Element Buffer Object and links it to indices

rendererItems.VBOs =VBO2;
// Links VBO attributes such as coordinates and colors to VAO
rendererItems.VAOs.LinkAttrib(rendererItems.VBOs, 0, 2, GL_FLOAT, 5 * sizeof(float), (void*)0);
rendererItems.VAOs.LinkAttrib(rendererItems.VBOs, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(2 * sizeof(float)));
// Unbind all to prevent accidentally modifying them
rendererItems.VAOs.Unbind();
rendererItems.VBOs.Unbind();


}
