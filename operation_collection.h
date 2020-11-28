//
// Created by Mekhail on 13.11.2020.
//

#pragma once

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
    * Add to collection operations from .dll files stored in folder
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
     * Collection of operations
     */
    std::vector<p_ACalcObject> operations;
};
