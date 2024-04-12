#ifndef __READ_FASTQ_H__
#define __READ_FASTQ_H__
#include <iostream>
#include <string>
#include <list>
#include "fastq_seq.h"
#include "seq.h"
#include "encoded_sequence.h"

bool is_valid_qual(char c);
bool handle_fastq(std::string fname, std::list<FastqSequence> &seqList);
/*
* Read a FASTQ file and return a list of FastqSequence
*/
std::list<FastqSequence> read_fastq(std::string fname);
#endif