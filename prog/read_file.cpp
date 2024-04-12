#include <iostream>
#include <list>
#include <string>
#include "seq.h"
#include "fasta_seq.h"
#include "fastq_seq.h"
#include "encoded_sequence.h"
#include "read_file.h"

bool  is_valid_nucl(char c){
    return ((c == 'a') || (c == 'A')
          || (c == 'c') || (c == 'C')
          || (c == 'g') || (c == 'G')
          || (c == 't') || (c == 'T')
          || (c == 'u') || (c == 'U')
          || (c == 'b') || (c == 'B')
          || (c == 'd') || (c == 'D')
          || (c == 'h') || (c == 'H')
          || (c == 'v') || (c == 'V')
          || (c == 'w') || (c == 'W')
          || (c == 's') || (c == 'S')
          || (c == 'k') || (c == 'K')
          || (c == 'm') || (c == 'M')
          || (c == 'p') || (c == 'P')
          || (c == 'y') || (c == 'Y')
          || (c == '.') || (c == '-')
          || (c == 'n') || (c == 'N'));
};
bool  is_valid_aa(char c){
    return ((c == 'A') || (c == 'a')
          || (c == 'R') || (c == 'r')
          || (c == 'N') || (c == 'n')
          || (c == 'D') || (c == 'd')
          || (c == 'C') || (c == 'c')
          || (c == 'Q') || (c == 'q')
          || (c == 'E') || (c == 'e')
          || (c == 'G') || (c == 'g')
          || (c == 'H') || (c == 'h')
          || (c == 'I') || (c == 'i')
          || (c == 'L') || (c == 'l')
          || (c == 'K') || (c == 'k')
          || (c == 'M') || (c == 'm')
          || (c == 'F') || (c == 'f')
          || (c == 'P') || (c == 'p')
          || (c == 'S') || (c == 's')
          || (c == 'T') || (c == 't')
          || (c == 'W') || (c == 'w')
          || (c == 'Y') || (c == 'y')
          || (c == 'V') || (c == 'v')
          || (c == 'B') || (c == 'b')
          || (c == 'Z') || (c == 'z')
          || (c == 'X') || (c == 'x')
          || (c == '*'));
};
bool is_a_fastq_file(std::string fname){
    return (fname.find(".fastq") != std::string::npos);
};
bool is_a_fasta_file(std::string fname){
    return (fname.find(".fasta") != std::string::npos);
};
