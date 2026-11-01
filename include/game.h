#pragma once
#include "resource_manager.h"
#include "scene.h"
#include "sprite_renderer.h"
#include "glad/gl.h"
#include "GLFW/glfw3.h"
#include "scene.h"
#include "tile.h"
#include "sprite_renderer.h"
#include "grid.h"
#include "text_renderer.h"
#include "input_manager.h"
#include "screen_manager.h"
#include "ft2build.h"
#include FT_FREETYPE_H

class Game
{
public:
    int width;
    int height;
    GLFWwindow *window;
    ScreenManager screenManager;

    Game(int width, int height);

    void render();
    void update(float deltaTime);
    void run();

private:
    static void frameBufferSizeCallback(GLFWwindow *window, int width, int height);
    int initWindowAndGL();
};