#include "constants.h"

std::vector<std::string>* words_init() {
    // TODO implement
    return nullptr;
}


std::vector<BuiltInDataType*>* datatypes_init() {
    std::vector<BuiltInDataType*>* types = new std::vector<BuiltInDataType*>;
    types->push_back(new Number);
    types->push_back(new Bool);
    types->push_back(new String);
    types->push_back(new Tuple);
    types->push_back(new List);
    types->push_back(new Dictionary);
    return types;
}
