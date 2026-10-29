#include "resource_manager.h"
#include "scene.h"
#include "sprite_renderer.h"

class Game
{
public:
    Scene *scene;
    int width;
    int height;
    Game(int width, int height, Scene *scene);

    void render();
    void update(float deltaTime);
};