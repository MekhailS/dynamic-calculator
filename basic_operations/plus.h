//
// Created by Mekhail on 12.11.2020.
//

#pragma once

#include "../abstract_calc_object.h"

class Plus: public ACalcObject
{
public:

    std::string getToken()
    { return "+";}

    Type getType()
    { return ACalcObject::BINARY_LIKE_PLUS;}

    ErrorWDouble apply(std::vector<double> args)
    {
        if (args.size() != getArgsNum())
            return {Error::ERR_ARGS, ACalcObject::NONE};
        return {Error::ERR_OK, args[0] + args[1]};
    }

    p_ACalcObject clone()
    {
        static p_ACalcObject plus = std::make_shared<Plus>();
        return plus;
    }

};
