//
//  main.cpp
//  KnuthMorrisPratt
//
//  Created by Alexey Ischenko on 05.12.2019.
//  Copyright © 2019 Enthropy. All rights reserved.
//

#include <iostream>
#include "kmp.hpp"

int main() {
    std::string pattern;
    std::string source;
    std::cout << "KMP algorithm demo" << std::endl;
    std::cout << "Enter the string you want to search in:" << std::endl;
    std::cin >> source;
    std::cout << "Enter the substring you want to find:" << std::endl;
    std::cin >> pattern;
    std::cout << "Substring starts in the source line at index (src len if not found): " << std::endl;
    std::cout << find_inclusion(source, pattern, 0) << std::endl;
    return 0;
}
