#include <string>
#include <vector>

enum FundamentalType {

    NUMBER,
    BOOL,
    STRING,
    TUPLE,
    LIST,
    DICTIONARY,
    NONE

};

enum BooleanOperator {

    LESS,
    MORE,
    EQUAL,
    LESS_OR_EQUAL,
    MORE_OR_EQUAL,
    NOT_EQUAL,
    AND,
    OR,
    NOT

};

enum ArithmeticOperator {

    PLUS,
    MINUS,
    DIVIDE,
    MULTIPLY

};

enum AssignmentOperator {

    ASSIGN,
    ASSIGN_PLUS,
    ASSIGN_MINUS,
    ASSIGN_DIVIDE,
    ASSIGN_MULTIPLY,
    ASSIGN_AND,
    ASSIGN_OR

};

/*
 * Represents a data type in python. Meant to be stored
 * in a global list of types.
 */
class DataType {

    protected:
        DataType(std::string name);
        ~DataType();

    public:
        std::string name;
        std::vector<BooleanOperator>* boolean_operators;
        std::vector<ArithmeticOperator>* arithmetic_operators;
        std::vector<AssignmentOperator>* assignment_operators;
        bool iterable;

};

/*
 * Represents a built in type in python. Meant to be in the global
 * list of types from the beginning
 */
class BuiltInDataType : public DataType {
    
    public:
        virtual std::string generate_random_literal() const = 0;
    protected:
        BuiltInDataType(std::string name) : DataType(name) {};

};

class Number : public BuiltInDataType {
    Number();
    virtual std::string generate_random_literal() const override;
};

class Bool : public BuiltInDataType {
    Bool();
    virtual std::string generate_random_literal() const override;
};

class String : public BuiltInDataType {
    String();
    virtual std::string generate_random_literal() const override;
};

class Tuple : public BuiltInDataType {
    Tuple();
    virtual std::string generate_random_literal() const override;
};

class List : public BuiltInDataType {
    List();
    virtual std::string generate_random_literal() const override;
};

class Dictionary : public BuiltInDataType {
    Dictionary();
    virtual std::string generate_random_literal() const override;
};

class Variable {

    public:
        std::string get_name() const;
        DataType get_type() const;
        void set_type(DataType t);

    private:
        std::string name;
        DataType type;
    
};

