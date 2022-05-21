#include <vector>
#include <string>

using namespace std;

#ifndef TOKENIZEDINSTRUCTION_H
#define TOKENIZEDINSTRUCTION_H


class TokenizedInstruction {
    public:
        TokenizedInstruction(string opCode, vector <string> operandsWithSeperators);
        virtual ~TokenizedInstruction();

        string getOpCode() {
            return opCode;
        }

        vector <string> getOperandsWithSeperators() {
            return operandsWithSeperators;
        }
    protected:
    private:
        string opCode;
        vector <string> operandsWithSeperators;
};

#endif // TOKENIZEDINSTRUCTION_H
