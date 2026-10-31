#include <iostream>
#include "glad/gl.h"
#include "glfw/glfw3.h"
#include "game.h"
#include "scene.h"
#include "tile.h"
#include "sprite_renderer.h"
#include "grid.h"
#include "text_renderer.h"
#include "input_manager.h"
#include "ft2build.h"
#include FT_FREETYPE_H

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;

void frameBufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pazzuru", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to initialize window" << std::endl;
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGL(glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD\n";
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

    // configurations
    glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // creating scene
    Tile tile = Tile(glm::vec2(0.0f), glm::vec2(80.0f, 60.0f), glm::vec4(0.0f, 0.0f, 1.0f / 10, 1.0f / 10));
    Grid grid = Grid(800, 600, 2, 2);
    Scene scene = Scene();
    scene.add(&grid);

    // instantiating game
    Game game = Game(800, 600, &scene);

    // initializing input manager
    InputManager::Initialize(window);

    // initializing text renderer
    TextRenderer::init();

    float lastTime = 0;
    float deltaTime = 0;
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // getting time between frames
        float currentTime = (float)(glfwGetTime());
        deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        game.update(deltaTime);
        game.render();

        if (grid.solved)
        {

            TextRenderer::renderText(ResourceManager::GetShader("text"), "You win", 400.0f, 300.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f));
        }

        glfwSwapBuffers(window);

        InputManager::Update();
    }

    return 0;
}