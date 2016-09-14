#include <string>

class Function {

    public:
        
    private:

};

class Operator : Function {

    public:
        virtual std::string get_symbol() = 0;

};

class BooleanOperator : Operator {};
class ArithmeticOperator : Operator {};
class IndexOperator : Operator {};

