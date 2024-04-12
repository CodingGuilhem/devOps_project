#ifndef __SEQ_H__
#define __SEQ_H__
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "encoded_sequence.h"


class Sequence {
    protected:
    
        EncodedSequence *sequence;
        std::string description;
        
    public:
        Sequence();
        Sequence(std::string seq);
        Sequence(std::string seq, std::string desc);
        ~Sequence();
        void setSequence(std::string seq);
        std::string getSequence();
        inline size_t len();
        std::string getDescription();
        void setDescription(std::string desc);
};

#endif