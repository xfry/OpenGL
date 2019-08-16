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
 * init - Función que inicia los datos y el contexto de OpenGL
 * description: Esta funcion inicializa cada VAO, VBO y los enlaza con el
 * contexto de OpenGL (GPU), una vez inicializados, se especifica el diseño en
 * memoria del array de vertices (VAO) y se habilitan los primeros
 * componentes a ser manipulados por OpenGL.
 *
 * return: void, o nada.
 */
void init (void)
{
	static const GLfloat vertices[NumVertices][2] = {
		// x      y
		{-0.90, -0.90}, //here start triangle 1
		{0.90, -0.90},
		{0.60, 0.60},
		{0.60, -0.90}, // here start triangle 2
		{-0.60, 0.60},
		{-0.90, -0.90}
	};

	glCreateVertexArrays(NumVAOs, VAOs);
	glBindVertexArray(VAOs[Triangles]);
	glCreateBuffers(NumBuffers, Buffers);
	glNamedBufferStorage(Buffers[ArrayBuffer],
			     sizeof(vertices),
			     vertices,
			     0);


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
	glDrawArrays(GL_POINTS, 0, NumVertices);
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
