#include <string>
#include <iostream>
#include <fstream>
#include "encoded_sequence.h"
#include "seq.h"

using namespace std;
/*
* Creator for the class Sequence
*/
Sequence::Sequence(){
    sequence = NULL;
    description = "";
};
/*
* Creator for the class Sequence
*/
Sequence::Sequence(string seq){
    sequence = new EncodedSequence(seq) ;
    description = "";
};
/*
* Creator for the class Sequence
*/
Sequence::Sequence(string seq, string desc){
    if (sequence != NULL){
        sequence->~EncodedSequence();
    }
    sequence = new EncodedSequence(seq);
    description = desc;
};
/*
* Destructor for the class Sequence
*/
Sequence::~Sequence(){
    if (sequence != NULL){
        sequence->~EncodedSequence();
    }
    description = "";
};
/*
* Set the sequence
*/
void Sequence::setSequence(string seq){
    if (sequence != NULL){
        sequence->~EncodedSequence();
    }
    sequence = new EncodedSequence(seq);
    description = "";
};
/*
* Get the sequence
*/
string Sequence::getSequence(){
    return sequence->decode();
};
/*
* Get the description
*/
string Sequence::getDescription(){
    return description;
};
/*
* Set the description
*/
void Sequence::setDescription(string desc){
    description = desc;
};

/*
* Get the length of the sequence
*/
size_t Sequence::len(){
    return sequence->length();
};
