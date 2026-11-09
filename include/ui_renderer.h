#include "glad/gl.h"
#include "shader.h"
#include "resource_manager.h"
#include "sprite_renderer.h"

class UIRenderer
{
public:
    static unsigned int VAO, VBO, EBO;
    static void initialize();
    static void draw(glm::vec2 position, glm::vec2 size, glm::vec3 color);
    static void UIRenderer::draw(Texture sprite, glm::vec2 position, glm::vec2 size, glm::vec3 color);
    static void drawRect(glm::vec2 position, glm::vec2 size, glm::vec3 color);
    static void drawCircle(glm::vec2 position, float radius);
    static void update(float deltaTime);

private:
    static Shader shader;
};