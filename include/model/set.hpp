#ifndef MAGIC_TOOL_MODEL_SET_HPP
#define MAGIC_TOOL_MODEL_SET_HPP

#include <string>
#include <nlohmann/json.hpp>

#include "model/date.hpp"

namespace model
{
    struct set
    {
        set();
        set(nlohmann::json &json);

        std::string m_code;
        std::string m_name;
        std::string m_scryfall_url;
        date m_released_at;
        std::string m_icon_url;
    };
} // namespace model


#endif // MAGIC_TOOL_MODEL_SET_HPP