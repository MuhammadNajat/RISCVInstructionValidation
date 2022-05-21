#include <string>
#include "InstructionPreprocessor.h"

using namespace std;

InstructionPreprocessor::InstructionPreprocessor() {
    //ctor
}

InstructionPreprocessor::~InstructionPreprocessor() {
    //dtor
}

/**
Returns the first index of '#', -1 if no comment exists.
**/
string InstructionPreprocessor::getCommentRemoved(const string & instruction) {
    int instructionLength = instruction.length();
    string processed = "";
    for(int i=0; i<instructionLength && instruction[i] != '#'; i++) {
        processed += instruction[i];
    }

    return processed;
}

string InstructionPreprocessor::preprocessInstruction(const string & instruction) {
    string processed = getCommentRemoved(instruction);
    return processed;
}
