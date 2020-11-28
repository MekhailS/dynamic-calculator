//
// Created by Mekhail on 12.11.2020.
//

#pragma once

#include "../abstract_calc_object.h"

class Number: public ACalcObject
{
public:

    Number(double n_) : n(n_) {}

    std::string getToken()
    { return std::to_string(n);}

    Type getType()
    { return ACalcObject::NUMBER;}

    ErrorWDouble apply(std::vector<double> args)
    { return {Error::ERR_OK, n};}

    p_ACalcObject clone()
    { return std::make_shared<Number>(n);}

private:
    double n;
};
