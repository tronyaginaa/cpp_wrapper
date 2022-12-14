//
//  engine.cpp
//  cpp_wrapper
//
//  Created by Alexandra on 27.12.2022.
//

#include "engine.hpp"

void Engine::registerCommand(Wrapper* wrapper,std::string command) {
    if (!wrapper)
        return;
    if (commands.find(command) == commands.end())
        commands[command] = wrapper;
    return;
}

int Engine::execute(const std::string& command,std::map<std::string, int> args) {
    auto namedArg = commands.find(command);
    if (namedArg == commands.end())
        throw std::invalid_argument("Not such command");
    return namedArg->second->execute(args);
}
