#ifndef __SEQ_H__
#define __SEQ_H__
#include <iostream>
#include <string>
#include <fstream>
#include "encoded_sequence.h"

class Sequence {
    protected:
        EncodedSequence *sequence;
        std::string description;
        
    public:
        Sequence();
        Sequence(string seq);
        Sequence(string seq, std::string desc);
        ~Sequence();
        void setSequence(string seq);
        string getSequence();
        inline size_t len();
        string getDesc();
        virtual void read_file(string filename);
};

#endif