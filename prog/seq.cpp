#include <string>
#include <iostream>
#include <fstream>
#include "encoded_sequence.h"
#include "seq.h"

using namespace std;

Sequence::Sequence(){
    sequence = NULL;
    length = 0;
};

Sequence::Sequence(char* seq){
    sequence = new EncodedSequence(seq);
    length = sequence->length();
};
Sequence::~Sequence(){
    if (sequence != NULL){
        sequence->~EncodedSequence();
        length = 0;
    }
};

void Sequence::setSequence(char* seq){
    if (sequence != NULL){
        sequence->~EncodedSequence();
    }
    sequence = new EncodedSequence(seq);
    length = sequence->size();
};
string getSequence(){
    return sequence->decode();
};
int getLength(){
    return this->len();
};



