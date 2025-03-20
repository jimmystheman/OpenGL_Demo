#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

// resize callback
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main()
{
    // proj set up
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // create window object
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // check glad is OK
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // set window dimensions
    glViewport(0, 0, 800, 600);

    // callback for window resize
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // while loop to keep program running, check for events
    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window); // swap front (display) buffer with back buffer when it's ready render next frame
        glfwPollEvents();
    }

    // exit when window closed
    glfwTerminate();

    return 0;
}