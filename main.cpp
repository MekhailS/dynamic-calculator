#include <iostream>

#include "operation_collection.h"
#include "abstract_calc_object.h"

#include "calculator.h"

std::string getErrorMsg(Error err)
{
    switch(err)
    {
        case Error::ERR_OK: return("no error");

        case Error::ERR_ARGS: return("not valid function arguments");

        case Error::ERR_DLL_NOT_VALID: return("can not open .dll file");

        case Error::ERR_DLL_FORMAT: return("can not load getInstance function from .dll file");

        case Error::ERR_TOKEN: return("not valid operation token");

        case Error::ERR_EXPRESSION: return("not valid expression");

        default: return("");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2)
        return 0;

    const std::string PATH_DLL = R"(..\dll_operations)";
    OperationCollection operationCollection;
    operationCollection.initBasicOperations();

    Error errWDll = operationCollection.addDllOperationsFromFolder(PATH_DLL);
    if (errWDll != Error::ERR_OK)
    {
        std::cout << getErrorMsg(errWDll) << std::endl;
        return 0;
    }

    std::string expression(argv[1]);
    std::cout << expression + " = ";

    Calculator calculator(operationCollection);
    ErrorWDouble res = calculator.calculate(expression);

    if (res.first != Error::ERR_OK)
        std::cout << getErrorMsg(res.first) << std::endl;
    else
        std::cout << std::to_string(res.second) << std::endl;

    return 0;
}
