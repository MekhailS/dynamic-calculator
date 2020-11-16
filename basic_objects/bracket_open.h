//
// Created by Mekhail on 12.11.2020.
//

#ifndef DYNAMIC_CALCULATOR_BRACKET_OPEN_H
#define DYNAMIC_CALCULATOR_BRACKET_OPEN_H

#include "../abstract_calc_object.h"

class BracketOpen: public ACalcObject
{
public:

    std::string getToken()
    { return "(";}

    Type getType()
    { return Type(-10);}

    ErrorWDouble apply(std::vector<double> args)
    { return {ERR_OK, ACalcObject::NONE};}

    p_ACalcObject clone()
    {
        static p_ACalcObject bracketOpen = std::make_shared<BracketOpen>();
        return bracketOpen;
    }

};

#endif //DYNAMIC_CALCULATOR_BRACKET_OPEN_H
