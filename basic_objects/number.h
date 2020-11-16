//
// Created by Mekhail on 12.11.2020.
//

#ifndef DYNAMIC_CALCULATOR_NUMBER_H
#define DYNAMIC_CALCULATOR_NUMBER_H

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
    { return {ERR_OK, n};}

    p_ACalcObject clone()
    { return std::make_shared<Number>(n);}

private:
    double n;
};

#endif //DYNAMIC_CALCULATOR_NUMBER_H
