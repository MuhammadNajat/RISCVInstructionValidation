#include "TokenizedInstructionValidator.h"

TokenizedInstructionValidator::TokenizedInstructionValidator() {
    //ctor
}

TokenizedInstructionValidator::~TokenizedInstructionValidator() {
    //dtor
}

int TokenizedInstructionValidator::getOperandCount(vector <string> operandsWithSeperators) {
    int operandCount = 0;
    for(int i=0; i<(int) operandsWithSeperators.size(); i++) {
        if(operandsWithSeperators[i] != ",") {
            operandCount++;
        }
    }

    return operandCount;
}

bool TokenizedInstructionValidator::isOperandValid(string operand) {
    bool isValid = true;
    int operandLength = operand.length();
    int digitCount = 0;
    int i;

    for(i=0; i<operandLength; i++) {
        if(isdigit(operand[i])) {
            digitCount++;
        }
        else if(operand[i] != '_' && !isalpha(operand[i])) {
            break;
        }
    }

    if(i < operandLength || (isdigit(operand[0]) && digitCount < operandLength)) {
        isValid = false;
    }

    return isValid;
}

bool TokenizedInstructionValidator::isTokenizedInstructionValid(unordered_map <string, int> opCodeToOperandNumber, TokenizedInstruction tokenizedInstruction) {
    bool isValid = true;
    vector <string> operandsWithSeperators = tokenizedInstruction.getOperandsWithSeperators();
    int operandCount = getOperandCount(operandsWithSeperators);

    string opCode = tokenizedInstruction.getOpCode();
    if(opCodeToOperandNumber.find(opCode) != opCodeToOperandNumber.end()) {
        isValid &= (opCodeToOperandNumber[opCode] == operandCount);
    }
    else {
        isValid = false;
    }

    int operandsAndSeperatorsCount = (int) operandsWithSeperators.size();
    isValid &= (operandsAndSeperatorsCount == 0  || isOperandValid(operandsWithSeperators[operandsAndSeperatorsCount - 1]));

    for(int i=0; i<operandsAndSeperatorsCount-1; i+=2) {
        if(!(isOperandValid( operandsWithSeperators[i] ) && operandsWithSeperators[i+1] == ",")) {
            isValid = false;
            break;
        }
    }

    return isValid;
}
