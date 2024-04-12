#include <iostream>
#include <string>
#include <fstream>
#include "fasta_seq.h"

using namespace std;

FastaSequence::FastaSequence(){
    this->setDescription("");
    sequence = NULL;
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
FastaSequence::FastaSequence(std::string sequence, std::string description, std::string comments){
    this->setDescription(description);
    this->setSequence(sequence);
    this->setComments(comments);
};

void FastaSequence::setComments(string comm){
    comments = comm;
};
string FastaSequence::getComments(){
    return comments;
};

