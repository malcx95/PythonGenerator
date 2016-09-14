#include <string>
#include <vector>
#include "function.h"

enum FundamentalType {

    INT,
    FLOAT,
    BOOL,
    STRING,
    TUPLE,
    LIST,
    DICTIONARY

};

class Type {

    public:
        std::string get_name() const;
        std::vector<BooleanOperator> get_boolean_operators() const;
        std::vector<ArithmeticOperator> get_arithmetic_operators() const;
        std::vector<IndexOperator> get_index_operators() const;
    private:
        std::string name;
        std::vector<BooleanOperator> boolean_operators;
        std::vector<ArithmeticOperator> arithmetic_operators;
        std::vector<IndexOperator> index_operators;
    
};

/*
 * Abstract variable class representing a variable in Python.
 *
 */
class Variable {
    
};

