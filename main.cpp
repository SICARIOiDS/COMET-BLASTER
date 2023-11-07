//  MATHCODED.com 
//		est 2021
// Sombrosa Renderer
//		began on 8-18-2023
// 
// 
//  Author: Jonathan P. Wolfe 
//          
//
#include "./Headers/gameEngine.h"

// Opens a GFLW Window until terminated.  
//	defaults used:
// OpenGL Version: 4.6
// Name:           SICARIOiDS
// Resolution:     800x800
// 
//
//
int main()
{
	GameEngine game(false);

	game.initializeGraphics();

	game.run();

	game.close();

	
	return 0;
};
