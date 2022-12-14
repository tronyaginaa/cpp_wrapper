//
//  wrapper.cpp
//  cpp_wrapper
//
//  Created by Alexandra on 01.12.2022.
//

#include "wrapper.hpp"

int Wrapper::execute(std::map<std::string, int>& args){
    std::vector<int> argsVector;
    if(wrapperArgs.first.size() != args.size())
        throw std::invalid_argument("Wrong num of arguments");
    for (auto& elem : wrapperArgs.first) {
        auto arg = args.find(elem);
        if (arg == args.end())
            throw std::invalid_argument("No argument with this name");
        argsVector.push_back(arg->second);
    }
    return function(argsVector);
}

