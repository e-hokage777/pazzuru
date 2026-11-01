#include "game.h"
#include "screen_manager.h"
#include "gameplay_screen.h"
#include "mainmenu_screen.h"

Game::Game(int width, int height) : width(width), height(height), window(nullptr)
{
    // initializing window and opengl
    initWindowAndGL();

    // initialize input classes
    InputManager::Initialize(window);
    TextRenderer::init();

    // loading shaders
    ResourceManager::LoadShader("shaders/screen.vs", "shaders/screen.fs", nullptr, "screen");
    ResourceManager::LoadShader("shaders/sprite.vs", "shaders/sprite.fs", nullptr, "sprite");
    ResourceManager::LoadShader("shaders/text.vs", "shaders/text.fs", nullptr, "text");
    // loading textures
    ResourceManager::LoadTexture("assets/enze-fu-1.jpg", false, "puzzle");

    // setting up shadered matrices
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(width), 0.0f, static_cast<float>(height));
    ResourceManager::GetShader("sprite").uniformMat4("projection", projection);
    ResourceManager::GetShader("text").uniformMat4("projection", projection);

    // initializing
    SpriteRenderer::initialize();

    // creating screen manager
    screenManager = ScreenManager();
}

void Game::render()
{
    // scene->draw();
}

void Game::update(float deltaTime)
{
    // scene->update(deltaTime);
}

void Game::frameBufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int Game::initWindowAndGL()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, "My Game", NULL, NULL);

    if (!window)
    {
        std::cout << "ERROR::Unable to initialize window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGL(glfwGetProcAddress))
    {
        std::cout << "ERROR::Failed to initialize GLAD" << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

    // configurations
    glfwSwapInterval(1);

    // these have to be made screen specific configurations
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glfwSetFramebufferSizeCallback(window, Game::frameBufferSizeCallback);

    return 0;
}

void Game::run()
{
;
    // screenManager.setScreen(std::make_unique<GamePlayScreen>(window));
    screenManager.setScreen(std::make_unique<MainMenuScreen>(window));
    // // creating scene
    // // Tile tile = Tile(glm::vec2(0.0f), glm::vec2(80.0f, 60.0f), glm::vec4(0.0f, 0.0f, 1.0f / 10, 1.0f / 10));
    // Grid grid = Grid(800, 600, 2, 2);
    // Scene scene = Scene();
    // scene.add(&grid);

    float lastTime = 0;
    float deltaTime = 0;
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // getting time between frames
        float currentTime = (float)(glfwGetTime());
        deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        // update(deltaTime);
        // render();
        screenManager.update(deltaTime);
        screenManager.render();

        InputManager::Update();
    }
}