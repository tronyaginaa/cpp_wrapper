//
//  engine.hpp
//  cpp_wrapper
//
//  Created by Alexandra on 27.11.2022.
//

#ifndef engine_hpp
#define engine_hpp

#include "wrapper.hpp"

class Engine{
public:
    Engine() = default;
    ~Engine() = default;
    Engine(Engine const&) = delete;
    Engine& operator =(Engine const&) = delete;
    Engine(Engine&&) = delete;
    Engine& operator =(Engine&&) = delete;
    
    void registerCommand(Wrapper* wrapper, std::string command);
    int execute(const std::string& commandName, std::map<std::string, int> args);
private:
    std::map<std::string, Wrapper*> commands;
};

#endif /* engine_hpp */
