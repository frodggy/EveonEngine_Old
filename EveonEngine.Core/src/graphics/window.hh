#include <iostream>
#include "../types.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

namespace eveon
{
    namespace graphics
    {

        class EvWindow
        {
        private:
            GLFWwindow *m_window;
            str m_title;
            float m_height, m_width;
            bool m_keys[MAX_KEYS];
            bool m_mouseButtons[MAX_BUTTONS];
            double mx, my;

        public:
            EvWindow(str title, int width, int height);
            void Run(void (*func)(EvWindow *));
            int Exit(EV_EXIT_CODE exit_code);
            bool isKeyPressed(unsigned int keycode) const;
            bool isMouseButtonPressed(unsigned int button) const;
            void getMousePosition(double &x, double &y) const;
            bool ShoudClose();
            ~EvWindow();

        private:
            void Clear() const;
            void Update();
            void Set();
            friend void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
            friend void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
            friend void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);
            friend void window_resize(GLFWwindow *window, int width, int height);
        };
    }
}
