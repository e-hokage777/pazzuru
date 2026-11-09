#include <vector>
#include "glm/gtc/matrix_transform.hpp"
#include "texture.h"

class UIElement
{
public:
    float x, y, width, height;
    glm::vec3 bgColor;
    Texture sprite;
    bool useSprite;
    UIElement() = default;
    UIElement(float x, float y, float width, float height, glm::vec3 bgColor = glm::vec3(1.0f, 1.0f, 1.0f));
    UIElement(float x, float y, float width, float height, Texture sprite,  glm::vec3 bgColor = glm::vec3(1.0f, 1.0f, 1.0f));
    void add(UIElement, float px = 0, float py = 0);
    void draw();
    void update(float deltaTime);

private:
    std::vector<UIElement> children;

protected:
    void drawChildren();
    void updateChildren(float deltaTime);
};

class Rect : public UIElement
{
public:
    float width, height;
    Rect(float x, float y, float width, float height);
};