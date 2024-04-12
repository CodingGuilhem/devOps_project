#ifndef __READ_FILE_H__
#define __READ_FILE_H__
#include <iostream>
#include <list>
#include <string>
#include "seq.h"
#include "fasta_seq.h"
#include "fastq_seq.h"
#include "encoded_sequence.h"

bool  is_valid_nucl(char c);
bool  is_valid_aa(char c);

#endif