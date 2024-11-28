#include "controller/csv.hpp"

#include <fstream>

namespace controller
{
    bool csv::save(const std::vector<model::set> &sets, const std::string &file_name)
    {
        std::ofstream out_file(file_name);

        // add column names
        out_file << "\"Code\",\"Name\",\"Api_url\",\"Released\",\"Icon_url\"\n";

        // add each set
        for (const auto &set : sets)
        {
            out_file << "\"" << set.m_code << "\",";
            out_file << "\"" << set.m_name << "\",";
            out_file << "\"" << set.m_scryfall_url << "\",";
            out_file << "\"" << set.m_released_at.to_string() << "\",";
            out_file << "\"" << set.m_icon_url << "\"\n";
        }

        out_file.close();
        return true;
    }
} // namespace controller
