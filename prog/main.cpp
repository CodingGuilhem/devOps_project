#include <iostream>
#include <list>
#include <string>
#include "table_suffixes.h"
#include "read_fastq.h"
#include "read_fasta.h"
#include "seq.h"
#include "fastq_seq.h"
#include "fasta_seq.h"

using namespace std;

void usage (){
    cout << "This program maps reads from a file to a reference file." << endl;
    cout << "Usage : ./map [options] <reference_file> <reads_file>" << endl;
    cout << "Options : " << endl;
    cout << "-h : display this help" << endl;
    cout << "-f : reads file format (fasta or fastq)" << endl;
    cout << "-r : reference file format (fasta or fastq)" << endl;
    cout << "-o : output file" << endl;
    cout << "-k : k-mer size" << endl << endl;
    cout << "Example : ./map -f fastq -r fasta -o output.txt -k 10 reference.fasta reads.fastq" << endl << endl;
}
int main (int argc, char** argv){
    if(argc < 3){
        usage();
        return 1;
    }
    else{
        for (int i = 1; i < argc; i++){
            switch (expression)
            {
            case /* constant-expression */:
                /* code */
                break;
            
            default:
                break;
            }
        }
    }

}