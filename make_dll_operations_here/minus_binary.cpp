//
// Created by Mekhail on 16.11.2020.
//

#include "../abstract_calc_object.h"

class MinusBinary: public ACalcObject
{
public:

    std::string getToken()
    {return "-";}

    ACalcObject::Type getType()
    { return ACalcObject::BINARY_LIKE_PLUS;}

    ErrorWDouble apply(std::vector<double> args)
    {
        if (args.size() != getArgsNum())
            return {ERR_ARGS, ACalcObject::NONE};
        return {ERR_OK, args[0] - args[1]};
    }

    p_ACalcObject clone()
    {
        static p_ACalcObject minus = std::make_shared<MinusBinary>();
        return minus;
    }

};

LOAD_FROM_DLL_SIGNATURE GET_OPERATION_INSTANCE()
{
    return MinusBinary().clone();
}
