#include <iostream>
#include <list>
#include <string>
#include "seq.h"
#include "fasta_seq.h"
#include "fastq_seq.h"
#include "read_fasta.h"
#include "read_fastq.h"
#include "encoded_sequence.h"

using namespace std;

// Fonction pour afficher les informations d'une séquence
void afficher_sequence(FastaSequence &seq) {
    cout << "Description: " << seq.getDescription() << endl;
    cout << "Sequence: " << seq.getSequence() << endl;
}

int main() {
    string nom_fichier = "votre_fichier.fasta"; // Remplacez "votre_fichier.fasta" par le nom de votre fichier FASTA

    // Lecture du fichier FASTA
    list<FastaSequence> sequences = read_fasta(nom_fichier);

    // Vérification si la lecture a été réussie
    if (sequences.empty()) {
        cerr << "Erreur: Aucune séquence lue depuis le fichier : " << nom_fichier << endl;
        return 1;
    }

    // Affichage des informations de chaque séquence
    for ( FastaSequence sequence : sequences) {
        afficher_sequence(sequence);
        cout << endl;
    }

    return 0;
}
