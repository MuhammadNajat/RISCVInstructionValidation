#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "OpCodeManager.h"
#include "InstructionPreprocessor.h"
#include "TokenizedInstructionValidator.h"
#include "Tokenizer.h"

using namespace std;

void showTokenizedInstruction(TokenizedInstruction tokenizedInstruction) {
    cout << "OPCODE: " << tokenizedInstruction.getOpCode() << endl;

    cout << "OPERANDS:" << endl;
    vector <string> operandsWithSeperators = tokenizedInstruction.getOperandsWithSeperators();
    for(int i=0, j=1; i<(int) operandsWithSeperators.size(); i++) {
        if(operandsWithSeperators[i] != ",") {
            cout << j++ << "." << operandsWithSeperators[i] << endl;
        }
    }
    cout << endl;
}

int main() {
    unordered_map <string, int> opCodeToOperandNumber;

    OpCodeManager::assignOperandNumbersToOpCodes(opCodeToOperandNumber);

    InstructionPreprocessor instructionPreprocessor;

    Tokenizer tokenizer;

    TokenizedInstructionValidator tokenizedInstructionValidator;

    vector < string > validInstructions;
    vector < TokenizedInstruction > validTokenizedInstructions;

    char instruction[501];
    while(gets(instruction)) {
        string processedInstruction = instructionPreprocessor.preprocessInstruction(instruction);

        TokenizedInstruction tokenizedInstruction = tokenizer.getInstructionTokenized(processedInstruction);

        bool isValid = tokenizedInstructionValidator.isTokenizedInstructionValid(opCodeToOperandNumber, tokenizedInstruction);
        if(isValid) {
            validTokenizedInstructions.push_back( tokenizedInstruction );
            validInstructions.push_back( processedInstruction );
            cout << "VALID" << endl;
        }
        else {
            cout << "INVALID" << endl;
        }

    }

    cout << "\n*** *** *** VALID INSTRUCTIONS *** *** ***\n" << endl;
    for(int i=0; i<(int) validTokenizedInstructions.size(); i++) {
        cout << "INSTRUCTION:" << endl << validInstructions[i] << endl;
        showTokenizedInstruction( validTokenizedInstructions[i] );
    }

    return 0;
}
