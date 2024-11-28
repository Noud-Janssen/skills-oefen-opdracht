#ifndef MAGIC_TOOL_CONSOLE_HPP
#define MAGIC_TOOL_CONSOLE_HPP

#include <string>

namespace console
{
    void print(const std::string &text);
    void error(const std::string &text);
    void warning(const std::string &text);
} // namespace console

#endif // MAGIC_TOOL_CONSOLE_HPP