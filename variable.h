#include <string>
#include <random>
#include <vector>
#include "function.h"

#ifndef VARIABLE_H
#define VARIABLE_H

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

    public:
        ~DataType();
        std::string name;
        std::vector<BooleanOperator>* boolean_operators;
        std::vector<Function>* methods; 
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
    public:
        Number();
        virtual std::string generate_random_literal() const override;
        std::string generate_random_int() const;
        std::string generate_random_float() const;
};


class Bool : public BuiltInDataType {
    public:
        Bool();
        virtual std::string generate_random_literal() const override;
};


class String : public BuiltInDataType {
    public:
        String(const std::vector<std::string>* words);
        virtual std::string generate_random_literal() const override;
        std::string generate_gibberish() const;
        std::string generate_random_words() const;
    private:
        const std::vector<std::string>* words;
};


class Tuple : public BuiltInDataType {
    public:
        Tuple();
        virtual std::string generate_random_literal() const override;
};


class List : public BuiltInDataType {
    public:
        List();
        virtual std::string generate_random_literal() const override;
};


class Dictionary : public BuiltInDataType {
    public:
        Dictionary();
        virtual std::string generate_random_literal() const override;
};


struct Variable {

    public:
        Variable(std::string name, DataType* type);
        std::string name;
        DataType* type;
    
};


class Class : public DataType {

    public:

        Class(std::string name) : DataType(name) {
            fields = new std::vector<Variable>;
        }

        ~Class() {
            delete fields;
        }

        std::vector<Variable>* fields;

};

#endif
