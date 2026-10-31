#pragma once
#include <vector>
#include "tile.h"
#include "game_object.h"
#include "input_manager.h"
#include "glfw/glfw3.h"
#include <algorithm>
#include <random>

class Grid : public GameObject
{
public:
    float width;
    float height;
    int rows;
    int columns;
    float gap;
    bool solved;
    glm::vec4 emptySpace;
    std::vector<Tile> tiles;
    std::vector<glm::vec2> targetPositions;

    Grid(float width, float height, int rows, int columns, float gap = 5.0f) : width(width), height(height), rows(rows), columns(columns), gap(gap), solved(false)
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
                targetPositions.push_back(position);
            }
        }

        // shuffle tiles
        shuffle();
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

                    if (distanceFromEmpty <= glm::distance(glm::vec2(emptySpace), glm::vec2(emptySpace) + glm::vec2(emptySpace.z, emptySpace.w)))
                    {
                        // switch positions with empty
                        glm::vec2 oldTilePosition = tile.position;
                        tile.position = glm::vec2(emptySpace);
                        emptySpace.x = oldTilePosition.x;
                        emptySpace.y = oldTilePosition.y;
                    }
                }

                solved = checkSolved();

                if(solved){
                    std::cout << "Solved" << std::endl;
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

    void shuffle()
    {
        // TODO: better shuffling algorithm would be to move the empty space around
        // current implentation may lead to unsolvable puzzles
        std::vector<glm::vec2> positions;

        for (auto &tile : tiles)
        {
            positions.push_back(tile.position);
        }

        std::random_device rd;

        // Initialize the Mersenne Twister engine with the seed
        std::mt19937 g(rd());

        // Shuffle the vector in place
        std::shuffle(positions.begin(), positions.end(), g);

        for (int i = 0; i < tiles.size(); ++i)
        {
            tiles[i].position = positions[i];
        }
    }

    bool checkSolved()
    {
        for (int i = 0; i < tiles.size(); ++i)
        {
            if (glm::distance(tiles[i].position, targetPositions[i]) > 0.0000005)
            {
                return false;
            }
        }

        return true;
    }
};