#include <iostream>
#include <fstream>
#include "read_seq.h"


class FastaSequence : public Sequence {
    
    public:
        FastaSequence();
        virtual void read(char* filename);
};