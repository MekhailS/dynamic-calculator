//
// Created by Mekhail on 12.11.2020.
//

#pragma once

#include "definitions.h"

/*!
 * Abstract calculation object, all operations and operands are inherited from this class
 */
class ACalcObject
{
public:

    /*!
     * Value used as result when error occurs
     */
    constexpr static const double NONE = 0.0;

    /*!
     * Types of calculation objects
     * (also defines the priority of each type)
     */
    enum Type
    {
        NUMBER,
        BINARY_LIKE_PLUS,
        BINARY_LIKE_MULTIPLY,
        BINARY_LIKE_POWER,
        UNARY_LIKE_MINUS,
        FUNC
    };

    /*!
     * Get token of operation
     * @return token as string
     */
    virtual std::string getToken() = 0;

    /*!
     * Get type of operation
     * @return type
     */
    virtual Type getType() = 0;

    /*!
     * apply function to args
     * @param args - vector of arguments passed to function
     * @return error and res, error - if number of args is not valid or args are not valid
     */
    virtual ErrorWDouble apply(std::vector<double> args) = 0;

    /*!
     * Get dynamically allocated instance
     * @return pointer to dynamically allocated instance of operation
     */
    virtual p_ACalcObject clone() = 0;

    /*!
     * Compare calculation object to another
     * @param op - calculation object to compare with
     * @return true - if (this) > op, false otherwise
     */
    bool compareToCalcObject(ACalcObject& op)
    {
        auto selfType = getType();
        auto opType = op.getType();
        if (selfType == opType)
            return (selfType != ACalcObject::BINARY_LIKE_POWER);
        else
            return (int(selfType) < int(opType));
    }

    /*!
     * Get number of arguments of calculation object
     * @return arguments number
     */
    int getArgsNum()
    {
        auto type = getType();
        return ((type == BINARY_LIKE_POWER || type == BINARY_LIKE_MULTIPLY || type == BINARY_LIKE_PLUS) ? 2 :
                (type == UNARY_LIKE_MINUS || type == FUNC) ? 1 :
                (type == NUMBER) ? 0 : -1);
    }

    /*!
     * check if operation is equal to another in context of it's token and number of arguments
     * @param operation to compare with
     * @return true if equal, false otherwise
     */
    bool equalInTermsOfTokenAndArgsNum(ACalcObject& operation)
    {
        if (getToken() == operation.getToken())
        {
            if ((getArgsNum() == -1) ||
                ((operation.getArgsNum() == 0 || operation.getArgsNum() == 1) &&
                (getArgsNum() == 0 || getArgsNum() == 1)) ||
                (operation.getArgsNum() == 2 && getArgsNum() == 2))
                return true;
        }
        return false;
    }
};

/*********************************************************************************************
    *  ALL OPERATIONS WITH <name> CREATED IN .DLL MUST HAVE FUNCTION WITH FOLLOWING STRUCTURE:
    *
    *  LOAD_FROM_DLL_SIGNATURE GET_OPERATION_INSTANCE()
    *  {
    *       return <name>().clone();
    *  }
 *********************************************************************************************/
