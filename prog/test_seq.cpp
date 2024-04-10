#include <iostream>
#include "seq.h"
#include "fasta_seq.h"
#include "fastq_seq.h"
#include "encoded_sequence.h"
#include "encoded_sequence.h"

using namespace std;
int main() {
    // Test des différents constructeurs
    Sequence seq1;
    cout << "Sequence 1 (default constructor):\n";
    cout << "Sequence: " << seq1.getSequence() << endl;
    cout << "Description: " << seq1.getDescription() << endl;

    Sequence seq2("ATCG");
    cout << "\nSequence 2 (sequence constructor):\n";
    cout << "Sequence: " << seq2.getSequence() << endl;
    cout << "Description: " << seq2.getDescription() << endl;

    Sequence seq3("ATCG", "DNA sequence");
    cout << "\nSequence 3 (sequence and description constructor):\n";
    cout << "Sequence: " << seq3.getSequence() << endl;
    cout << "Description: " << seq3.getDescription() << endl;

    // Test de la modification de la séquence et de la description
    cout << "\nSetting sequence and description for Sequence 1...\n";
    seq1.setSequence("GCTA");
    seq1.setDescription("RNA sequence");
    cout << "New sequence for Sequence 1: " << seq1.getSequence() << endl;
    cout << "New description for Sequence 1: " << seq1.getDescription() << endl;
    
    cout << "fastQsequence class : " << endl << endl;

    FastqSequence seq4;
    cout << "Sequence 4 (default constructor):\n";
    cout << "Sequence: " << seq4.getSequence() << endl;
    cout << "Quality: " << seq4.getQuality() << endl;
    cout << "Comments: " << seq4.getComments() << endl;

    FastqSequence seq5("ATCG");
    cout << "\nSequence 5 (sequence constructor):\n";
    cout << "Sequence: " << seq5.getSequence() << endl;
    cout << "Quality: " << seq5.getQuality() << endl;
    cout << "Comments: " << seq5.getComments() << endl;

    FastqSequence seq6("ATCG", "Header", "IIII");
    cout << "\nSequence 6 (sequence, header, and quality constructor):\n";
    cout << "Sequence: " << seq6.getSequence() << endl;
    cout << "Quality: " << seq6.getQuality() << endl;
    cout << "Comments: " << seq6.getComments() << endl;

    // Test de la modification de la qualité et des commentaires
    cout << "\nSetting quality and comments for Sequence 4...\n";
    seq4.setQuality("HHHH");
    seq4.setComments("New comments for sequence 4");
    cout << "New quality for Sequence 4: " << seq4.getQuality() << endl;
    cout << "New comments for Sequence 4: " << seq4.getComments() << endl;

    cout << "Fasta Sequence : " << endl << endl;
    FastaSequence seq7;
    cout << "Sequence 7 (default constructor):\n";
    cout << "Sequence: " << seq7.getSequence() << endl;
    cout << "Description: " << seq7.getDescription() << endl;
    cout << "Comments: " << seq7.getComments() << endl;

    FastaSequence seq8("ATCG");
    cout << "\nSequence 8 (sequence constructor):\n";
    cout << "Sequence: " << seq8.getSequence() << endl;
    cout << "Description: " << seq8.getDescription() << endl;
    cout << "Comments: " << seq8.getComments() << endl;

    FastaSequence seq9("ATCG", "DNA sequence", "Some comments");
    cout << "\nSequence 9 (sequence, description, and comments constructor):\n";
    cout << "Sequence: " << seq9.getSequence() << endl;
    cout << "Description: " << seq9.getDescription() << endl;
    cout << "Comments: " << seq9.getComments() << endl;

    // Test de la modification des commentaires
    cout << "\nSetting comments for Sequence 7...\n";
    seq7.setComments("New comments for sequence 7");
    cout << "New comments for Sequence 7: " << seq7.getComments() << endl;
    
    return 0;
}
