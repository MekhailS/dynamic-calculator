//
// Created by Mekhail on 15.11.2020.
//

#include "calculator.h"

#include "basic_objects/number.h"

/*!
* Init calculator which supports operations from collection
* @param operations - collection of operations
*/
Calculator::Calculator(OperationCollection operations)
{
    this->operations = operations;
}

/*!
* Calculate an expression represented as string
* @param str expression
* @return error and result
*/
ErrorWDouble Calculator::calculate(const std::string& str)
{
    ErrorWArrayOfp_ACalcObject errorWithExpression = parseString(str);
    Error error = errorWithExpression.first;
    auto expression = errorWithExpression.second;

    if (error != Error::ERR_OK)
        return {error, ACalcObject::NONE};

    ErrorWArrayOfp_ACalcObject errorWithRPN = transformToRPN(expression);
    error = errorWithRPN.first;
    auto RPN = errorWithRPN.second;

    if (error != Error::ERR_OK)
        return {error, ACalcObject::NONE};

    return calculateRPN(RPN);
}


bool isClosedBracket(p_ACalcObject& obj)
{
    return (obj->getToken() == ")");
}


bool isOpenBracket(p_ACalcObject& obj)
{
    return (obj->getToken() == "(");
}

/*!
* Parse expression string to vector of calculation objects
* @param str expression
* @return error and vector of calculation objects
*/
ErrorWArrayOfp_ACalcObject Calculator::parseString(const std::string& str) {

    std::vector<p_ACalcObject> expression;
    for (int i = 0; i < str.size(); i++)
    {
        // is current symbol is space, skip it
        if (isspace(str[i]))
            continue;

        // if current symbol is digit, process number beginning with this digit
        // and move i on length of this digit
        if (isdigit(str[i]))
        {
            size_t numLenInChars = 1;
            std::string substr = str.substr(i);
            double num = std::stod(str.substr(i), &numLenInChars);
            i += numLenInChars - 1;

            expression.push_back(Number(num).clone());

            continue;
        }

        // if current symbol is not a space or digit, then it must be some sort of operation
        p_ACalcObject operation;
        operation = operations.stringStartsWithOperation(str, i, -1);
        if (operation == nullptr)
        {
            if (expression.empty() ||
                (expression.back()->getType() != ACalcObject::NUMBER && !isClosedBracket(expression.back()))) {
                operation = operations.stringStartsWithOperation(str, i, 0);
                if (operation == nullptr)
                    operation = operations.stringStartsWithOperation(str, i, 1);
            } else
                operation = operations.stringStartsWithOperation(str, i, 2);
        }

        if (operation == nullptr)
            return {Error::ERR_EXPRESSION, {}};

        expression.push_back(operation);
        i += operation->getToken().size() - 1;
    }
    return {Error::ERR_OK, expression};
}

/*!
* Transform expression represented as vector of calc objects to RPN
* @param expression as vector of calculation objects
* @return error and RPN
*/
ErrorWArrayOfp_ACalcObject Calculator::transformToRPN(std::vector<p_ACalcObject>& expression)
{
    std::vector<p_ACalcObject> RPN;
    std::vector<p_ACalcObject> stackOperation;

    for (auto& operationCur : expression)
    {
        ACalcObject::Type typeCur = operationCur->getType();
        
        if (typeCur == ACalcObject::NUMBER)
            RPN.push_back(operationCur);
        else
        {
            if (isClosedBracket(operationCur))
            {
                while (true)
                {
                    if (stackOperation.empty())
                        return {Error::ERR_EXPRESSION, {}};

                    auto operationFromStack = stackOperation.back();
                    stackOperation.pop_back();

                    if (isOpenBracket(operationFromStack))
                        break;
                    else
                        RPN.push_back(operationFromStack);
                }
            }
            else if (isOpenBracket(operationCur))
                stackOperation.push_back(operationCur);
            else
            {
                while (!stackOperation.empty())
                {
                    auto opFromStack = stackOperation.back();
                    if (!operationCur->compareToCalcObject(*opFromStack))
                        break;
                    else
                    {
                        stackOperation.pop_back();
                        RPN.push_back(opFromStack);
                    }
                }
                stackOperation.push_back(operationCur);
            }
        }
    }
    while (!stackOperation.empty())
    {
        auto operationFromStack = stackOperation.back();

        if (isOpenBracket(operationFromStack))
            return {Error::ERR_EXPRESSION, {}};

        stackOperation.pop_back();
        RPN.push_back(operationFromStack);
    }
    return {Error::ERR_OK, RPN};
}

/*!
* Calculate RPN
* @param RPN
* @return error and result
*/
ErrorWDouble Calculator::calculateRPN(std::vector<p_ACalcObject>& RPN)
{
    std::vector<double> operands;

    for (auto& calcObject : RPN)
    {
        if (calcObject->getType() == ACalcObject::NUMBER)
            operands.push_back(calcObject->apply({}).second);
        else
        {
            std::vector<double> args(calcObject->getArgsNum());

            if (operands.size() < args.size())
                return {Error::ERR_EXPRESSION, ACalcObject::NONE};

            for (int i = 0; i < args.size(); i++)
            {
                args[args.size() - 1 - i] = operands.back();
                operands.pop_back();
            }
            ErrorWDouble errorWDouble = calcObject->apply(args);
            Error err = errorWDouble.first;
            double res = errorWDouble.second;
            if (err != Error::ERR_OK)
                return {err, ACalcObject::NONE};

            operands.push_back(res);
        }
    }
    if (operands.size() != 1)
        return {Error::ERR_EXPRESSION, ACalcObject::NONE};
    return {Error::ERR_OK, operands[0]};
}