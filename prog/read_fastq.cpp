#include <iostream>
#include <fstream>
#include <string>
#include "fastq_seq.h"
#include "seq.h"
#include "encoded_sequence.h"
#include "read_file.h"
#include "read_fastq.h"

using namespace std;

#define silent 1

bool is_valid_qual(char c) {
  return ((c >= 33) && (c <= 126));
}
bool handle_fastq(string fname, list<FastqSequence> &seqList){
    ifstream file = ifstream(fname);
    // Check if the file is open
    if (!file.is_open()) {
    cout << "Impossible d'ouvrir le fichier "
         << "'" << fname << "'"
         << "!" << endl;
    return false;
    }
    if (!silent){
        cout << "Fichier "
        << "'" << fname << "'"
        << " ouvert." << endl;
    }
    char c;
    FastqSequence *currentSeq = new FastqSequence();
    bool in_header = false;
    bool in_seq = false;
    bool in_qual = false;
    int nb_lines = 0;
    int nb_columns = 0;
    int nb_seq = -1;
    string seq = "";
    string qual = "";
    string header = "";

    while(file){
        //If the header isnt empty we need to store the e store the sequence in the list 
        if(nb_seq != -1 && seq != "" && header != "" && qual != ""){ 
            seqList.push_back(*currentSeq);
            currentSeq->~FastqSequence();
        }
        c = file.get(); // read a character from the file
        if(c == '@'){ // if the character is the beginning of a new sequence
            in_header = true; // we are in the header
            in_qual = false;
            if(in_seq){ // if we are in the sequence there is a problem in the file
                cout << "Error in " << fname << " line "<< nb_lines << " \n sequence line without quality" << endl;
                return false;
            }
            // we reset the variables
            header = ""; 
            seq = "";
            qual = "";
            while(c != '\n'){ // while we are in the header (= until we reach the end of the line)
                c = file.get();
                nb_columns++;
                header += c; // we store the header
            }
            nb_columns = 0;
            nb_lines++;
        }else{ // If we are not in the header
            if(c == '+'){ // we check if we are in the quality lines
                in_seq = false;
                in_qual = true;
                if(in_header){  // if the header is not false there is a problem in the file
                    cout << "Error in " << fname << " line "<< nb_lines << " \n quality line without sequence" << endl;
                    return false;
                }
                while (c != '@'){ // if we are we skip the characters
                    c = file.get();
                    if(!is_valid_qual(c)){
                        cout << "Error in " << fname << " line "<< nb_lines <<" column " << nb_columns << " \n invalid quality character" << endl;
                        return false;
                    }
                    else{
                        qual += c;
                    }
                    nb_columns++;
                    if(c == '\n'){
                        nb_lines++;
                        nb_columns = 0;
                    }
                }
            }
            else{ // if we are not in the header or in the quality lines we are in the sequence
                in_header = false;
                in_seq = true;
                if(in_qual){ // if we are in the quality lines there is a problem in the file
                    cout << "Error in " << fname << " line "<< nb_lines << " \n sequence line without header" << endl;
                    return false;
                }
                c = file.get();
                nb_columns++;
                while(c != '\n'){
                    if(is_valid_nucl(c) || is_valid_aa(c)){ // if the character is a valid nucleotide or amino acid
                        seq += c; // we store it in the sequence
                    }
                    else{
                        cout << "Error in " << fname << " line "<< nb_lines <<" column " << nb_columns << " \n invalid sequence character" << endl;
                        return false;
                    }        
                }
                nb_columns = 0;
                nb_lines++;
        }

        if(seq != "" && header != "" && qual != ""){ // if the current sequence is not empty we store it in the sequence class
                currentSeq->setDescription(header);
                currentSeq->setSequence(seq);
                
                currentSeq->setQuality(qual);
                nb_seq++;
        }
    }
    file.close();
    currentSeq->~FastqSequence();
    }
    return true;
}
list<FastqSequence> read_fastq(string fname){
    list<FastqSequence> seqList;
    if (!handle_fastq(fname, seqList)) {
        cout << "Il y a eu un souci lors de la lecture du fichier" << endl;
    }
    return seqList;
}
