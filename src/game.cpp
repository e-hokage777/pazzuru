#include "game.h"

Game::Game(int width, int height, Scene *scene) : width(width), height(height), scene(scene)
{
    // loading shaders
    ResourceManager::LoadShader("shaders/sprite.vs", "shaders/sprite.fs", nullptr, "sprite");
    // loading textures
    ResourceManager::LoadTexture("assets/enze-fu-1.jpg", false, "puzzle");

    // setting up shadered matrices
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(width), 0.0f, static_cast<float>(height));
    ResourceManager::GetShader("sprite").uniformMat4("projection", projection);

    // initializing
    SpriteRenderer::initialize();
}

void Game::render()
{
    scene->draw();
}

void Game::update(float deltaTime)
{
    scene->update(deltaTime);
}