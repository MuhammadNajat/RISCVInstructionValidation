#include <vector>
#include <string>
#include "Tokenizer.h"

using namespace std;

Tokenizer::Tokenizer() {
    //ctor
}

Tokenizer::~Tokenizer() {
    //dtor
}

vector <string> Tokenizer::tokenize(const string & instruction) {
    vector <string> tokens;
    int instructionLength = instruction.length();
    for(int i=0; i<instructionLength; i++) {
        string token = "";
        if(isalnum(instruction[i])) {
            while(i < instructionLength && isalnum(instruction[i])) {
                token += instruction[i];
                i++;
            }
            i--;
        }
        else if(instruction[i] == ',') {
            token = ",";
        }
        if(token.length() > 0) {
            tokens.push_back( token );
        }
    }

    return tokens;
}

TokenizedInstruction Tokenizer::getInstructionTokenized(const string & instruction) {
    vector < string > tokens = tokenize(instruction);
    string opCode;
    vector <string> operandsWithSeperators;

    for(int i=0; i<(int) tokens.size(); i++) {
        if(i == 0) {
            opCode = tokens[i];
        }
        else {
            operandsWithSeperators.push_back( tokens[i] );
        }
    }

    TokenizedInstruction tokenizedInstruction(opCode, operandsWithSeperators);

    return tokenizedInstruction;
}
