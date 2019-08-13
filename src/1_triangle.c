/** 1_triangle.c */

#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

/**
 * Declare some repetitive constants
 */
enum VAO_IDs {Triangles, NumVAOs};
enum Buffers_IDs { ArrayBuffer, NumBuffers};
enum Attrib_IDs { vPosition = 0 };
enum {NumVertices = 6};

GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];

/**
 * init - This function start the settup of the OpenGL context
 * description: Here you will found the data needed to build two
 * triangles at screen. You will create the buffer, bind the
 * VAOs objects to the Opengl Context.
 */
void init (void)
{
	static const GLfloat vertices[NumVertices][2] = {
		{-0.90f, 0.90f}, //here start triangle 1
		{0.85f, 0.90f},
		{-0.90f, 0.85f},
		{0.90f, 0.85f}, // here start triangle 2
		{0.90f, 0.90f},
		{-0.85f, 0.90f}
	};
	
	glCreateVertexArrays(NumVAOs, VAOs);
	glCreateBuffers(NumBuffers, Buffers);
	glNamedBufferStorage(Buffers[ArrayBuffer],
			     sizeof(vertices),
			     vertices,
			     0);

	glBindVertexArray(VAOs[Triangles]);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
	glVertexAttribPointer(vPosition, 2, GL_FLOAT,
			      GL_FALSE, 0,  0);

	glEnableVertexAttribArray(vPosition);
}
/**
 * display - a function to display triangles
 */
void display(void)
{
	static const float black[] = {0.0, 0,10, 0,10};
	glClearBufferfv(GL_COLOR, 0, black);

	glBindVertexArray(VAOs[Triangles]);
	glDrawArrays(GL_TRIANGLES, 0, NumVertices);
}
/**
 * main
 */

int main(int argc, char **argv)
{
	(void)argv;
	(void)argc;

	glfwInit();

	GLFWwindow *window = glfwCreateWindow(800,600, "Trianlge",
					      NULL, NULL);

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;
	glewInit();
	init();

	while(!glfwWindowShouldClose(window))
	{
		display();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
}
