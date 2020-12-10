//
//  kmp.hpp
//  KnuthMorrisPratt
//
//  Created by Alexey Ischenko on 05.12.2019.
//  Copyright © 2019 Enthropy. All rights reserved.
//

#ifndef kmp_hpp
#define kmp_hpp

#include <vector>
#include <cstdint>
#include <string>

std::vector<int_fast64_t> prefix_function(const std::string& str);

int_fast64_t find_inclusion(const std::string &str,
                            const std::string &pattern,
                            const int_fast64_t& def_num);

#endif /* kmp_hpp */
