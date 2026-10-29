#pragma once
#include <vector>
#include "tile.h"
#include "game_object.h"
#include "input_manager.h"
#include "glfw/glfw3.h"

class Grid : public GameObject
{
public:
    float width;
    float height;
    int rows;
    int columns;
    float gap;
    glm::vec4 emptySpace;
    std::vector<Tile> tiles;

    Grid(float width, float height, int rows, int columns, float gap = 5.0f) : width(width), height(height), rows(rows), columns(columns), gap(gap)
    {
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < columns; c++)
            {
                float totalGapX = (columns - 1) * gap;
                float totalGapY = (rows - 1) * gap;
                float f_rows = rows * 1.0f;
                float f_columns = columns * 1.0f;
                glm::vec2 position = glm::vec2(c / f_columns * width, r / f_rows * height);
                glm::vec2 size = glm::vec2((width - totalGapX) / f_columns, (height - totalGapY) / f_rows);
                glm::vec4 texCoords = glm::vec4(c / f_columns, r / f_rows, (c + 1) / f_columns, (r + 1) / f_rows);

                if (r == rows - 1 && c == columns - 1)
                {
                    emptySpace = glm::vec4(position, size);
                    break;
                }

                tiles.push_back(Tile(position, size, texCoords));
            }
        }
    }

    void draw() override
    {
        for (auto &tile : tiles)
        {
            tile.draw();
        }
    }

    void update(float deltaTime) override
    {
        for (auto &tile : tiles)
        {
            if (InputManager::MouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
            {
                float mouseX = InputManager::GetMouseX();
                float mouseY = InputManager::GetOpenGLMouseY();

                if (checkTileClicked(tile, mouseX, mouseY))
                {

                    float distanceFromEmpty = glm::distance(tile.position, glm::vec2(emptySpace));

                    std::cout << "dist: " << distanceFromEmpty << "  size: " << tile.size.x << std::endl; 

                    if (distanceFromEmpty <= tile.size.x)
                    {
                    }
                    // switch positions with empty
                    glm::vec2 oldTilePosition = tile.position;
                    tile.position = glm::vec2(emptySpace);
                    emptySpace.x = oldTilePosition.x;
                    emptySpace.y = oldTilePosition.y;
                }
            }
        }
    }

private:
    bool checkTileClicked(Tile tile, float x, float y)
    {
        if (tile.position.x < x &&
            tile.position.x + tile.size.x > x &&
            tile.position.y < y &&
            tile.position.y + tile.size.y > y)
        {
            return true;
        }

        return false;
    }
};