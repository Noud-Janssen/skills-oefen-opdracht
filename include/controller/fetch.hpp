#ifndef MAGIC_TOOL_CONTROLLER_FETCH_HPP
#define MAGIC_TOOL_CONTROLLER_FETCH_HPP

#include <string>
#include <vector>



#include "model/set.hpp"

namespace controller
{
    class fetch
    {
    public:
        fetch(const std::string &root_url);
        ~fetch() = default;
    public:
        bool fetch_and_fill(std::vector<model::set> &sets);
    private:
        const std::string m_root_url;
    };
} // namespace controller


#endif // MAGIC_TOOL_CONTROLLER_FETCH_HPP