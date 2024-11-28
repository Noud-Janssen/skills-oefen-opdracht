#ifndef MAGIC_TOOL_MODEL_DATE_HPP
#define MAGIC_TOOL_MODEL_DATE_HPP

#include <string>

namespace model
{
    struct date
    {
        date operator=(const std::string &string);
        bool operator<(const date &other) const;
        std::string to_string() const;

        int year = 0;
        int month = 0;
        int day = 0;
    };
    
} // namespace model


#endif // MAGIC_TOOL_MODEL_DATE_HPP