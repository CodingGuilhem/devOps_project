#ifndef __FASTQ_SEQ_H__
#define __FASTQ_SEQ_H__

#include <iostream>
#include <fstream>
#include <string>
#include "seq.h"

class FastqSequence : public Sequence {
    private :
        std::string comments; 
        std::string quality;  
  
    public:
        FastqSequence();
        FastqSequence(std::string sequence);
        FastqSequence(std::string sequence, std::string header, std::string quality);
        void setQuality(std::string quality);
        std::string getQuality();
        void setComments(std::string comm);
        std::string getComments();
};
#endif