//
//  kmp.cpp
//  KnuthMorrisPratt
//
//  Created by Alexey Ischenko on 05.12.2019.
//  Copyright © 2019 Enthropy. All rights reserved.
//

#include "kmp.hpp"

std::vector<int_fast64_t> prefix_function(const std::string& str){
    std::vector<int_fast64_t> p;
    p.emplace_back(0); //prefix function value for the first element
    
    for (int_fast64_t i = 1; i < str.size(); ++i){
        int_fast64_t k = p[i - 1];
        while (k > 0){
            if (str[i] == str[k]){
                p.emplace_back(k + 1);
                break;
            }
            k = p[k - 1];
        }
        
        if (k == 0){
            p.emplace_back((str[i] == str[0]));
        }
    }
    return p;
}

int_fast64_t find_inclusion(const std::string &str,
                            const std::string &pattern,
                            const int_fast64_t& def_num){
    const auto pattern_prefix_function = prefix_function(pattern);
    int_fast64_t current = 0;
    for (int_fast64_t i = def_num; i < str.size(); ++i){
        const char symbol = str[i];
        int_fast64_t k = current;
        
        if (k == pattern.size()){
            k = pattern_prefix_function[k - 1];
        }
        
        while (k > 0){
            if (pattern[k] == symbol){
                current = k + 1;
                break;
            }
            else {
                k = pattern_prefix_function[k - 1];
            }
        }
        
        if (k == 0){
            current = (symbol == pattern[0]);
        }
        
        if (current == pattern.size()){
            return i - pattern.size() + 1;
        }
    }
    return str.length();
}
