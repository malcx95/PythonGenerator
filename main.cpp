#include <iostream>
#include "boost/program_options.hpp"
#include <string>
#include <vector>

std::vector<std::string>* parse_args(int argc, char** argv) {
    namespace po = boost::program_options;
    po::options_description desc("Options");
    desc.add_options()
        ("help", "Print help message")
        ("add,a", "Something");
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    std::vector<std::string>* result = new std::vector<std::string>;
    if (vm.count("add")) {
        result->push_back("add");
    }
    if (vm.count("help")) {
        result->push_back("help");
    }
    return result;
}

int main(int argc, char* argv[])
{
    std::vector<std::string>* args = parse_args(argc, argv);
    for (std::string s : *args) {
        std::cout << s << std::endl;
    }
    return 0;
}
