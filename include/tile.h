#pragma once

#include "glm/gtc/matrix_transform.hpp"
#include "shader.h"
#include "game_object.h"
#include "sprite_renderer.h"
#include "texture.h"
#include "resource_manager.h"

class Tile : public GameObject
{
public:
    glm::vec4 texCoords;

    Tile(glm::vec2 position, glm::vec2 size, glm::vec4 texCoords) : GameObject(position, size), texCoords(texCoords)
    {
    }

    void draw() override
    {
        SpriteRenderer::draw(ResourceManager::GetTexture("puzzle"), position, size, texCoords);
    }

};