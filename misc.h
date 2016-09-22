#ifndef MISC_H
#define MISC_H

#include <vector>
#include <string>
#include <random>
#include "variable.h"

namespace misc {

    std::string get_random_word(const std::vector<std::string>* words) {
        std::default_random_engine generator;
        generator.seed(std::random_device()());
        std::uniform_int_distribution<int> dist(0, words->size() - 1);

        return (*words)[dist(generator)];
    }
}

#endif
