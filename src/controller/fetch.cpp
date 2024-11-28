#include "controller/fetch.hpp"

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <sstream>

#include <nlohmann/json.hpp>

namespace controller
{
    fetch::fetch(const std::string &root_url)
        : m_root_url(root_url)
    {

    }

    bool fetch::fetch_and_fill(std::vector<model::set> &sets)
    {
        // fetch the data
        curlpp::Easy request;
        std::ostringstream result;

        request.setOpt(curlpp::Options::Url(m_root_url + "/sets"));
        request.setOpt(curlpp::Options::HttpHeader({"accept: application/json", "user-agent: csv-tool"}));
        result << request;

        // convert the result into a json object
        nlohmann::json json = nlohmann::json::parse(result.str());

        // check if 
        if (json.contains("data"))
        {
            nlohmann::json data_json = json["data"];
            for (auto &json_set : data_json)
            {
                sets.emplace_back(json_set);
            }

            return true;
        }
        else
        {
            std::cout << "Missing json attribute \"data\"" << std::endl;
            return false;
        }

        return false;
    }
} // namespace controller
