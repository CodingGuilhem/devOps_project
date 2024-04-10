#include <iostream>
#include <string>
#include <fstream>
#include "fasta_seq.h"

using namespace std;

FastaSequence::FastaSequence(){
    this->setDescription("");
    this->setSequence(NULL);
    comments = "";
};
FastaSequence::FastaSequence(string seq){
    this->setDescription("");
    this->setSequence(seq);
    comments = "";
};
FastaSequence::FastaSequence(string seq, string desc){
    this->setDescription(desc); ;
    this->setSequence(seq);
    comments= "";
};

void FastaSequence::setComments(string comm){
    comments = comm;
};
string FastaSequence::getComments(){
    return comments;
};

