#include "model/set.hpp"

namespace model
{
    set::set()
        : m_code("NOT_FOUND"), m_name("NOT_FOUND"), m_scryfall_url("NOT_FOUND"),m_icon_url("NOT_FOUND")
    {

    }

    set::set(nlohmann::json &json)
        : m_code("NOT_FOUND"), m_name("NOT_FOUND"), m_scryfall_url("NOT_FOUND"),m_icon_url("NOT_FOUND")
    {
        if (json.contains("code"))
        {
            m_code = json["code"];
        }
        if (json.contains("name"))
        {
            m_name = json["name"];
        }
        if (json.contains("scryfall_uri"))
        {
            m_scryfall_url = json["scryfall_uri"];
        }
        if (json.contains("released_at"))
        {
            m_released_at = json["released_at"];
        }
        if (json.contains("icon_svg_uri"))
        {
            m_icon_url = json["icon_svg_uri"];
        }
    }
} // namespace model
