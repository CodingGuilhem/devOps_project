#ifndef __READ_FASTA_H__
#define __READ_FASTA_H__
#include <iostream>
#include <list>
#include "fasta_seq.h"
#include "seq.h"

/*
* read a fasta file and return a list of FastaSequence
*/
std::list<FastaSequence> read_fasta(std::string fname);
#endif