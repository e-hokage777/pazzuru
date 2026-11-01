#pragma once
#include "glad/gl.h"
#include "GLFW/glfw3.h"
#include "resource_manager.h"

class Screen
{
private:
    GLFWwindow *window;
    void clear();
    void swapBuffers();
    
    public:
    Screen(GLFWwindow *window);
    virtual void update(float deltaTime);
    virtual void cleanUp();
    virtual void draw();
    void render();
};