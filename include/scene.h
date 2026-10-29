#pragma once

#include <vector>
#include "game_object.h"

class Scene
{
public:
    Scene() {}
    std::vector<GameObject *>
        gameObjects;

    void add(GameObject *gameObject)
    {
        gameObjects.push_back(gameObject);
    }

    void update(float deltaTime)
    {
        for (const auto &gameObject : gameObjects)
        {
            gameObject->update(deltaTime);
        }
    }

    void draw()
    {
        for (const auto &gameObject : gameObjects)
        {
            gameObject->draw();
        }
    }
};