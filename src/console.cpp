#include "console.hpp"

#include <iostream>

void console::print(const std::string &text)
{
    std::cout << text << std::endl;
}

void console::error(const std::string &text)
{
    std::cout << text << std::endl;
}

void console::warning(const std::string &text)
{
    std::cout << text << std::endl;
}

