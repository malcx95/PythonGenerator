#include "variable.h"

DataType::DataType(std::string name) {
    this->name = name;
    this->boolean_operators = new std::vector<BooleanOperator>;
    this->arithmetic_operators = new std::vector<ArithmeticOperator>;
    this->assignment_operators = new std::vector<AssignmentOperator>;
    this->iterable = false;
}

DataType::~DataType() {

    delete this->boolean_operators;
    delete this->arithmetic_operators;
    delete this->assignment_operators;

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
    // TODO implement
    return "1";
}

// #################### BOOL ###########################

Bool::Bool() : BuiltInDataType("bool") {
    // TODO implement
}

std::string Bool::generate_random_literal() const {
    // TODO implement
}

// #################### STRING ###########################

String::String() : BuiltInDataType("str") {
    // TODO implement
}

std::string String::generate_random_literal() const {
    // TODO implement
}

// #################### TUPLE ###########################

Tuple::Tuple() : BuiltInDataType("tuple") {
    // TODO implement
}

std::string Tuple::generate_random_literal() const {
    // TODO implement
}

// #################### LIST ###########################

List::List() : BuiltInDataType("list") {
    // TODO implement
}

std::string List::generate_random_literal() const {
    // TODO implement
}


// #################### DICTIONARY ###########################

Dictionary::Dictionary() : BuiltInDataType("dict") {
    // TODO implement
}

std::string Dictionary::generate_random_literal() const {
    // TODO implement
}
