#include "filter.h"
#include <iostream>
#include <list>

using namespace std;
/*
* Test if the Sequence contain a N 
* return true if the sequence contain N else return false 
*/
bool contain_N(Sequence seq){
    for(int i=0;i<=seq.len();i++){
        if(seq.getSequence()[i] == 'N'){
            return true;
        }
    }
    return false;
}
/*
* Delete the sequence that contains a N in the list of Sequences
* return the list of Sequences without those ones
*/
void delete_N(list<Sequence> seq_list){
    list<Sequence> result = list<Sequence>();
    for(int i = 0;i<=seq_list.size();i++){
        if(!contain_N(seq_list[i])){

        }
    }
}