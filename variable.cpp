#include "variable.h"
#include "misc.h"
#include <random>
#include <iostream>
#include <limits>
#include <stdlib.h>

DataType::DataType(std::string name) {
    this->name = name;
    this->boolean_operators = new std::vector<BooleanOperator>;
    this->arithmetic_operators = new std::vector<ArithmeticOperator>;
    this->assignment_operators = new std::vector<AssignmentOperator>;
    this->methods = new std::vector<Function>;
    this->iterable = false;
}

DataType::~DataType() {

    delete this->boolean_operators;
    delete this->arithmetic_operators;
    delete this->assignment_operators;
    delete this->methods;

}

// #################### NUMBER ###########################

Number::Number() : BuiltInDataType("int") {
    this->boolean_operators->push_back(BooleanOperator::LESS);
    this->boolean_operators->push_back(BooleanOperator::MORE);
    this->boolean_operators->push_back(BooleanOperator::EQUAL);
    this->boolean_operators->push_back(BooleanOperator::LESS_OR_EQUAL);
    this->boolean_operators->push_back(BooleanOperator::MORE_OR_EQUAL);
    this->boolean_operators->push_back(BooleanOperator::NOT);
    this->boolean_operators->push_back(BooleanOperator::AND);
    this->boolean_operators->push_back(BooleanOperator::OR);

    this->arithmetic_operators->push_back(ArithmeticOperator::PLUS);
    this->arithmetic_operators->push_back(ArithmeticOperator::MINUS);
    this->arithmetic_operators->push_back(ArithmeticOperator::MULTIPLY);
    this->arithmetic_operators->push_back(ArithmeticOperator::DIVIDE);

    this->assignment_operators->push_back(AssignmentOperator::ASSIGN);
    this->assignment_operators->push_back(AssignmentOperator::ASSIGN_PLUS);
    this->assignment_operators->push_back(AssignmentOperator::ASSIGN_MINUS);
    this->assignment_operators->push_back(AssignmentOperator::ASSIGN_MULTIPLY);
    this->assignment_operators->push_back(AssignmentOperator::ASSIGN_DIVIDE);
}

std::string Number::generate_random_literal() const {
    std::default_random_engine generator;
    generator.seed(std::random_device()());

    // generate ints more often than doubles
    std::uniform_int_distribution<int> int_or_double_dist(0, 3);
    int int_or_double = int_or_double_dist(generator);
    std::cout << int_or_double << std::endl;
    if (int_or_double) {
        return generate_random_int();
    } else {
        return generate_random_float();
    }
}

std::string Number::generate_random_int() const {
    std::default_random_engine generator;
    generator.seed(std::random_device()());
    std::normal_distribution<double> dist(0, 100.0);
    return std::to_string((long) dist(generator));
}

std::string Number::generate_random_float() const {
    std::default_random_engine generator;
    generator.seed(std::random_device()());
    std::normal_distribution<double> dist(0, 100.0);
    return std::to_string(dist(generator));
}

// #################### BOOL ###########################

Bool::Bool() : BuiltInDataType("bool") {
    this->boolean_operators->push_back(BooleanOperator::NOT);
    this->boolean_operators->push_back(BooleanOperator::AND);
    this->boolean_operators->push_back(BooleanOperator::OR);
    this->boolean_operators->push_back(BooleanOperator::EQUAL);
    this->boolean_operators->push_back(BooleanOperator::NOT_EQUAL);

    this->assignment_operators->push_back(AssignmentOperator::ASSIGN);
    this->assignment_operators->push_back(AssignmentOperator::ASSIGN_OR);
    this->assignment_operators->push_back(AssignmentOperator::ASSIGN_AND);
}

std::string Bool::generate_random_literal() const {
    std::default_random_engine generator;
    generator.seed(std::random_device()());
    std::uniform_int_distribution<int> dist(0, 1);
    if (dist(generator)) {
        return "True";
    }
    else {
        return "False";
    }
}

// #################### STRING ###########################

String::String(const std::vector<std::string>* words) : BuiltInDataType("str") {
    this->boolean_operators->push_back(BooleanOperator::LESS);
    this->boolean_operators->push_back(BooleanOperator::MORE);
    this->boolean_operators->push_back(BooleanOperator::EQUAL);
    this->boolean_operators->push_back(BooleanOperator::LESS_OR_EQUAL);
    this->boolean_operators->push_back(BooleanOperator::MORE_OR_EQUAL);
    this->boolean_operators->push_back(BooleanOperator::NOT);

    this->arithmetic_operators->push_back(ArithmeticOperator::PLUS);

    this->assignment_operators->push_back(AssignmentOperator::ASSIGN);
    this->assignment_operators->push_back(AssignmentOperator::ASSIGN_PLUS);
    this->iterable = true;
    this->words = words;
}

