#include <iostream>

#include "operation_collection.h"
#include "abstract_calc_object.h"

#include "calculator.h"

std::string getErrorMsg(Error err)
{
    std::string res;
    switch(err)
    {
        case ERR_OK:
            res = "no error";
            break;

        case ERR_ARGS:
            res = "not valid function arguments";
            break;

        case ERR_DLL_NOT_VALID:
            res = "can not open .dll file";
            break;

        case ERR_DLL_FORMAT:
            res = "can not load getInstance function from .dll file";
            break;

        case ERR_TOKEN:
            res = "not valid operation token";
            break;

        case ERR_EXPRESSION:
            res = "not valid expression";
            break;
    }
    return res;
}

int main(int argc, char* argv[]) {
    if (argc != 2)
        return 0;

    const std::string PATH_DLL = R"(..\dll_operations)";
    OperationCollection operationCollection;
    operationCollection.initBasicOperations();

    Error errWDll = operationCollection.addDllOperationsFromFolder(PATH_DLL);

    if (errWDll)
    {
        std::cout << getErrorMsg(errWDll) << std::endl;
        return 0;
    }

    std::string expression(argv[1]);
    std::cout << expression + " = ";

    Calculator calculator(operationCollection);
    ErrorWDouble res = calculator.calculate(expression);

    if (res.first)
        std::cout << getErrorMsg(res.first) << std::endl;
    else
        std::cout << std::to_string(res.second) << std::endl;

    return 0;
}
