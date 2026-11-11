#pragma once

#include "container.h"

class ColContainer : public Container
{
public:
    ColContainer() = default;
    ColContainer(float x, float y, float width, float height, glm::vec4 bgColor = glm::vec4(1.0f, 1.0f, 1.0f, 0.0f)) : Container(x, y, width, height, bgColor) {}

protected:
    void updateChildren(float deltaTime) override
    {
        // update children positions
        std::size_t numChildren = children.size();
        float divisionSize = height / numChildren;

        for (int i = 0; i < numChildren; ++i)
        {
            auto &child = children[i];

            child->y = height - (y + i * divisionSize + divisionSize * 0.5f + child->height /2 );
            child->x = x + (width - child->width) * 0.5f;

            child->update(deltaTime);
        }
    }
};