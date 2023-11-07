#ifndef SHIP_CLASS_H
#define SHIP_CLASS_H

#include "../../Libraries/include/glad/gl.h"
#include "rgb.h"
#include "rendererItems.h"
class Ship {
public:
    Ship();
    float centerX = 0.0f;
    float centerY = 0.0f;
    float theta;
    float size;
    int health;
    Rgb color;
   
    GLfloat vertices[20];
    GLuint indices[6] =
    {
        0, 2, 3,
        1, 2, 3
};

    void getVertices();
    void setColor();
    RendererItems rendererItems;
    void preRender();
};

#endif
