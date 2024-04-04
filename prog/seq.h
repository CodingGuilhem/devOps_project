#ifndef __SEQ_H__
#define __SEQ_H__
#include <iostream>
#include <string>
#include <fstream>
#include "encoded_sequence.h"

class Sequence {
    private:
        EncodedSequence *sequence;
        size_t length;
        
    public:
        Sequence();
        Sequence(char* sequence);
        ~Sequence();
        void setSequence(char* sequence);
        char* getSequence();
        size_t len();
        char* getDesc();
        virtual void read_file(char* filename);
};