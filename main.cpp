#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

struct ColorManager {
    // vals need to be within 0 - 1.0
    float r = 0.f;
    float g = 0.f;
    float b = 0.f;
    float a = 0.f;

    void Normalize()
    {
        if (r > 1.0)
            r = 1.0;
        if (r < 0.0)
            r = 0.0;

        if (g > 1.0)
            g = 1.0;
        if (g < 0.0)
            g = 0.0;

        if (b > 1.0)
            b = 1.0;
        if (b < 0.0)
            b = 0.0;
    }
};

// resize callback
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// process input, escape = indicate window should close
void processInput(GLFWwindow* window, ColorManager& color)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        color.r += 0.01;
    else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        color.r -= 0.01;

    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        color.g += 0.01;
    else if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        color.g -= 0.01;

    if (glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS)
        color.b += 0.01;
    else if (glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS)
        color.b -= 0.01;

    // keep colors in 0.0 - 1.0 range
    color.Normalize();
}

int main()
{
    // color struct to update color w/ user input and save state
    ColorManager clear_color;

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
        // user input
        processInput(window, clear_color);
        system("cls");
        cout << "color [rgba] = [" << clear_color.r << ", " << clear_color.g << ", " << clear_color.b << ", " << clear_color.a << "]";
        // render
        glClearColor(clear_color.r, clear_color.g, clear_color.b, clear_color.a); // define color to set when clear called
        glClear(GL_COLOR_BUFFER_BIT); // clear screen, set to solid color

        // check events/call callbacks
        glfwPollEvents();

        // swap front (display) buffer with back buffer when it's ready render next frame
        glfwSwapBuffers(window);
    }

    // exit when window closed
    glfwTerminate();

    return 0;
}