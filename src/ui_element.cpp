#include "ui_element.h"
#include "ui_renderer.h"

UIElement::UIElement(float x, float y, float width, float height, glm::vec3 bgColor) : x(x), y(y), width(width), height(height), bgColor(bgColor), sprite(sprite) {}
UIElement::UIElement(float x, float y, float width, float height, Texture sprite, glm::vec3 bgColor) : UIElement(x, y, width, height, bgColor)
{
    this->sprite = sprite;
    useSprite = true;
}

void UIElement::draw()
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

void UIElement::update(float deltaTime)
{
    // update self
    // update children
    updateChildren(deltaTime);
}

void UIElement::add(UIElement child, float px, float py)
{
    // add child to list of children of element
    child.x = x + width * px;
    child.y = y + height * py;

    children.push_back(child);
}

void UIElement::drawChildren()
{
    for (auto &child : children)
    {
        child.draw();
    }
}

void UIElement::updateChildren(float deltaTime)
{
    // update children positions
    int numChildren = children.size();
    float divisionSize = width / numChildren;

    for (int i = 0; i < numChildren; ++i)
    {
        children[i].x = i * divisionSize + divisionSize * 0.5f;
        children[i].update(deltaTime);
    }

    // for (auto &child : children)
    // {
    //     child.update(deltaTime);
    // }
}

//////// Rectangle
Rect::Rect(float x, float y, float width, float height) : UIElement(x, y, width, height)
{
}