#include <string>

class Function {

    public:
        
    private:

};

class Operator : Function {

    public:
        virtual std::string get_symbol() = 0;

};

// TODO replace with enums, you don't need polymorphic behavior
class BooleanOperator : Operator {};
class ArithmeticOperator : Operator {};
class IndexOperator : Operator {};

