#include "model/date.hpp"

namespace model
{
    date date::operator=(const std::string &date_string)
    {
        std::string tmp_string = date_string;
        year = std::stoi(tmp_string.substr(0, tmp_string.find("-")));
        tmp_string.erase(0, tmp_string.find("-") + 1);
        month = std::stoi(tmp_string.substr(0, tmp_string.find("-")));
        tmp_string.erase(0, tmp_string.find("-") + 1);
        day = std::stoi(tmp_string.substr(0, tmp_string.find("-")));
        
        return *this;
    }

    bool date::operator<(const date &other) const
    {
        // first check year
        if (year != other.year)
        {
            return year < other.year;
        }
        else if (month != other.month)
        {
            return month < other.month;
        }
        else if (day != other.day)
        {
            return day < other.day;
        }
        return false;
    }

    std::string date::to_string() const
    {
        return std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day); 
    }
} // namespace model
