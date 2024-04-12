#include <iostream>
#include <fstream>
#include <string>
#include "fastq_seq.h"

using namespace std;

FastqSequence::FastqSequence(){
    this->setDescription("");
    sequence = NULL;
    comments = "";
    quality = "";
};
FastqSequence::FastqSequence(std::string sequence){
    this->setDescription("");
    this->setSequence(sequence);
    comments = "";
    quality = "";
};
FastqSequence::FastqSequence(std::string sequence, std::string header, std::string quality){
    this->setDescription(header);
    this->setSequence(sequence);
    comments = "";
    this->setQuality(quality);
};
void FastqSequence::setQuality(std::string qual){
    quality = qual;
};
string FastqSequence::getQuality(){
    return quality;
};
void FastqSequence::setComments(std::string comm){
    comments = comm;
};
string FastqSequence::getComments(){
    return comments;
};
