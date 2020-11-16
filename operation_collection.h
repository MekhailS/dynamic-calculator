//
// Created by Mekhail on 13.11.2020.
//

#ifndef DYNAMIC_CALCULATOR_OPERATION_COLLECTION_H
#define DYNAMIC_CALCULATOR_OPERATION_COLLECTION_H

#include "definitions.h"

/*!
 * Collection of operations: basic operations and ones (optionally) loaded from .dll
 */
class OperationCollection
{
public:

    /*!
     * init operation collection with default operations:
     * brackets, plus, multiply, unary minus
     */
    void initBasicOperations();

    /*!
    * Add operations from .dll files stored in folder to collection
    * @param path - folder with .dll files
    * @return error code
    */
    Error addDllOperationsFromFolder(const std::string& path);

    /*!
     * Check if collection has an operation with certain number of args and
     * token same as first chars of string by offset
     * @param str - string with operation token
     * @param offset - first char token index (in string)
     * @param numArgs - number of args which operation must have
     * @return pointer to operation if operation was found, nullptr otherwise
     */
    p_ACalcObject stringStartsWithOperation(const std::string& str, int offset, int numArgs);

private:

    /*!
     * Check if collection already has such operation
     * (same token and num of args)
     * @param operation - operation, whose properties need to be found
     * @return true if such operation exists, false otherwise
     */
    bool operationAlreadyExists(p_ACalcObject& operation);

    /*!
     * Collection of operations
     */
    std::vector<p_ACalcObject> operations;
};


#endif //DYNAMIC_CALCULATOR_OPERATION_COLLECTION_H
