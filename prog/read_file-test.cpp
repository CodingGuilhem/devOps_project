#include <iostream>
#include <list>
#include "fasta_seq.h"

using namespace std;

// Fonction pour afficher les informations d'une séquence
void afficher_sequence(const FastaSequence& seq) {
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
    for (const auto& sequence : sequences) {
        afficher_sequence(sequence);
        cout << endl;
    }

    return 0;
}
