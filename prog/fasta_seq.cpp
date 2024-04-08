#include <iostream>
#include <string>
#include <fstream>
#include "fasta_seq.h"

using namespace std;

bool is_valid_nucl(char c) {
  return ((c == 'a') || (c == 'A')
          || (c == 'c') || (c == 'C')
          || (c == 'g') || (c == 'G')
          || (c == 't') || (c == 'T')
          || (c == 'u') || (c == 'U')
          || (c == 'b') || (c == 'B')
          || (c == 'd') || (c == 'D')
          || (c == 'h') || (c == 'H')
          || (c == 'v') || (c == 'V')
          || (c == 'w') || (c == 'W')
          || (c == 's') || (c == 'S')
          || (c == 'k') || (c == 'K')
          || (c == 'm') || (c == 'M')
          || (c == 'p') || (c == 'P')
          || (c == 'y') || (c == 'Y')
          || (c == '.') || (c == '-')
          || (c == 'n') || (c == 'N'));
}

bool fromStream(istream &is,string *desc,string *seq) {
  int nb_l = 1; // Numéro de ligne du flux en cours de lecture
  int nb_c = 0; // Numéro de colonne du flux en cours de lecture
  char c; // Caractère courant
  string _description = ""; // Description de la séquence
  string _sequence = ""; // Séquence biologique
  // string l; // Ligne en cours (pour le debug uniquement)
  bool in_header = true; // Booléen qui est vrai lors de la lecture d'un nouvel entête et faux sinon.
  bool in_comment = false; // Booléen qui est vrai lors de la lecture d'un commentaire et faux sinon.
  bool in_sequence = false; // Séquence en cours de lecture

  while (is) {
    c = is.get(); // Lecture du caractère courant avec déplacement du curseur de lecture
    ++nb_c;
    // cout << "DEBUG:" << nb_l << ":" << nb_c << ":"
    //      << "Lecture du caractère '" << c << "' (code ASCII " << (int) c
    //      << ", soit " << hex << (int) c << dec << " en hexadécimal)." << endl;
    if (c == '\n') {
      ++nb_l; // Passage à une nouvelle ligne
      // cout << "DEBUG:" << nb_l << ":" << nb_c << ":"
      //      << "Ligne lue: '" << l << "'" << endl;
      nb_c = 0;
      // l.clear();
      in_comment = false; // Fin du commentaire le cas échéant.
      c = is.peek(); // Lecture du caractère qui débute la prochaine ligne sans déplacement du curseur de lecture.
      if ((c == '>') || (c == ';')) {
        if (in_header) {
          // L'entête est sur plusieurs lignes.
          // cout << "DEBUG:" << nb_l << ":" << nb_c << ":"
          //      << "L'entête est sur plusieurs lignes." << endl;
          _description += '\n';
        } else {
          // La prochaine ligne sera l'entête d'une nouvelle séquence.
          // cout << "DEBUG:" << nb_l << ":" << nb_c << ":"
          //      << "La prochaine ligne sera l'entête d'une nouvelle séquence." << endl;
          in_header = true;
          if (in_sequence) {
            return true;
          }
          _description = "";
          _sequence = "";
        }
      } else {
        if (in_header) {
          // La prochaine ligne sera le début de la séquence biologique.
          // cout << "DEBUG:" << nb_l << ":" << nb_c << ":"
          //      << "La prochaine ligne sera le début de la séquence biologique." << endl;
          in_header = false;
        }
      }
    } else {
      // l += c; // Ajout du caractère lu à la ligne en cours de lecture
      if (!in_comment) {
        // Si on est dans du commentaire, on ignore simplement, sinon on traite...
        if (in_header) {
          if (nb_c == 1) {
            // Normalement, le caractère est donc soit un '>' soit un ';'
            if ((c != '>') && (c != ';')) {
              cout << "Flux mal formé à la ligne "
                   << nb_l << " (colonne " << nb_c << "): caractère '"
                   << c << "' trouvé alors qu'une nouvelle séquence est attendue (caractère '>' ou ';')" << endl;
              return false;
            }
            in_sequence = true;
          } else {
            // Ajout du caractère courant à l'entête
            // cout << "DEBUG:" << nb_l << ":" << nb_c << ":"
            //      << "Ajout du caractère '" << c << "' à l'entête de la séquence courante." << endl;
            _description += c;
          }
        } else {
          if (c > ' ') {
            if (c == ';') {
              // Début d'un commentaire qui va jusqu'à la fin de la ligne
              // cout << "DEBUG:" << nb_l << ":" << nb_c << ":"
              //      << "Passage en mode commentaire jusqu'à la fin de la ligne." << endl;
              in_comment = true;
            } else {
              if (!in_sequence) {
                cout << "Flux mal formé à la ligne "
                     << nb_l << " (colonne " << nb_c << "): caractère '"
                     << c << "' trouvé alors qu'aucun entête n'a encore été défini." << endl;
                return false;
              } else {
                // Le caractère est un caractère visible (l'espace n'est pas considéré comme visible ici)
                if (is_valid_nucl(c) || is_valid_aa(c)) {
                  // Ajout du caractère courant à la séquence
                  // cout << "DEBUG:" << nb_l << ":" << nb_c << ":"
                  //      << "Ajout du caractère '" << c << "' à la séquence courante." << endl;
                  _sequence += c;
                } else {
                  cout << "Flux mal formé à la ligne "
                       << nb_l << " (colonne " << nb_c << "): caractère '"
                       << c << "' non valide (il sera simplement ignoré)." << endl;
                }
              }
            }
          }
        }
      }
    }
  }

  return true;
}

FastaSequence::FastaSequence(){
    header = "";
    this->setSequence(NULL);
    description = "";
};
FastaSequence::FastaSequence(string seq){
    header = "";
    this->setSequence(seq);
    description = "";
};
FastaSequence::FastaSequence(string seq, string head){
    header = head;
    this->setSequence(seq);
    description = "";
};

void FastaSequence::setHeader(string head){
    header = head;
};
string FastaSequence::getHeader(){
    return header;
};
void FastaSequence::read_file(string filename){
    ifstream file;
    file.open(filename);
    if (file.is_open()){
        string line;
        string seq = "";
        while(getline(file, line)){
                seq += line;
        }
        this->setSequence(seq);
    }
};
