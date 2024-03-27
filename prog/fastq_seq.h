#include <iostream>
#include <fstream>
#include <string>
#include "read_seq.h"

class FastqSequence : public Sequence {
    private :
        std::string quality;  
  
    public:
        FastqSequence();
        virtual void read(char* filename);
};