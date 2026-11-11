#include "container.h"

class GridContainer : public Container
{
public:
    int rows, cols;
    GridContainer(float x, float y, float width, float height, int rows, int cols) : Container(x, y, width, height), rows(rows), cols(cols)
    {
    }
    GridContainer() : GridContainer(0, 0, 0, 0, 0, 0) {}

protected:
    void updateChildren(float deltaTime) override
    {
        float cellWidth = width / cols;
        float cellHeight = height / rows;
        float cellOffsetX = cellWidth / 2;
        float cellOffsetY = cellHeight / 2;
        std::size_t numChildren = children.size();

        for (std::size_t i = 0; i < numChildren; ++i)
        {
            int currentRow = i / cols;
            int currentCol = i % cols;

            children[i]->x = x + currentCol * cellWidth + cellOffsetX - children[i]->width / 2.0f;
            children[i]->y = y + height - currentRow * cellHeight - cellOffsetY - children[i]->height / 2.0f;
        }
    }
};