//
// Created by Mekhail on 12.11.2020.
//

#pragma once

#include "../abstract_calc_object.h"

class BracketOpen: public ACalcObject
{
public:

    std::string getToken()
    { return "(";}

    Type getType()
    { return Type(-10);}

    ErrorWDouble apply(std::vector<double> args)
    { return {Error::ERR_OK, ACalcObject::NONE};}

    p_ACalcObject clone()
    {
        static p_ACalcObject bracketOpen = std::make_shared<BracketOpen>();
        return bracketOpen;
    }

};
