#pragma once

#include <cppglob/glob.hpp>
#include <string>
#include <filesystem>

namespace eveon
{
    namespace scripting
    {
        class ScriptingEngine
        {
        private:
            /* data */
        public:
            ScriptingEngine(const char* src_dir);
            ~ScriptingEngine();
        };
        
        ScriptingEngine::ScriptingEngine(const char* src_dir)
        {
            std::string pattern = std::string(src_dir) + std::string("**/*.lua");
            std::vector<std::filesystem::path> matches = cppglob::glob(pattern.c_str(), true);
            for (auto &p : matches)
            {
                std::cout << p.u8string() << "\n";
            }
            
        }

        ScriptingEngine::~ScriptingEngine()
        {
        }
        
    } // namespace scripting

} // namespace eveon
