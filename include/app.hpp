#ifndef MAGIC_TOOL_HPP
#define MAGIC_TOOL_HPP

#include <vector>
#include "controller/fetch.hpp"
#include "controller/csv.hpp"
#include "model/set.hpp"
#include <cxxopts.hpp>

class app
{
public:
    app();
    ~app() = default;
public:
    bool init(int argc, const char **argv);
    bool run();
private:
    std::vector<model::set> m_sets;
    std::vector<model::set> m_filtered_sets;
    controller::fetch m_fetch_controller;
    controller::csv m_csv_controller;
    cxxopts::Options m_cli_options;

    std::string m_file_output;
};

#endif // MAGIC_TOOL_HPP