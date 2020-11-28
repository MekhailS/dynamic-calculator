//
// Created by Mekhail on 15.11.2020.
//

#include "../abstract_calc_object.h"
#include "math.h"

class Sin: public ACalcObject
{
public:

    std::string getToken()
    {return "sin";}

    ACalcObject::Type getType()
    { return ACalcObject::FUNC;}

    ErrorWDouble apply(std::vector<double> args)
    {
        if (args.size() != getArgsNum())
            return {Error::ERR_ARGS, ACalcObject::NONE};
        return {Error::ERR_OK, sin(args[0])};
    }

    p_ACalcObject clone()
    {
        static p_ACalcObject sin = std::make_shared<Sin>();
        return sin;
    }

};

LOAD_FROM_DLL_SIGNATURE GET_OPERATION_INSTANCE()
{
    return Sin().clone();
}