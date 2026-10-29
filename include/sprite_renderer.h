#pragma once
#include "texture.h"
#include "glm/gtc/matrix_transform.hpp"
#include "resource_manager.h"
#include "texture.h"

class SpriteRenderer
{
private:
    static unsigned int VAO;
    static unsigned int VBO;
    static unsigned int EBO;
    static Shader shader;

public:
    static void initialize();
    static void draw(Texture sprite, glm::vec2 position, glm::vec2 size, glm::vec4 texCoords = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
};