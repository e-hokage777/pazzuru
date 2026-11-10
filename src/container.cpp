#include "container.h"
#include "ui_renderer.h"

Container::Container(float x, float y, float width, float height, glm::vec3 bgColor) : UIElement(x, y, width, height), bgColor(bgColor) {}
Container::Container(float x, float y, float width, float height, Texture sprite, glm::vec3 bgColor) : Container(x, y, width, height, bgColor)
{
    this->sprite = sprite;
    useSprite = true;
}

void Container::draw()
{
    // draw self
    if (useSprite)
    {
        UIRenderer::draw(sprite, glm::vec2(x, y), glm::vec2(width, height), bgColor);
    }
    else
    {
        UIRenderer::draw(glm::vec2(x, y), glm::vec2(width, height), bgColor);
    }
    // draw children
    drawChildren();
}

void Container::update(float deltaTime)
{
    // update self
    // update children
    updateChildren(deltaTime);
}

void Container::add(std::unique_ptr<UIElement> child, float px, float py)
{
    // add child to list of children of element
    child->x = x + width * px;
    child->y = y + height * py;

    children.push_back(std::move(child));
}

void Container::drawChildren()
{
    for (auto &child : children)
    {
        child->draw();
    }
}

void Container::updateChildren(float deltaTime)
{
    // update children positions
    int numChildren = children.size();
    float divisionSize = width / numChildren;

    for (int i = 0; i < numChildren; ++i)
    {
        children[i]->x = x + i * divisionSize + divisionSize * 0.5f;
        children[i]->y = y + (height - children[i]->height) * 0.5f;
        children[i]->update(deltaTime);
    }
}
