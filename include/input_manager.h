#pragma once
#include <glfw/glfw3.h>
#include <unordered_map>

class InputManager {
public:
    // Initialize the manager and bind callbacks to the window
    static void Initialize(GLFWwindow* window);

    // Call this at the very end of your frame update loop to clear "Pressed" states
    static void Update();

    // Mouse Button States
    static bool MouseButton(int button);        // True as long as button is held down
    static bool MouseButtonPressed(int button); // True ONLY on the frame it was clicked

    // Mouse Position
    static double GetMouseX() { return m_MouseX; }
    static double GetMouseY() { return m_MouseY; }
    static double GetOpenGLMouseY() { return m_WindowHeight - m_MouseY; } // Flipped Y for OpenGL

private:
    // GLFW Internal Callbacks (Must be static)
    static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    static void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
    static void WindowSizeCallback(GLFWwindow* window, int width, int height);

    // State Tracking
    static std::unordered_map<int, bool> m_MouseButtons;
    static std::unordered_map<int, bool> m_MouseButtonsPressed;
    
    static double m_MouseX;
    static double m_MouseY;
    static int m_WindowHeight;
};
