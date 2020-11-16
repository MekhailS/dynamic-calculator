//
// Created by Mekhail on 13.11.2020.
//

#include <filesystem>
#include <windows.h>

#include "operation_collection.h"

#include "basic_objects/bracket_closed.h"
#include "basic_objects/bracket_open.h"

#include "basic_operations/multiply.h"
#include "basic_operations/plus.h"
#include "basic_operations/minus_unary.h"

namespace fs = std::filesystem;
typedef p_ACalcObject (__cdecl *factoryGetInstance)();

/*!
* init operation collection with default operations:
* brackets, plus, multiply, unary minus
*/
void OperationCollection::initBasicOperations()
{
    operations = { BracketClosed().clone(), BracketOpen().clone(),
                   Multiply().clone(), Plus().clone(), MinusUnary().clone() };
}

/*!
 * Add operations from .dll files stored in folder
 * @param path - folder with .dll files
 * @return error code
 */
Error OperationCollection::addDllOperationsFromFolder(const std::string& path)
{
    for (auto& entry: fs::directory_iterator(path))
    {
        std::string filename = entry.path().string();
        std::string filetype = filename.substr(filename.find_last_of('.'), filename.length()-1);

        if (filetype != ".dll")
            continue;

        HINSTANCE hGetProcID_DLL = LoadLibrary(filename.c_str());
        if (hGetProcID_DLL == nullptr)
            return ERR_DLL_NOT_VALID;

        auto p_getInstance = (factoryGetInstance)GetProcAddress(hGetProcID_DLL, GET_OPERATION_INSTANCE_str);
        if (p_getInstance == nullptr)
            return ERR_DLL_FORMAT;

        p_ACalcObject operation = p_getInstance();

        if (operationAlreadyExists(operation))
            return ERR_TOKEN;

        operations.push_back(operation);
    }
    return ERR_OK;
}

/*!
* Check if there is an operation with certain number of args and
* token same as first chars of string by offset
* @param str - string with operation token
* @param offset - first char token index (in string)
* @param numArgs - number of args which operation must have
* @return pointer to operation if operation was found, nullptr otherwise
*/
p_ACalcObject OperationCollection::stringStartsWithOperation(const std::string& str, int offset, int numArgs)
{
    if (offset < 0 || offset >= str.size())
        return nullptr;

    for (auto& operation: operations)
    {
        if (str.compare(offset, operation->getToken().size(), operation->getToken()) == 0 &&
                numArgs == operation->getArgsNum())
            return operation;
    }
    return nullptr;
}

/*!
* Check if collection already has such operation
* (same token and num of args)
* @param operation - operation, whose properties need to be found
* @return true if such operation exists, false otherwise
*/
bool OperationCollection::operationAlreadyExists(p_ACalcObject& operation)
{
    for (auto& operationInCollection: operations)
    {
        if (operationInCollection->getToken() == operation->getToken())
        {
            if (operationInCollection->getArgsNum() == -1)
                return true;
            if ((operation->getArgsNum() == 0 || operation->getArgsNum() == 1) &&
                (operationInCollection->getArgsNum() == 0 || operationInCollection->getArgsNum() == 1))
                return true;
            if (operation->getArgsNum() == 2 && operationInCollection->getArgsNum() == 2)
                return true;
        }
    }
    return false;
}
