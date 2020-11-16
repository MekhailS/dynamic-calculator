//
// Created by Mekhail on 12.11.2020.
//

#ifndef DYNAMIC_CALCULATOR_MINUS_UNARY_H
#define DYNAMIC_CALCULATOR_MINUS_UNARY_H

#include "../abstract_calc_object.h"

class MinusUnary: public ACalcObject
{
public:

    std::string getToken()
    { return "-";}

    Type getType()
    { return ACalcObject::UNARY_LIKE_MINUS;}

    ErrorWDouble apply(std::vector<double> args)
    {
        if (args.size() != getArgsNum())
            return {ERR_ARGS, ACalcObject::NONE};
        return {ERR_OK, -args[0]};
    }

    p_ACalcObject clone()
    {
        static p_ACalcObject minusUnary = std::make_shared<MinusUnary>();
        return minusUnary;
    }
};

#endif //DYNAMIC_CALCULATOR_MINUS_UNARY_H
