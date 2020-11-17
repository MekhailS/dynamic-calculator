//
// Created by Mekhail on 17.11.2020.
//

#include "../abstract_calc_object.h"
#include "math.h"

class Power: public ACalcObject
{
public:

    std::string getToken()
    {return "pow";}

    ACalcObject::Type getType()
    { return ACalcObject::BINARY_LIKE_POWER;}

    ErrorWDouble apply(std::vector<double> args)
    {
        if (args.size() != getArgsNum() || args[0] < 0)
            return {ERR_ARGS, ACalcObject::NONE};
        return {ERR_OK, pow(args[0], args[1])};
    }

    p_ACalcObject clone()
    {
        static p_ACalcObject power = std::make_shared<Power>();
        return power;
    }

};

LOAD_FROM_DLL_SIGNATURE GET_OPERATION_INSTANCE()
{
    return Power().clone();
}
