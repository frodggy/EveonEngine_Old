#include "graphics/window.hh"
#include "srcipting/scripting_engine.hh"
#include <toml++/toml.h>
#include <iostream>
#include <string>


using namespace eveon;


void Loop(graphics::EvWindow* win)
{
    glClearColor(0.546f, 0.12f, 0.65, 1.0f);

    if (win->isKeyPressed(GLFW_KEY_ESCAPE)) {
        win->Exit(EV_GRACEFUL_EXIT);
    }
    

}

int main(int argc, char *argv[])
{
    std::string name = (std::string(argv[1]) + std::string("project.ev"));
    toml::parse_result result = toml::parse_file(name);

    std::optional<const char *> project_name = result["project"]["name"].value<const char*>();
    const char *engine_name = "Eveon Engine - ";
    std::string title = std::string(engine_name) + std::string(*project_name);

    std::string project_config_source_dir = *result["project"]["config"]["source_dir"].value<std::string>();

    std::string src_dir = std::string(argv[1]) + project_config_source_dir;

    scripting::ScriptingEngine(src_dir.c_str());

    graphics::EvWindow win(title.c_str(), 1080, 720);
    win.Run(&Loop);
    win.Exit(EV_GRACEFUL_EXIT);
    glfwTerminate();

    return 0;
}
