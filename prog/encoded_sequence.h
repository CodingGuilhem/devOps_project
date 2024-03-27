#ifndef __ENCODED_SEQUENCE_H__
#define __ENCODED_SEQUENCE_H__

#include <string>

/**
 * Permet de stocker une séquence nucléotidique en utilisant 1 octet
 * pour 4 nucléotides.
 */
class EncodedSequence {

 private:

  /*
   * Tableau d'octets pour stocker les nucléotides encodés.
   */
  char *_data;

  /*
   * Taille de la séquence (exprimée en nucléotides).
   *
   * La taille du tableau _data est donc ((_size - 1) / 4) + 1 si
   * _size est positif, donc séquence non vide, et 0 sinon).
   */
  size_t _size;

  /*
   * Capacité du tableau d'octets.
   *
   * À tout moment, nous avons _raw_capacity * 4 >= _size
   */
  size_t _raw_capacity;

 public:

  /**
   * Crée une séquence encodée correspondant à la séquence passée en
   * paramètre.
   *
   * \param cstr La chaîne C à utiliser pour construire la séquence
   * encodée correspondante.
   */
  EncodedSequence(const char *cstr = NULL);

  /**
   * Crée une séquence encodée correspondant à la séquence passée en
   * paramètre.
   *
   * \param s La chaîne à utiliser pour construire la séquence
   * encodée correspondante.
   */
  EncodedSequence(const std::string &s);

  /**
   * Crée une séquence encodée par copie de la séquence encodée passée
   * en paramètre.
   *
   * \param es La séquence encodée à dupliquer.
   */
  EncodedSequence(const EncodedSequence &es);

  /**
   * Opérations à réaliser lors de la destruction de l'instance
   * courante.
   */
  ~EncodedSequence();

  /**
   * Surcharge de l'opérateur d'affectation.
   *
   * L'instance courante correspond à la partie gauche de
   * l'affectation.
   *
   * \remark Soient e1 et e2, deux EncodedSequence, écrire : `e1 = e2;`
   * revient à écrire en réalité `e1.operator=(e2)`.
   *
   * \param es Partie droite de l'affectation (séquence à copier).
   *
   * \return Renvoie la séquence courante après mise à jour.
   */
  EncodedSequence &operator=(const EncodedSequence &es);

  /**
   * Renvoie la taille de la séquence (nombre de nucléotides)
   *
   * \return Renvoie la taille de la séquence.
   */
  inline size_t size() const {
    return _size;
  }

  /**
   * Renvoie la taille de la séquence (nombre de nucléotides).
   *
   * \see Voir la méthode size().
   *
   * \return Renvoie la taille de la séquence. 
   */
  inline size_t length() const {
    return size();
  }

  /**
   * Renvoie le nombre de nucléotides représentables sans besoin de
   * ré-allouer de la mémoire.
   *
   * \return Renvoie le nombre de nucléotides représentables sans
   * besoin de ré-allouer de la mémoire.
   */
  inline size_t capacity() const {
    return _raw_capacity << 2;
  }

  /**
   * Renvoie le nombre d'octets utilisés pour stocker la séquence
   * encodée.
   *
   * Ce n'est pas la même chose que la valeur de _raw_capacity;
   *
   * \return Renvoie le nombre d'octets utilisés pour stocker la
   * séquence encodée.
   */
  size_t rawSize() const;

  /**
   * Renvoie la séquence décodée.
   *
   * \return Renvoie la séquence décodée.
   */
  std::string decode() const;

  /**
   * Affiche la séquence encodée courante sur le flux passé en
   * paramètre.
   *
   * \param os Le flux dans lequel écrire la séquence décodée.
   */
  void affiche(std::ostream &os) const;

  /**
   * Renvoie le nucléotide à la position donnée.
   *
   * \param p La position du nucléotide à renvoyer (en commençant à
   * 0).
   *
   * \return Renvoie le nucléotide à la position p dans la séquence
   * d'origine.
   */
  char operator[](size_t p) const;

  /**
   * Change le nucléotide à la position p par le nucléotide donné.
   *
   * \param p La position du nucléotide à modifier.
   *
   * \param c Le nucléotide à positionner.
   */
  void setNucleotide(size_t p, char c);

  /**
   * Ajoute le nucléotide passé en paramètre à la fin de la séquence
   * encodée.
   *
   * \param c Le nucléotide à ajouter à la fin de la séquence.
   */
  void ajouteNucleotide(char c);

  /**
   * Redimensionne la séquence encodée à la taille voulue.
   *
   * Si la séquence est agrandie, le nucléotide 'A' est utilisé pour
   * l'initialisation des nucléotides ajoutés.
   *
   * \param n La nouvelle dimension de la séquence.
   */
  void resize(size_t n);

  /**
   * Alloue (au besoin) suffisament d'octets pour stocker n
   * nucléotides.
   *
   * Si la séquence courante est plus grande que la réserve demandée
   * on ne fait rien.
   *
   * \param n Le nombre de nucléotides que la séquence doit pouvoir
   * représenter *a minima*.
   */
  void reserve(size_t n);

  /**
   * Vide la séquence (attention, cela ne libère pas la mémoire).
   */
  void clear();

  /**
   * Libère la mémoire de sorte à n'utiliser que le stict minimum
   * d'octets pour représenter la séquence.
   */
  void shrink_to_fit();

  /**
   * Compare la séquence encodée avec celle passé en paramètre.
   *
   * \param e La séquence encodée à comparer avec la séquence
   * courante.
   *
   * \return Renvoie une valeur négative si l'instance courante est
   * lexicographiquement plus petite (A < C < G < T) ; renvoie une
   * valeur positive si c'est l'inverse et une valeur nulle si les
   * deux séquences sont identiques.
   */
  int compare(const EncodedSequence &e) const;

  /**
   * Vérifie si la séquence encodée courante est vide.
   *
   * \return Renvoie vrai si et seulement si la séquence courante est
   * vide.
   */
  inline bool empty() const {
    return (_size == 0);
  }

};

std::ostream &operator<<(std::ostream &os, const EncodedSequence &es);

#endif
