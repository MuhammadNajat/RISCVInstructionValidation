#include <vector>
#include <string>
#include "TokenizedInstruction.h"

using namespace std;

#ifndef TOKENIZER_H
#define TOKENIZER_H

class Tokenizer {
    public:
        Tokenizer();
        virtual ~Tokenizer();
        vector <string> tokenize(const string & instruction);
        TokenizedInstruction getInstructionTokenized(const string & instruction);
    protected:
    private:
};

#endif // TOKENIZER_H
