#ifndef __SEQ_H__
#define __SEQ_H__
#include <iostream>
#include <string>
#include <fstream>
#include "encoded_sequence.h"

class Sequence {
    private:
<<<<<<< HEAD
        EncodedSequence sequence;
        std::string description;
=======
        EncodedSequence *sequence;
        size_t length;
>>>>>>> 3be23c3037831db0124ea475275a79967aeb6e59
        
    public:
        Sequence();
        Sequence(EncodedSequence sequence);
        Sequence(EncodedSequence sequence, std::string desc);
        ~Sequence();
        void setSequence(char* sequence);
        char* getSequence();
        size_t len();
        char* getDesc();
        virtual void read_file(char* filename);
};