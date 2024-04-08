#include <iostream>
#include <fstream>
#include "seq.h"


class FastaSequence : public Sequence {
    private :
        std::string header;

    public:
        FastaSequence();
        FastaSequence(char* sequence);
        FastaSequence(char* sequence, char* header);
        void setHeader(char* header);
        char* getHeader();
        virtual void read(char* filename);
};