/*
 * PROJECT:         ReactOS PCI Bus driver
 * FILE:            pci.c
 * PURPOSE:         Driver entry
 * PROGRAMMERS:     Casper S. Hornstrup (chorns@users.sourceforge.net)
 * UPDATE HISTORY:
 *      10-09-2001  CSH  Created
 */





// OpenGL Libraries
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Standart GLIBC Headers
#include <stdio.h>



// CodePad Modules and Utilities
#include "shaderutils.h"

// Define OpenGL Version
#define OPENGL_VERSION_MAJOR 4
#define OPENGL_VERSION_MINOR 6







int main() {
    if (!glfwInit()) {
        fprintf(stderr, "GLFW::INIT - Failed to initialize GLFW");
    }
    // Set the OpenGL Version and Profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a GLFW Window
    GLFWwindow* window = glfwCreateWindow(800, 800, "CodePad", NULL, NULL);

    // Check if the window creation failed
    if (window == NULL) {
        fprintf(stderr, "GLFW::WINDOW::CREATE - Failed to create GLFW Window\n");
        glfwTerminate();
        return -1;
    }
    // Make the window the current context 
    glfwMakeContextCurrent(window);


    // Load OpenGl
    gladLoadGL();


    glViewport(0, 0, 800, 800);

    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);


    char* triangle_vertex_source = readShaderSource("resources/shaders/shapes/triangle/vertex.glsl");
    char* triangle_fragment_source = readShaderSource("resources/shaders/shapes/triangle/fragment.glsl");

    

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    

    glfwDestroyWindow(window);
    glfwTerminate();
}