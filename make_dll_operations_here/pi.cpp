//
// Created by Mekhail on 16.11.2020.
//

#include "../abstract_calc_object.h"

class Pi: public ACalcObject
{
public:

    std::string getToken()
    {return "pi";}

    ACalcObject::Type getType()
    { return ACalcObject::NUMBER;}

    ErrorWDouble apply(std::vector<double> args)
    {
        return {Error::ERR_OK, 3.14159265358979323846};
    }

    p_ACalcObject clone()
    {
        static p_ACalcObject pi = std::make_shared<Pi>();
        return pi;
    }

};

LOAD_FROM_DLL_SIGNATURE GET_OPERATION_INSTANCE()
{
    return Pi().clone();
}
