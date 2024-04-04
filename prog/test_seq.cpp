#include <iostream>
#include <fstream>
#include <cassert>
#include "seq.h"

void testSequence() {
    // Test default constructor
    Sequence seq1;
    assert(seq1.len() == 0);

    // Test constructor with sequence
    Sequence seq2("ATCG");
    assert(seq2.len() == 4);
    assert(seq2.getSequence() == "ATCG");

    // Test setSequence
    seq2.setSequence("GCTA");
    assert(seq2.len() == 4);
    assert(seq2.getSequence() == "GCTA");

    // Test read_file
    seq2.read_file("input.txt");
    assert(seq2.len() == 10);
    assert(seq2.getSequence() == "ACGTACGTAC");

    // Test destructor
    seq2.~Sequence();
    assert(seq2.len() == 0);
}

int main() {
    testSequence();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}