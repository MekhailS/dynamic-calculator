//
// Created by Mekhail on 12.11.2020.
//

#pragma once

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

using ErrorWDouble = std::pair<Error, double>;
using p_ACalcObject = std::shared_ptr<ACalcObject>;
