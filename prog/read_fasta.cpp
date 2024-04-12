#include <iostream> // pour cout/endl/...
#include <fstream>  // pour ifstream
#include <string>   // pour string
#include <libgen.h> // pour basename(...)
#include <list>     // pour list
#include "fasta_seq.h"

using namespace std;

#define silent 1

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

bool is_valid_aa(char c) {
  return ((c == 'A') || (c == 'a')
          || (c == 'R') || (c == 'r')
          || (c == 'N') || (c == 'n')
          || (c == 'D') || (c == 'd')
          || (c == 'C') || (c == 'c')
          || (c == 'Q') || (c == 'q')
          || (c == 'E') || (c == 'e')
          || (c == 'G') || (c == 'g')
          || (c == 'H') || (c == 'h')
          || (c == 'I') || (c == 'i')
          || (c == 'L') || (c == 'l')
          || (c == 'K') || (c == 'k')
          || (c == 'M') || (c == 'm')
          || (c == 'F') || (c == 'f')
          || (c == 'P') || (c == 'p')
          || (c == 'S') || (c == 's')
          || (c == 'T') || (c == 't')
          || (c == 'W') || (c == 'w')
          || (c == 'Y') || (c == 'y')
          || (c == 'V') || (c == 'v')
          || (c == 'B') || (c == 'b')
          || (c == 'Z') || (c == 'z')
          || (c == 'X') || (c == 'x')
          || (c == '*'));
}


/*
 * Cette fonction lit un fichier contenant des séquences au format FASTA.
 *
 * Cette fonction renvoie vrai si tout s'est bien passé et faux sinon.
 */
bool handle_fasta(string fname, list<FastaSequence> &seqList)  {
  ifstream fich(fname);

  if (!fich.is_open()) {
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

  // Lecture de chaque ligne du fichier
  int nb_l = 1; // Numéro de ligne du fichier en cours de lecture
  int nb_c = 0; // Numéro de colonne du fichier en cours de lecture
  char c; // Caractère courant
  // string l; // Ligne en cours (pour le debug uniquement)
  string header; // Entête de la séquence en cours
  string sequence; // Contenu de la séquence en cours
  bool in_header = true; // Booléen qui est vrai lors de la lecture d'un nouvel entête et faux sinon.
  bool in_comment = false; // Booléen qui est vrai lors de la lecture d'un commentaire et faux sinon.
  int nb_sequences = -1; // Compteur du nombre de séquences (mis à -1 pour gérer le cas de la toute première séquence)
  FastaSequence *currentSeq = new FastaSequence();

  while (fich) {
    if (currentSeq->getDescription() != ""){
      seqList.push_back(*currentSeq);
      currentSeq->~FastaSequence();
    }
    c = fich.get(); // Lecture du caractère courant avec déplacement du curseur de lecture
    ++nb_c;
    // cout << "DEBUG:" << fname << ":" << nb_l << ":" << nb_c << ":"
    //      << "Lecture du caractère '" << c << "' (code ASCII " << (int) c << ", soit " << hex << (int) c << dec << " en hexadécimal)." << endl;
    if (c == '\n') {
      ++nb_l; // Passage à une nouvelle ligne
      // cout << "DEBUG:" << fname << ":" << nb_l << ":" << nb_c << ":"
      //      << "Ligne lue: '" << l << "'" << endl;
      nb_c = 0;
      // l.clear();
      in_comment = false; // Fin du commentaire le cas échéant.
      c = fich.peek(); // Lecture du caractère qui débute la prochaine ligne sans déplacement du curseur de lecture.
      if ((c == '>') || (c == ';')) {
        if (in_header) {
          // L'entête est sur plusieurs lignes.
          // cout << "DEBUG:" << fname << ":" << nb_l << ":" << nb_c << ":"
          //      << "L'entête est sur plusieurs lignes." << endl;
          header += '\n';
        } else {
          // La prochaine ligne sera l'entête d'une nouvelle séquence.
          // cout << "DEBUG:" << fname << ":" << nb_l << ":" << nb_c << ":"
          //      << "La prochaine ligne sera l'entête d'une nouvelle séquence." << endl;
          in_header = true;
          if (++nb_sequences) {
            if(!silent){
            cout << "DEBUG:" << fname << ":" << nb_l << ":" << nb_c << ":"
                 << "La séquence qui vient d'être lue est donc la suivante:" << endl
                 << "- Numéro: '" << nb_sequences << "'" << endl
                 << "- Entête: '" << header << "'" << endl
                 << "- Séquence: '" << sequence << "'" << endl;
                 }
            currentSeq->setDescription(header);
            currentSeq->setSequence(sequence);

          }
          header.clear();
          sequence.clear();
        }
      } else {
        if (in_header) {
          // La prochaine ligne sera le début de la séquence biologique.
          // cout << "DEBUG:" << fname << ":" << nb_l << ":" << nb_c << ":"
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
              cout << "Fichier '" << fname << "' mal formé à la ligne "
                   << nb_l << " (colonne " << nb_c << "): caractère '"
                   << c << "' trouvé alors qu'une nouvelle séquence est attendue (caractère '>' ou ';')" << endl;
              return false;
            }
            if (nb_sequences == -1) {
              nb_sequences = 0;
            }
          } else {
            // Ajout du caractère courant à l'entête
            // cout << "DEBUG:" << fname << ":" << nb_l << ":" << nb_c << ":"
            //      << "Ajout du caractère '" << c << "' à l'entête de la séquence courante." << endl;
            header += c;
          }
        } else {
          if (c > ' ') {
            if (c == ';') {
              // Début d'un commentaire qui va jusqu'à la fin de la ligne
              // cout << "DEBUG:" << fname << ":" << nb_l << ":" << nb_c << ":"
              //      << "Passage en mode commentaire jusqu'à la fin de la ligne." << endl;
              in_comment = true;
            } else {
              if (nb_sequences == -1) {
                cout << "Fichier '" << fname << "' mal formé à la ligne "
                     << nb_l << " (colonne " << nb_c << "): caractère '"
                     << c << "' trouvé alors qu'aucun entête n'a encore été défini." << endl;
                return false;
              } else {
                // Le caractère est un caractère visible (l'espace n'est pas considéré comme visible ici)
                if (is_valid_nucl(c) || is_valid_aa(c)) {
                  // Ajout du caractère courant à la séquence
                  // cout << "DEBUG:" << fname << ":" << nb_l << ":" << nb_c << ":"
                  //      << "Ajout du caractère '" << c << "' à la séquence courante." << endl;
                  sequence += c;
                } else {
                  cout << "Fichier '" << fname << "' mal formé à la ligne "
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

  // Prise en compte de la dernière séquence
  ++nb_sequences;
  if (!silent){
  cout << "DEBUG:" << fname << ":" << nb_l << ":" << nb_c << ":"
       << "La séquence qui vient d'être lue est donc la suivante:" << endl
       << "- Numéro: '" << nb_sequences << "'" << endl
       << "- Entête: '" << header << "'" << endl
       << "- Séquence: '" << sequence << "'" << endl;
  }
  fich.close();

  if (fich.is_open()) {
    cout << "Problème à la fermeture du fichier "
         << "'" << fname << "'"
         << "!" << endl;
    return false;
  } else {
    if(!silent){
    cout << "Fichier "
         << "'" << fname << "'"
         << " fermé." << endl;
    }
  }
  return true;
}

list<FastaSequence> read_fasta(string fname) {

      list<FastaSequence> seqList;
      if (!handle_fasta(fname, seqList)) {
        cout << "Il y a eu un souci lors de la lecture du fichier" << endl;
      }
      return seqList;
}
