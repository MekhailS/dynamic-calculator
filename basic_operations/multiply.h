//
// Created by Mekhail on 12.11.2020.
//

#pragma once

#include "../abstract_calc_object.h"

class Multiply: public ACalcObject
{
public:

    std::string getToken()
    { return "*";}

    Type getType()
    { return ACalcObject::BINARY_LIKE_MULTIPLY;}

    ErrorWDouble apply(std::vector<double> args)
    {
        if (args.size() != getArgsNum())
            return {Error::ERR_ARGS, ACalcObject::NONE};
        return {Error::ERR_OK, args[0] * args[1]};
    }

    p_ACalcObject clone()
    {
        static p_ACalcObject multiply = std::make_shared<Multiply>();
        return multiply;
    }

};
