#include <string>
#include <iostream>
#include "seq.h"

using namespace std;
class Sequence {
    private:
        char* sequence;
        int length;

    public:
        Sequence(){
            sequence = NULL;
            length = 0;
        };

        Sequence(char* sequence);
        ~Sequence(){
            if (sequence != NULL){
                free(sequence);
            }
        };

        void setSequence(char* sequence){
            cout << "TODO" << endl;
        };
        char* getSequence();
        int getLength();
        void readFasta(char* filename);
        void readFastq(char* filename);
};