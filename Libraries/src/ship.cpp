#include "./Headers/ship.h"
#include <cmath>

Ship::Ship() {
    this->getVertices();
    color.set(0.5f, 0.7f, 0.9f);
    this->setColor();
}

void Ship::getVertices() {
    vertices[0] = (GLfloat) centerX+( - 0.1f);
    vertices[1] = (GLfloat) centerY+( - 0.0625f);
    
    vertices[5] = (GLfloat) centerX + (0.1f);
    vertices[6] = (GLfloat) centerY + (-0.0625f);
   
    vertices[10] = (GLfloat) centerX+(0.0f);
    vertices[11] = (GLfloat) centerY+(0.125f);
    
    vertices[15] = (GLfloat) centerX+(0.0f);
    vertices[16] = (GLfloat) centerY-(0.00166f);
   
}

void Ship::setColor() {
    vertices[2] = (GLfloat)color.red;
    vertices[3] = (GLfloat)color.green;
    vertices[4] = (GLfloat)color.blue;

    vertices[7] = (GLfloat)color.red;
    vertices[8] = (GLfloat)color.green;
    vertices[9] = (GLfloat)color.blue;

    vertices[12] = (GLfloat)color.red;
    vertices[13] = (GLfloat)color.green;
    vertices[14] = (GLfloat)color.blue;

    vertices[17] = (GLfloat)color.red;
    vertices[18] = (GLfloat)color.green;
    vertices[19] = (GLfloat)color.blue;
}

void Ship::preRender() {

    
    VAO VAO1;
    rendererItems.VAOs=VAO1;
    rendererItems.VAOs.Bind();

    // Generates Vertex Buffer Object and links it to vertices
    VBO VBO1(vertices, sizeof(vertices));
    // Generates Element Buffer Object and links it to indices
    EBO EBO1(indices, sizeof(indices));
    rendererItems.VBOs=VBO1;
    rendererItems.EBOs=EBO1;
    // Links VBO attributes such as coordinates and colors to VAO
    rendererItems.VAOs.LinkAttrib(rendererItems.VBOs, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
    rendererItems.VAOs.LinkAttrib(rendererItems.VBOs, 1, 3, GL_FLOAT, 5 * sizeof(float), (void*)(2 * sizeof(float)));
    // Unbind all to prevent accidentally modifying them
    rendererItems.VAOs.Unbind();
    rendererItems.VBOs.Unbind();
    rendererItems.EBOs.Unbind();

}