#ifndef RENDERER_ITEMS_CLASS_H
#define RENDERER_ITEMS_CLASS_H


#include<vector>
#include"shaderClass.h"
#include"VAO.h"
#include "VBO.h"
#include "EBO.h"

class RendererItems {
public:
	RendererItems();
	VAO VAOs;	
	VBO VBOs;
	EBO EBOs;
};
#endif
