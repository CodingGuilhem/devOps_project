#ifndef __FASTA_SEQ_H__
#define __FASTA_SEQ_H__
#include <iostream>
#include <fstream>
#include <string>
#include "seq.h"


class FastaSequence : public Sequence {
    private :
        std::string header;

    public:
        FastaSequence();
        FastaSequence(std::string sequence);
        FastaSequence(std::string sequence, std::string header);
        void setHeader(std::string header);
        std::string getHeader();
        virtual void read_file(string filename);
};

#endif