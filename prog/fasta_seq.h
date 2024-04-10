#ifndef __FASTA_SEQ_H__
#define __FASTA_SEQ_H__
#include <iostream>
#include <fstream>
#include <string>
#include "seq.h"


class FastaSequence : public Sequence {
    private :
        std::string comments;


    public:
        FastaSequence();
        FastaSequence(std::string sequence);
        FastaSequence(std::string sequence, std::string description);
        FastaSequence(std::string sequence, std::string description, std::string comments);
        void setComments(std::string comments);
        std::string getComments();
};

#endif