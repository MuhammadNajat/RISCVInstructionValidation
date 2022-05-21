#include <vector>
#include <string>
#include "TokenizedInstruction.h"

using namespace std;

TokenizedInstruction::TokenizedInstruction(const string & opCode, const vector <string> & operandsWithSeperators) {
    //ctor
    this->opCode = opCode;
    this->operandsWithSeperators = operandsWithSeperators;
}

TokenizedInstruction::~TokenizedInstruction() {
    //dtor
}
