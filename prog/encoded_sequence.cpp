#include "encoded_sequence.h"
#include <iostream>
using namespace std;

#define silent 1

static char _encode(char c) {
  if (c >= 97) {
    c -= 32; // Passage d'un nucléotide en minuscule à un nucléotide
             // majuscule (cf. table ASCII).
  }
  return ((c == 'A')
          ? 0
          : ((c == 'C')
             ? 1
             : ((c == 'G')
                ? 2
                : (((c == 'T') || (c == 'U'))
                   ? 3
                   : (random() & 3) // Nucléotide au hasard
                   // x % 4 = x % 2^2
                   //       = x & (2^2 - 1)
                   //       = x & 3
                   ))));
}

static char _decode(char c) {
  return ((c == 0)
          ? 'A'
          : ((c == 1)
             ? 'C'
             : ((c == 2)
                ? 'G'
                : ((c == 3)
                   ? 'T'
                   : _decode(c & 3))))); // ce dernier cas est
                                        // complétement débile.
}

EncodedSequence::EncodedSequence(const char *c_str): _data(NULL), _size(0), _raw_capacity(0) {
  if (!silent) {
    cout << "Création de l'objet à l'adresse " << this << endl;
  }
  if (!c_str) return;
  while (*c_str != '\0') {
    ajouteNucleotide(*c_str);
    ++c_str;
  }
}

EncodedSequence::EncodedSequence(const string &s): _data(NULL), _size(0), _raw_capacity(0) {
  if (!silent) {
    cout << "Création de l'objet à l'adresse " << this << endl;
  }
  for (size_t i = 0; i < s.size(); ++i) {
    ajouteNucleotide(s[i]);
  }
}

EncodedSequence::EncodedSequence(const EncodedSequence &es): _data(NULL), _size(0), _raw_capacity(0) {
 if(!silent){
 cout << "Création de l'objet à l'adresse " << this
      << " (par copie de celui à l'adresse " << &es << ")" << endl;
  }
 resize(es.size());
 for (size_t i = 0; i < rawSize(); ++i) {
   _data[i] = es._data[i];
 }
}

EncodedSequence::~EncodedSequence() {
  if(!silent){
  cout << "Destruction de l'objet à l'adresse " << this << endl;
  }
  if (_data) {
    delete [] _data;
  }
}

EncodedSequence &EncodedSequence::operator=(const EncodedSequence &es) {
  if(!silent){
  cout << "Affectation du contenu de la séquence encodée à l'adresse " << &es
       << " dans la séquence encodée à l'adresse " << this << endl;
  }
  if (&es != this) {
    clear();
    resize(es.size());
    for (size_t i = 0; i < rawSize(); ++i) {
      _data[i] = es._data[i];
    }
  }
  return *this;
}

size_t EncodedSequence::rawSize() const {
  // x >> 2 equivaut à x / 4 (division entière)
  return (_size ? ((_size - 1) >> 2) + 1 : 0);
}

string EncodedSequence::decode() const {
  string res;
  res.reserve(size());
  for (size_t i = 0; i < size(); ++i) {
    res.push_back(operator[](i)); // res.push_back((*this)[i])
  }
  return res;
}

char EncodedSequence::operator[](size_t p) const {
  size_t numero_octet = p >> 2; // == p / 4
  size_t position_dans_octet = p & 3; // == p % 4
  char w = _data[numero_octet];
  size_t delta = (3 - position_dans_octet) << 1; // = (3 - position_dans_octet) * 2
  return _decode((w >> delta) & 3);
}

void EncodedSequence::setNucleotide(size_t p, char c) {
  size_t numero_octet = p >> 2; // == p / 4
  size_t position_dans_octet = p & 3; // == p % 4
  char w = _data[numero_octet];
  size_t delta = (3 - position_dans_octet) << 1; // = (3 - position_dans_octet) * 2
  char mask = ~(3 << delta);
  w = w & mask; // met les deux bits d'intérêt à 0
  w = w | (_encode(c) << delta); // remplace les deux bits d'intérêts
                                 // par le codage du nucléotide c
  _data[numero_octet] = w;
}

void EncodedSequence::ajouteNucleotide(char c) {
  if (size() == capacity()) {
    reserve(capacity() ? 2 * capacity() : 1);
  }
  resize(size() + 1);
  setNucleotide(size() - 1, c);
}

void EncodedSequence::resize(size_t n) {
  reserve(n);
  for (size_t i = n; i < _size; ++i) {
    setNucleotide(i, 'A');
  }
  _size = n;
}

void EncodedSequence::reserve(size_t n) {
  size_t raw_n = (n ? ((n - 1) >> 2) + 1 : 0);
  if (raw_n > _raw_capacity) {
    char *tmp = new char[raw_n];
    for (size_t i = 0; i < _raw_capacity; ++i) {
      tmp[i] = _data[i];
    }
    for (size_t i = _raw_capacity; i < raw_n; ++i) {
      tmp[i] = 0;
    }
    _raw_capacity = n;
    delete [] _data;
    _data = tmp;
  }
}

void EncodedSequence::shrink_to_fit() {
  size_t n = rawSize();
  if (n < _raw_capacity) {
    char *tmp = new char[n];
    for (size_t i = 0; i < n; ++i) {
      tmp[i] = _data[i];
    }
    delete [] _data;
    _data = tmp;
    _raw_capacity = n;
  }
}

void EncodedSequence::clear() {
  resize(0);
}

int EncodedSequence::compare(const EncodedSequence &e) const {
  int res = 0;
  size_t n1 = rawSize();
  size_t n2 = e.rawSize();
  size_t n = n1 < n2 ? n1 : n2; // n = min(n1, n2)
  size_t i = 0;
  while (!res && (i < n)) {
    if (_data[i] > e._data[i]) {
      res = 1;
    } else {
      if (_data[i] < e._data[i]) {
        res = -1;
      } else {
        ++i;
      }
    }
  }
  if (!res) {
    if (size() < e.size()) {
      res = -1;
    } else {
      if (size() > e.size()) {
        res = 1;
      }
    }
  }
  return res;
}

void EncodedSequence::affiche(ostream &os) const {
  for (size_t i = 0; i < size(); ++i) {
    os << operator[](i); // res.push_back((*this)[i])
  }
}

ostream &operator<<(ostream &os, const EncodedSequence &es) {
  es.affiche(os);
  return os;
}
