#include "ui_renderer.h"

// defining static variables
unsigned int UIRenderer::VAO = 0;
unsigned int UIRenderer::VBO = 0;
unsigned int UIRenderer::EBO = 0;
Shader UIRenderer::shader;

void UIRenderer::initialize()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    // defining vertices and indices
    float positions[] = {
        0.0f, 1.0f, 0.0f, // top left
        1.0f, 1.0f, 0.0f, // top right
        1.0f, 0.0f, 0.0f, // bottom right
        0.0f, 0.0f, 0.0f  // bottom left
    };

    float normals[] = {
        0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f};

    float texCoords[] = {
        0.0f, 1.0f, // top left
        1.0f, 1.0f, // top right
        1.0f, 0.0f, // bottom right
        0.0f, 0.0f  // bottom left
    };

    unsigned int indices[] = {
        0, 3, 2,
        0, 2, 1};

    // setting up vertex array
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // creating buffers
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(positions) + sizeof(normals) + sizeof(texCoords), NULL, GL_DYNAMIC_DRAW);

    // moving data to array buffer
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(positions), positions);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(positions), sizeof(normals), normals);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(positions) + sizeof(normals), sizeof(texCoords), texCoords);

    // setting attribute pointers
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void *)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void *)(sizeof(positions)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void *)(sizeof(positions) + sizeof(normals)));

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // setting up shader
    shader = ResourceManager::GetShader("ui");
}

void UIRenderer::draw(glm::vec2 position, glm::vec2 size, glm::vec4 color)
{

    glm::mat4 model = glm::mat4(1.0f);

    // translation last
    model = glm::translate(model, glm::vec3(position, 0.0f));

    // scaling
    model = glm::scale(model, glm::vec3(size, 1.0f));

    // configuring shader
    shader.use();
    shader.uniformVec4("color", color);

    shader.uniformMat4("model", model);
    // shader.setTexUnit(0, sprite.ID, "sampler", GL_TEXTURE_2D);
    // shader.uniformVec4("uvRect", texCoord);

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void UIRenderer::draw(Texture sprite, glm::vec2 position, glm::vec2 size, glm::vec3 color)
{

    SpriteRenderer::draw(sprite, position, size, glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), color);
}