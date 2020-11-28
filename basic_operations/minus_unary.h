//
// Created by Mekhail on 12.11.2020.
//

#pragma once

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
            return {Error::ERR_ARGS, ACalcObject::NONE};
        return {Error::ERR_OK, -args[0]};
    }

    p_ACalcObject clone()
    {
        static p_ACalcObject minusUnary = std::make_shared<MinusUnary>();
        return minusUnary;
    }
};
