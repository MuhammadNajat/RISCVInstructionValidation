#include <string>

using namespace std;

#ifndef INSTRUCTIONPREPROCESSOR_H
#define INSTRUCTIONPREPROCESSOR_H


class InstructionPreprocessor {
    public:
        InstructionPreprocessor();
        virtual ~InstructionPreprocessor();

        string getCommentRemoved(const string & instruction);
        string preprocessInstruction(const string & instruction);
    protected:
    private:
};

#endif // INSTRUCTIONPREPROCESSOR_H
