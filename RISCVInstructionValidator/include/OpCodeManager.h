#include <unordered_map>
#include <string>
using namespace std;

#ifndef OPCODEMANAGER_H
#define OPCODEMANAGER_H


class OpCodeManager {
    public:
        OpCodeManager();
        virtual ~OpCodeManager();
        static void assignOperandNumbersToOpCodes(unordered_map <string, int> & opCodeToOperandNumber);
    protected:
    private:
};

#endif // OPCODEMANAGER_H
