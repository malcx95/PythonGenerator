#include <vector>
#include <string>
#include "variable.h"

std::vector<std::string>* words_init();
std::vector<BuiltInDataType*>* datatypes_init();

namespace constants {

    const static std::vector<std::string>* WORDS = words_init();

    const static std::vector<BuiltInDataType*>* BUILT_IN_DATA_TYPES = datatypes_init();

};
