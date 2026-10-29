#pragma once
#include "glm/gtc/matrix_transform.hpp"

class GameObject
{
public:
    glm::vec2 position;
    glm::vec2 size;

    GameObject(glm::vec2 position = glm::vec2(0.0f), glm::vec2 size = glm::vec2(1.0f));

    void update(float deltaTime);
    virtual void draw();
};