/**
 * @file backend.h
 * @author Dylan E. Holland (salinson1138@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include <VM/Include/opcode.h>
#include <VM/Include/instruction.h>
#include <Tools/Assembly/Include/parser.h>

#include <vector>

using namespace liz::vm;

namespace liz::tools::assembly {
    struct extractOperandResult {
        struct intermediateOperand *operand;
        struct intermediateDataValue *data;
    };

    struct intermediate *createIntermediate(std::vector<struct assemblyLine*> instructionList);
    enum liz::vm::opcode opcodeFromString(std::string potentialInstruction);
    struct intermediateDataValue *getCharacterFromOperandString(std::string operandStr, int lineNUmber);
    struct extractOperandResult *extractOperand(std::string operand, int lineNumber);
    void writeIntermediate(std::string fileName, struct intermediate *program);
}