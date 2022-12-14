//
//  main.cpp
//  cpp_wrapper
//
//  Created by Alexandra on 14.12.2022.
//

#include "engine.hpp"
#include "subjects.hpp"

int main(int argc, const char * argv[]) {
    
    Subject1 subj_first;
    Wrapper wrapper_first(&subj_first, &Subject1::f2, {{"arg1", 0}, {"arg2", 0}});
    Engine engine_first;
    engine_first.registerCommand(&wrapper_first, "command1");
    std::cout << engine_first.execute("command1", {{"arg1", 4}, {"arg2", 5}}) << std::endl;
    
    Subject2 subj_second;
    Wrapper wrapper_second(&subj_second, &Subject2::f3, {{"arg1", 0}, {"arg2", 0}, {"arg3", 0}});
    Engine engine_second;
    engine_second.registerCommand(&wrapper_second, "command");
    std::cout << engine_second.execute("command", {{"arg1", 4}, {"arg2", 5}, {"arg3", 6}}) << std::endl;
    
    return 0;
}
