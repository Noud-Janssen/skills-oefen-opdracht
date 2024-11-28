#ifndef MAGIC_TOOL_CONTROLLER_CSV_HPP
#define MAGIC_TOOL_CONTROLLER_CSV_HPP

#include <vector>
#include <string>
#include "model/set.hpp"

namespace controller
{
    class csv
    {
    public:
        csv() = default;
        ~csv() = default;
    public:
        bool save(const std::vector<model::set> &sets, const std::string &file_name);
    };    
} // namespace controller


#endif // MAGIC_TOOL_CONTROLLER_CSV_HPP