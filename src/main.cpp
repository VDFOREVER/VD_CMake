#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

GLfloat point[] = {
    0.0f, 0.5f, 0.0f,
    0.5, -0.5f, 0.0f,
    -0.5, -0.5f, 0.0f
};

GLfloat color[] = {
    1.0f,0.0f,0.0f,
    0.0f,1.0f,0.0f,
    0.0f,0.0f,1.0f
};

int g_windowsSizeX = 640;
int g_windowsSizeY = 480;

void glfwWindowSizeCallback(GLFWwindow* window, int width, int height){
    g_windowsSizeX = width;
    g_windowsSizeY = height;
    glViewport(0, 0, g_windowsSizeX, g_windowsSizeY);
   // cout << width << " x " << height << endl; // Для проверки разрешение окна
}

void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
    {
        cout << "glfwInit failad!" << endl;
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(g_windowsSizeX, g_windowsSizeY, "VD_CMake", nullptr, nullptr);
    if (!window)
    {
        cout << "faller glfwCreateWindow" << endl;
        glfwTerminate();
        return -1;
    }

    glfwSetWindowSizeCallback(window, glfwWindowSizeCallback);
    glfwSetKeyCallback(window, glfwKeyCallback);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if(!gladLoadGL()){
cout << "Can't load GLAD" << endl;
return -1;
    }
    cout << "Render: " << glGetString(GL_RENDERER) <<endl;
    cout << "OPENGL Version: " << glGetString(GL_VERSION) << endl;
    glClearColor(1,1,0,1);
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}