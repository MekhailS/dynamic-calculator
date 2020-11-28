//
// Created by Mekhail on 15.11.2020.
//

#pragma once

#include "definitions.h"
#include "operation_collection.h"

using ErrorWArrayOfp_ACalcObject = std::pair<Error, std::vector<p_ACalcObject>>;

class Calculator {
    
public:

    /*!
     * Init calculator which supports operations from collection
     * @param operations - collection of operations
     */
    Calculator(OperationCollection operations);

    /*!
     * Calculate an expression represented as string
     * @param str expression
     * @return error and result
     */
    ErrorWDouble calculate(const std::string& str);

private:

    /*!
     * Parse expression string to vector of calculation objects
     * @param str expression
     * @return error and vector of calculation objects
     */
    ErrorWArrayOfp_ACalcObject  parseString(const std::string& str);

    /*!
     * Transform expression represented as vector of calc objects to RPN
     * @param expression as vector of calculation objects
     * @return error and RPN
     */
    static ErrorWArrayOfp_ACalcObject transformToRPN(std::vector<p_ACalcObject>& expression);

    /*!
     * Calculate RPN
     * @param RPN
     * @return error and result
     */
    static ErrorWDouble calculateRPN(std::vector<p_ACalcObject>& RPN);

    /*!
     * Operations collection
     */
    OperationCollection operations;
};
