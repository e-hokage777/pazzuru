#pragma once
#include "screen.h"
#include "grid_container.h"
#include "col_container.h"
#include "game.h"
#include "ui_text.h"

class LevelSelectionScreen : public Screen
{
public:
    Game *game;
    GridContainer container;
    Container background;
    ColContainer outerContainer;

    LevelSelectionScreen(GLFWwindow *window, Game *game) : Screen(window), game(game)
    {
        container = GridContainer(0, 0, game->width * 0.7f, game->height * 0.7f, 3, 3);
        container.add(std::make_unique<Container>(0, 0, 120.0f, 120.0f, ResourceManager::GetTexture("puzzle")));
        container.add(std::make_unique<Container>(0, 0, 120.0f, 120.0f, ResourceManager::GetTexture("puzzle")));
        container.add(std::make_unique<Container>(0, 0, 120.0f, 120.0f, ResourceManager::GetTexture("puzzle")));
        container.add(std::make_unique<Container>(0, 0, 120.0f, 120.0f, ResourceManager::GetTexture("puzzle")));

        auto text = std::make_unique<Text>(0, 0, 2, "Select Level", glm::vec3(0, 1.0f, 0.0f));

        outerContainer = ColContainer(0, 0, game->width * 1.0f, game->height * 1.0f);
        outerContainer.add(std::move(text));
        outerContainer.add(std::make_unique<GridContainer>(std::move(container)));

        background = Container(0, 0, game->width, game->height, ResourceManager::GetTexture("mm-background"), glm::vec4(0.3f, 0.3f, 0.3f, 1.0f));
    }

    void update(float deltaTime) override
    {
        // container.update(deltaTime);
        outerContainer.update(deltaTime);
    }

    void draw() override
    {
        background.draw();
        // container.draw();
        outerContainer.draw();
    }
};