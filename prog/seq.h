
#include <iostream>
#include <string>
#include "encoded_sequence.h"

class Sequence {
    private:
        EncodedSequence sequence;
        size_t length;
        string description;
        
    public:
        Sequence();
        Sequence(char* sequence);
        ~Sequence();
        void setSequence(char* sequence);
        char* getSequence();
        size_t len();
        void setDesc(char* desc);
        char* getDesc();
        virtual void read(char* filename);
};