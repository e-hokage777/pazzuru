#include "glad/gl.h"
#include "GLFW/glfw3.h"

class Screen
{
private:
    GLFWwindow *window;
    void clear();
    void swapBuffers();
    void render();

public:
    Screen(GLFWwindow *window);
    virtual void update(float deltaTime);
    void draw();
};