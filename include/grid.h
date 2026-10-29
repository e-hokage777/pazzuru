#pragma once
#include <vector>
#include "tile.h"
#include "game_object.h"

class Grid : public GameObject
{
public:
    float width;
    float height;
    int rows;
    int columns;
    float gap;
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
                    break;
                }

                tiles.push_back(Tile(position, size, texCoords));
            }
        }
    }

    void draw()
    {
        for (auto &tile : tiles)
        {
            tile.draw();
        }
    }
};