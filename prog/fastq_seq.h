#include <iostream>
#include <fstream>
#include <string>
#include "seq.h"

class FastqSequence : public Sequence {
    private :
        std::string header; 
        std::string quality;  
  
    public:
        FastqSequence();
        FastqSequence(char* sequence);
        FastqSequence(char* sequence, char* header, char* quality);
        void setQuality(char* quality);
        char* getQuality();
        void setHeader(char* header);
        char* getHeader();
        virtual void read(char* filename);
};