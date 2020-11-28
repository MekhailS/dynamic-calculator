//
// Created by Mekhail on 12.11.2020.
//

#include "../abstract_calc_object.h"

class Divide: public ACalcObject
{
public:

    std::string getToken()
    {return "/";}

    ACalcObject::Type getType()
    { return ACalcObject::BINARY_LIKE_MULTIPLY;}

    ErrorWDouble apply(std::vector<double> args)
    {
        if (args.size() != getArgsNum() || args[1] == 0)
            return {Error::ERR_ARGS, ACalcObject::NONE};
        return {Error::ERR_OK, args[0] / args[1]};
    }

    p_ACalcObject clone()
    {
        static p_ACalcObject divide = std::make_shared<Divide>();
        return divide;
    }

};

LOAD_FROM_DLL_SIGNATURE GET_OPERATION_INSTANCE()
{
    return Divide().clone();
}


