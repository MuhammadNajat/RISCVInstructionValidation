#include <iostream>
#include "OpCodeManager.h"
using namespace std;

OpCodeManager::OpCodeManager() {
    //ctor
}

OpCodeManager::~OpCodeManager() {
    //dtor
}

void OpCodeManager::assignOperandNumbersToOpCodes(unordered_map <string, int> & opCodeToOperandNumber) {
    opCodeToOperandNumber["add"] = 3;
    opCodeToOperandNumber["addi"] = 3;
    opCodeToOperandNumber["sub"] = 3;
    opCodeToOperandNumber["subi"] = 3;

    opCodeToOperandNumber["la"] = 2;
    opCodeToOperandNumber["li"] = 2;

    opCodeToOperandNumber["ecall"] = 0;
}
