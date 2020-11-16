#include <iostream>

#include "operation_collection.h"
#include "abstract_calc_object.h"
#include "basic_operations/plus.h"

#include "calculator.h"

int main() {

    OperationCollection operationCollection;
    operationCollection.initBasicOperations();

    std::cout << "Hello, World!" << std::endl;

    std::string path = R"(C:\Users\Mekhail\CLionProjects\dynamic_calc\dll_operations)";

    Error errWDll = operationCollection.addDllOperationsFromFolder(path);

    std::string str = "5+6+-(7.2)+4*2+7/1+sin(1)*2-sin(pi)-1";

    Calculator calculator(operationCollection);

    ErrorWDouble res = calculator.calculate(str);

    return 0;
}
