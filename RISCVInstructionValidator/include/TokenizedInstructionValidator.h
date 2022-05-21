#include <vector>
#include <string>
#include <unordered_map>
#include "TokenizedInstruction.h"

using namespace std;

#ifndef TOKENIZEDINSTRUCTIONVALIDATOR_H
#define TOKENIZEDINSTRUCTIONVALIDATOR_H


class TokenizedInstructionValidator {
    public:
        TokenizedInstructionValidator();
        virtual ~TokenizedInstructionValidator();

        int getOperandCount(const vector <string> & operandsWithSeperators);
        bool isTokenizedInstructionValid(unordered_map <string, int> opCodeToOperandNumber, TokenizedInstruction tokenizedInstruction);
        bool isOperandValid(const string & operand);

    protected:
    private:
};

#endif // TOKENIZEDINSTRUCTIONVALIDATOR_H
