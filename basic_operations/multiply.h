//
// Created by Mekhail on 12.11.2020.
//

#ifndef DYNAMIC_CALCULATOR_MULTIPLY_H
#define DYNAMIC_CALCULATOR_MULTIPLY_H

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
            return {ERR_ARGS, ACalcObject::NONE};
        return {ERR_OK, args[0] * args[1]};
    }

    p_ACalcObject clone()
    {
        static p_ACalcObject multiply = std::make_shared<Multiply>();
        return multiply;
    }

};

#endif //DYNAMIC_CALCULATOR_MULTIPLY_H
