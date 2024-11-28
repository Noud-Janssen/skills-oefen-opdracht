#include "app.hpp"

#include "console.hpp"
#include "model/date.hpp"
#include <iostream>

app::app()
    : m_fetch_controller("https://api.scryfall.com"), m_cli_options("magic_tool","A simple tool to get the latest magic the gathering cards")
{
    m_cli_options.add_options()
    ("f,file","File to write to",cxxopts::value<std::string>()->default_value("cards.csv"));
}

bool app::init(int argc, const char **argv)
{
    try
    {
        auto cli_results = m_cli_options.parse(argc,argv);
        m_file_output = cli_results["file"].as<std::string>();
    }
    catch(const std::exception& e)
    {
        console::error(e.what());
        return false;
    }
    
    return true;
}

bool app::run()
{
    // fetch all data, and parse it into sets
    console::print("Fetching all data");
    if (!m_fetch_controller.fetch_and_fill(m_sets))
    {
        console::error("Failed to fetch all data");
        return false;
    }

    struct
    {
        bool operator()(model::set a, model::set b) const {

            return a.m_released_at < b.m_released_at;
        }
    }
    sort_by_release_date;

    // filter all unofficial sets
    std::copy_if(
        m_sets.begin(), 
        m_sets.end(), 
        std::back_inserter(m_filtered_sets), 
        [](model::set &set){
            return set.m_code.size() == 3;
    });


    // sort the sets based on their release date
    std::sort(m_filtered_sets.begin(), m_filtered_sets.end(), sort_by_release_date);

    // save the sets into a cards.csv file
    if (!m_csv_controller.save(m_filtered_sets, m_file_output))
    {
        console::error("Failed to save sets to " + m_file_output);
        return false;
    }
    console::print("Saved sets to " + m_file_output);
    return true;
}