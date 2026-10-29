#include "input_manager.h"

// Define static variables
std::unordered_map<int, bool> InputManager::m_MouseButtons;
std::unordered_map<int, bool> InputManager::m_MouseButtonsPressed;
double InputManager::m_MouseX = 0.0;
double InputManager::m_MouseY = 0.0;
int InputManager::m_WindowHeight = 0;

void InputManager::Initialize(GLFWwindow* window) {
    // Get initial window dimensions for Y-coordinate mapping
    int width;
    glfwGetWindowSize(window, &width, &m_WindowHeight);

    // Register callbacks with GLFW
    glfwSetMouseButtonCallback(window, MouseButtonCallback);
    glfwSetCursorPosCallback(window, CursorPositionCallback);
    glfwSetWindowSizeCallback(window, WindowSizeCallback);
}

void InputManager::Update() {
    // Clear one-frame triggers so they don't fire continuously
    m_MouseButtonsPressed.clear();
}

bool InputManager::MouseButton(int button) {
    auto it = m_MouseButtons.find(button);
    return (it != m_MouseButtons.end()) ? it->second : false;
}

bool InputManager::MouseButtonPressed(int button) {
    auto it = m_MouseButtonsPressed.find(button);
    return (it != m_MouseButtonsPressed.end()) ? it->second : false;
}

void InputManager::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if (action == GLFW_PRESS) {
        m_MouseButtons[button] = true;
        m_MouseButtonsPressed[button] = true; // Set trigger for a single frame
    } 
    else if (action == GLFW_RELEASE) {
        m_MouseButtons[button] = false;
    }
}

void InputManager::CursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
    m_MouseX = xpos;
    m_MouseY = ypos;
}

void InputManager::WindowSizeCallback(GLFWwindow* window, int width, int height) {
    m_WindowHeight = height; // Keep height updated if user resizes window
}
