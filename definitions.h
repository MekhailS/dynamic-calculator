//
// Created by Mekhail on 12.11.2020.
//

#ifndef DYNAMIC_CALCULATOR_DEFINITIONS_H
#define DYNAMIC_CALCULATOR_DEFINITIONS_H

#include <string>
#include <map>
#include <vector>
#include <memory>
#include <iostream>
#include "assert.h"

#include "error.h"

#define GET_OPERATION_INSTANCE getInstance
#define GET_OPERATION_INSTANCE_str "getInstance"
#define LOAD_FROM_DLL_SIGNATURE extern "C" __declspec(dllexport) p_ACalcObject __cdecl

class ACalcObject;

typedef std::pair<Error, double> ErrorWDouble;
typedef std::shared_ptr<ACalcObject> p_ACalcObject;

#endif //DYNAMIC_CALCULATOR_DEFINITIONS_H