std::string String::generate_random_literal() const {
    std::default_random_engine generator;
    generator.seed(std::random_device()());

    std::uniform_int_distribution<int> dist(0, 3);

    if (dist(generator)) {
        return generate_random_words();
    } else {
        return generate_gibberish();
    }
}

std::string String::generate_gibberish() const {
    std::default_random_engine generator;
    generator.seed(std::random_device()());
    std::normal_distribution<double> length_dist(0, 100);
    std::string result = "";
    std::uniform_int_distribution<int> dist(32, 126);
    for (unsigned i = 0; i < abs((int)length_dist(generator)); ++i) {
        int code = dist(generator);
        bool escape = 
            code == 34 ||
            code == 39 ||
            code == 92;
        if (escape) result += '\\';
        result += ((char) code);
    }
    return '\"' + result + '\"';
}

std::string String::generate_random_words() const {
    std::default_random_engine generator;
    generator.seed(std::random_device()());
    std::normal_distribution<double> length_dist(0, 10);

    const std::vector<char> punctuation = {
        '.', '.', '.', '!', '?'
    };

    std::uniform_int_distribution<int> shall_have_punct_dist(0, 3);
    std::uniform_int_distribution<int> punct_dist(0, punctuation.size() - 1);

    std::string result = "";
    for (unsigned i = 0; i < abs((int)length_dist(generator)); ++i) {
        result += misc::get_random_word(words) + ' ';
    }
    result += misc::get_random_word(words);
    if (!shall_have_punct_dist(generator)) {
        result += punctuation[punct_dist(generator)];
    }
    return '\"' + result + '\"';
}

// #################### TUPLE ###########################

Tuple::Tuple() : BuiltInDataType("tuple") {
    this->boolean_operators->push_back(BooleanOperator::LESS);
    this->boolean_operators->push_back(BooleanOperator::MORE);
    this->boolean_operators->push_back(BooleanOperator::EQUAL);
    this->boolean_operators->push_back(BooleanOperator::LESS_OR_EQUAL);
    this->boolean_operators->push_back(BooleanOperator::MORE_OR_EQUAL);
    this->boolean_operators->push_back(BooleanOperator::NOT);

    this->arithmetic_operators->push_back(ArithmeticOperator::PLUS);

    this->assignment_operators->push_back(AssignmentOperator::ASSIGN);
    this->iterable = true;
}

std::string Tuple::generate_random_literal() const {
    return "()";
}

// #################### LIST ###########################

List::List() : BuiltInDataType("list") {
    this->boolean_operators->push_back(BooleanOperator::LESS);
    this->boolean_operators->push_back(BooleanOperator::MORE);
    this->boolean_operators->push_back(BooleanOperator::EQUAL);
    this->boolean_operators->push_back(BooleanOperator::LESS_OR_EQUAL);
    this->boolean_operators->push_back(BooleanOperator::MORE_OR_EQUAL);
    this->boolean_operators->push_back(BooleanOperator::NOT);

    this->arithmetic_operators->push_back(ArithmeticOperator::PLUS);

    this->assignment_operators->push_back(AssignmentOperator::ASSIGN);
    this->assignment_operators->push_back(AssignmentOperator::ASSIGN_PLUS);
    this->iterable = true;
}

std::string List::generate_random_literal() const {
    return "[]";
}


// #################### DICTIONARY ###########################

Dictionary::Dictionary() : BuiltInDataType("dict") {
    this->boolean_operators->push_back(BooleanOperator::LESS);
    this->boolean_operators->push_back(BooleanOperator::MORE);
    this->boolean_operators->push_back(BooleanOperator::EQUAL);
    this->boolean_operators->push_back(BooleanOperator::LESS_OR_EQUAL);
    this->boolean_operators->push_back(BooleanOperator::MORE_OR_EQUAL);
    this->boolean_operators->push_back(BooleanOperator::NOT);

    this->assignment_operators->push_back(AssignmentOperator::ASSIGN);
    this->iterable = true;
}

std::string Dictionary::generate_random_literal() const {
    return "{}";
}

Variable::Variable(std::string name, DataType* type) {
    this->type = type;
    this->name = name;
}

