#include "window.hh"

namespace eveon
{
    namespace graphics
    {
        // void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
        // void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
        // void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);
        void window_resize(GLFWwindow *window, int width, int height);

        EvWindow::EvWindow(str title, int width, int height)
        {
            this->m_title = title;
            this->m_width = width;
            this->m_height = height;
            if (!glfwInit())
                return;

            for (int i = 0; i < MAX_KEYS; i++)
            {
                m_keys[i] = false;
            }

            for (int i = 0; i < MAX_BUTTONS; i++)
            {
                m_mouseButtons[i] = false;
            }

            this->m_window = glfwCreateWindow(this->m_width, this->m_height, this->m_title, NULL, NULL);

            if (!m_window)
            {
                this->Exit(EV_FAILED);
            }
            this->Set();
            if (glewInit() != GLEW_OK)
            {
                std::cout << "Could not initialize GLEW!" << std::endl;
                return;
            }

            
        }

        void EvWindow::Set()
        {
            void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods);
            void mouse_button_callback(GLFWwindow * window, int button, int action, int mods);
            void cursor_position_callback(GLFWwindow * window, double xpos, double ypos);
            void window_resize(GLFWwindow * window, int width, int height);
            glfwMakeContextCurrent(this->m_window);
            glfwSetWindowUserPointer(this->m_window, this);
            glfwSetWindowSizeCallback(this->m_window, window_resize);
            glfwSetKeyCallback(this->m_window, key_callback);
            glfwSetMouseButtonCallback(this->m_window, mouse_button_callback);
            glfwSetCursorPosCallback(this->m_window, cursor_position_callback);
        }

        EvWindow::~EvWindow()
        {
            this->Exit(EV_GRACEFUL_EXIT);
        }

        void EvWindow::Run(void (*func)(EvWindow *))
        {
            while (!glfwWindowShouldClose(this->m_window))
            {

                glClearColor(0.546f, 0.12f, 0.65, 0.5f);

                this->Clear();

                func(this);

                this->Update();
            }
            this->Exit(EV_GRACEFUL_EXIT);
        }

        bool EvWindow::ShoudClose()
        {
            glfwSetWindowShouldClose(this->m_window, GL_TRUE);
            return glfwWindowShouldClose(this->m_window);
        }

        bool EvWindow::isKeyPressed(unsigned int keycode) const
        {
            // TODO: Log this!
            if (keycode >= MAX_KEYS)
                return false;

            return m_keys[keycode];
        }

        bool EvWindow::isMouseButtonPressed(unsigned int button) const
        {
            // TODO: Log this!
            if (button >= MAX_BUTTONS)
                return false;

            return m_mouseButtons[button];
        }

        void EvWindow::getMousePosition(double &x, double &y) const
        {
            x = mx;
            y = my;
        }

        int EvWindow::Exit(EV_EXIT_CODE exit_code)
        {
            glfwTerminate();
            glfwSetWindowShouldClose(this->m_window, GL_FALSE);
            // this->~EvWindow();
            return exit_code;
        }

        void EvWindow::Clear() const
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        void EvWindow::Update()
        {
            glfwPollEvents();
            glfwSwapBuffers(this->m_window);
        }

        void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
        {
            EvWindow *win = (EvWindow *)glfwGetWindowUserPointer(window);
            win->m_keys[key] = action != GLFW_RELEASE;
        }

        void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
        {
            EvWindow *win = (EvWindow *)glfwGetWindowUserPointer(window);
            win->m_mouseButtons[button] = action != GLFW_RELEASE;
        }

        void cursor_position_callback(GLFWwindow *window, double xpos, double ypos)
        {
            EvWindow *win = (EvWindow *)glfwGetWindowUserPointer(window);
            win->mx = xpos;
            win->my = ypos;
        }

        void window_resize(GLFWwindow *window, int width, int height)
        {
            glViewport(0, 0, width, height);
        }
    }
}
