//
// Created by Mekhail on 12.11.2020.
//

#pragma once

#include "../abstract_calc_object.h"

class BracketClosed: public ACalcObject
{
public:

    std::string getToken()
    { return ")";}

    Type getType()
    { return Type(-11);}

    ErrorWDouble apply(std::vector<double> args)
    { return {Error::ERR_OK, ACalcObject::NONE};}

    p_ACalcObject clone()
    {
        static p_ACalcObject bracketClosed = std::make_shared<BracketClosed>();
        return bracketClosed;
    }

};
