#include "./Headers/gameEngine.h"
#include "./Headers/asteroid.h"
#include "./Headers/ship.h"



GameEngine::GameEngine(bool FULL_SCREEN) 

{
	// Initialize GLFW
	glfwInit();

	// Set OpenGL version.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_VERSION_MINOR);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	// Create <window> Window object.
	// terminal output of if window is created.  if not, terminates and
	// return -1 and exit if fails (need to fix later so that it throws an error. also handle error)
	//
GLFWwindow* w = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, NULL, NULL);
	if (w)
	{
		std::cout << "Created GLFW window" << std::endl;
	}
	else {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	// set <window> to active Window
	window = w;
	glfwMakeContextCurrent(window);
	gladLoadGL(glfwGetProcAddress);
	//set pixel viewport (0,0),(WINDOW_WIDTH,0),(0,WINDOW_HEIGHT),(WINDOW_WIDTH,WINDOW_HEIGHT)
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	Asteroid a(0.75f, 0.75f, 0.1f);
	asteroids.push_back(a);



	// Generates Shader object using shaders defualt.vert and default.frag
	Ship ship;

}
void GameEngine::initializeGraphics() {



	Shader shipShader("../Shaders/ship.vert", "../Shaders/ship.frag");
	shaders.push_back(shipShader);
	
	Shader asteroidShader("../Shaders/asteroid.vert", "../Shaders/asteroid.frag");
	shaders.push_back(asteroidShader);
	// Generates Vertex Array Object and binds it
	uniID = glGetUniformLocation(shaders[0].ID, "scale");
	uniID2 = glGetUniformLocation(shaders[1].ID, "scale");
}
void GameEngine::render() {

	
	ship.preRender();
	asteroids[0].preRender();
		
}
void GameEngine::run() {
	
	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		render();
		
		
		// Specify the color of the background
		glClearColor(CLEAR_RED, CLEAR_GREEN, CLEAR_BLUE, CLEAR_ALPHA);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaders[0].Activate();
		// Assigns a value to the uniform; NOTE: Must always be done after activating the Shader Program
		glUniform1f(uniID, 0.5f);
		// Bind the VAO so OpenGL knows to use it
		ship.rendererItems.VAOs.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		shaders[0].Deactivate();
		shaders[1].Activate();
		glUniform1f(uniID2, 0.5f);
		asteroids[0].rendererItems.VAOs.Bind();
		glDrawElements(GL_TRIANGLE_FAN, 8, GL_UNSIGNED_INT, asteroids[0].indices);
		shaders[1].Deactivate();
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
		
	ship.rendererItems.VAOs.Delete();
ship.rendererItems.VBOs.Delete();
 ship.rendererItems.EBOs.Delete();
	
	asteroids[0].rendererItems.VAOs.Delete();
	asteroids[0].rendererItems.VBOs.Delete();
	asteroids[0].rendererItems.EBOs.Delete();
	getInput(window);
	}

}
void GameEngine::close() {
	// Delete all the objects we've created
	/*for (VAO vao : rendererItems.VAOs)
		vao.Delete();
	for (VBO vbo : rendererItems.VBOs)
		vbo.Delete();
	for (EBO ebo : rendererItems.EBOs)
		ebo.Delete();*/
	for (Shader shader :shaders)
		shader.Delete();
	shaders.clear();
	/*
	rendererItems.VAOs.clear();
	rendererItems.VBOs.clear();
	rendererItems.EBOs.clear();
	*/
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
}

void GameEngine::getInput(GLFWwindow* window)
{
	Input input;
	// Check if the Escape key is pressed
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		input.W = true;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		input.A = true;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		input.S = true;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		input.D = true;
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS)
		input.ctrl = true;
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
		input.Space = true;

	processInput(input);
}
void GameEngine::processInput(Input input) {
	if (input.W == true)
		ship.centerY += .001f;
	if (input.S == true)
		ship.centerY -= .001f;
	if (input.A == true)
		ship.centerX -= .001f;
	if (input.D == true)
		ship.centerX += .001f;
	ship.getVertices();

}