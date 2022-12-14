//
//  wrapper.hpp
//  cpp_wrapper
//
//  Created by Alexandra on 01.12.2022.
//

#ifndef wrapper_hpp
#define wrapper_hpp

#include <iostream>
#include <map>
#include <functional>
#include <vector>
#include <exception>
#include <stdexcept>

class Wrapper{
public:
    Wrapper() = delete;
    ~Wrapper() = default;
    Wrapper(Wrapper const&) = delete;
    Wrapper& operator=(Wrapper const&) = delete;
    Wrapper(Wrapper&&) = delete;
    Wrapper& operator=(Wrapper&&) = delete;
    
    template<typename Subject, typename... Args>
    Wrapper(Subject* sbj, int (Subject::* subjectMethod)(Args...), const std::map<std::string, int>& args){
        for (auto& item : args) {
            wrapperArgs.first.push_back(item.first);
            wrapperArgs.second.push_back(item.second);
        }
        function = [sbj, subjectMethod, this](const std::vector<int>& args) {
            return callFunction(sbj, subjectMethod, args, std::make_index_sequence<sizeof...(Args)>{});
        };
    }
    
    int execute(std::map<std::string, int>& args);
    
private:
    std::pair<std::vector<std::string>, std::vector<int>> wrapperArgs;
    std::function<int(std::vector<int>& args)> function;
  
    template<typename Subject, typename Function, size_t... Ind>
    int callFunction(Subject* subj, Function func, const std::vector<int> args, std::index_sequence<Ind...>) {
        return (subj->*func)(args[Ind]...);
    }

};

#endif /* wrapper_hpp */
