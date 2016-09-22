#include <iostream>
#include "boost/program_options.hpp"
#include <string>
#include <vector>
#include "variable.h"
#include <fstream>

const std::string WORDS_FILE_NAME = "../words.txt";

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

std::vector<std::string>* words_init(std::string file_name) {
    std::vector<std::string>* words = new std::vector<std::string>;
    std::ifstream word_file(file_name);
    std::string word;
    while (word_file >> word) {
        words->push_back(word);
    }
    return words;
}


std::vector<BuiltInDataType*> datatypes_init() {
    std::vector<BuiltInDataType*> types;
    types.push_back(new Number);
    // types.push_back(new Bool);
    // types.push_back(new String);
    // types.push_back(new Tuple);
    // types.push_back(new List);
    // types.push_back(new Dictionary);
    return types;
}

int main(int argc, char* argv[])
{
    std::vector<std::string>* args = parse_args(argc, argv);
    const std::vector<std::string>* words = words_init(WORDS_FILE_NAME);
    const std::vector<BuiltInDataType*> built_in_types = datatypes_init();
    String s(words);
    while (true)
    std::cout << s.generate_random_literal() << std::endl;
    return 0;
}
