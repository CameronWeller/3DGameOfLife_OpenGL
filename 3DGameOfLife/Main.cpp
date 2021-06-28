#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<chrono>
#include<thread>
#include<windows.h>

int main() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	int xpos, ypos, width, height;
	glfwGetMonitorWorkarea(glfwGetPrimaryMonitor(), &xpos, &ypos, &width, &height);
	std::cout << "width " << width << std::endl << "height" << height << std::endl;

	GLFWwindow* window = glfwCreateWindow(width, height, "the trees are watching", NULL, NULL);
	
	
	if (window==NULL)
	{
		std::cout << "failed to create window my guy sorry" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	gladLoadGL();

	glViewport(0, 0, 1000, 1000);

	for (float i=0; ; i++)
	{
		glfwPollEvents();
	//color rotation 
	// b is for the color and will be proportional to i float
		float a = i / 200;
		float b = i / 200;
		float c = i / 200;
		glClearColor( a,b,c, 1.0f);
		
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
	
		std::this_thread::sleep_for(std::chrono::milliseconds(25));
	}



	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
