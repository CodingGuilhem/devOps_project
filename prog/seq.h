
#include <iostream>
#include <string>
#include "encoded_sequence.h"

class Sequence {
    private:
        EncodedSequence sequence;
        std::string description;
        
    public:
        Sequence();
        Sequence(EncodedSequence sequence);
        Sequence(EncodedSequence sequence, std::string desc);
        ~Sequence();
        void setSequence(char* sequence);
        char* getSequence();
        size_t len();
        void setDesc(char* desc);
        char* getDesc();
        virtual void read(char* filename);
};