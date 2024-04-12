#include "table_suffixes.h"

#include <algorithm>

using namespace std;

// Structure de manipulation de comparaison des suffixes

int TableSuffixes::_compare(const string &mot, size_t i) const {
  size_t n = _ref.size();
  size_t m = mot.size();
  size_t j = 0;
  int cmp = 0;
  // cmp < 0 <=> ref[i..n] < ref[j..n]
  // cmp > 0 <=> ref[i..n] > ref[j..n]
  while ((cmp == 0) && (i < n) && (j < m)){
    if (mot[j] < _ref[i]) {
      cmp = -1;
    } else {
      if (mot[j] > _ref[i]) {
        cmp = 1;
      } else {
        ++i;
        ++j;
      }
    }
  }
  if ((cmp == 0) && (j < m)) {
    cmp = 1;
  }
  return cmp;
}

void TableSuffixes::_affiche(ostream &os, size_t i, size_t n) const {
  size_t _n = _ref.size();
  while ((i < _n) && (n-- > 0)) {
    os << _ref[i];
    ++i;
  }
}

bool TableSuffixes::operator()(size_t i, size_t j) const {
  size_t n = _ref.size();
  int cmp = 0;
  // cmp < 0 <=> _ref[i..n] < _ref[j..n]
  // cmp > 0 <=> _ref[i..n] > _ref[j..n]
  while ((cmp == 0) && (i < n) && (j < n)){
    if (_ref[i] < _ref[j]) {
      cmp = -1;
    } else {
      if (_ref[i] > _ref[j]) {
        cmp = 1;
      } else {
        ++i;
        ++j;
      }
    }
  }
  if (i == n) {
    cmp = -1;
  }
  return cmp < 0;
}

TableSuffixes::TableSuffixes(const string &ref): _ref(ref), _suffixes(ref.size() + 1) {
  for (size_t i = 0; i < _suffixes.size(); ++i) {
    _suffixes[i] = i;
  }

  cout << "Table des suffixes non triée:" << endl;
  affiche(cout);

  sort(_suffixes.begin(), _suffixes.end(), *this);

  cout << "Table des suffixes triée:" << endl;
  affiche(cout);

}

list<size_t> TableSuffixes::occurrences(const string &motif) const {
  pair<size_t, size_t> p = _chercheTous(motif);
  list<size_t> pos;
  if (p.first != (size_t) -1) {
    for (size_t i = p.first; i <= p.second; ++i) {
      pos.push_back(_suffixes[i]);
    }
  }
  return pos;
}

void TableSuffixes::affiche(std::ostream &os) const {
  for (size_t i = 0; i < _suffixes.size(); ++i) {
    os << "- '";
    _affiche(os, _suffixes[i]);
    os << "'" << endl;
  }
}

size_t TableSuffixes::_cherche(const string &mot) const {
  size_t debut = 0, fin = _suffixes.size(), pos = 0;
  bool trouve = mot.empty();

  while (!trouve && (debut < fin)) {
    pos = (debut + fin) / 2;
    int c = _compare(mot, _suffixes[pos]);
    if (c < 0) {
      fin = pos;
    } else {
      if (c > 0) {
        debut = pos + 1;
      } else {
        trouve = true;
      }
    }
  }
  return trouve ? pos : -1;
}

pair<size_t, size_t> TableSuffixes::_chercheTous(const string &mot) const {
  size_t pos, premier, dernier;
  pos = premier = dernier = _cherche(mot);
  if (pos > 0) {
    bool trouve = true;
    while (trouve && (premier > 0)) {
      trouve = _compare(mot, _suffixes[--premier]) == 0;
    }

    trouve = (pos != (size_t) -1);
    while (trouve && (++dernier < _suffixes.size())) {
      trouve = _compare(mot, _suffixes[dernier]) == 0;
    }

    ++premier;
    --dernier;
  } else {
    if (pos == 0) {
      dernier = _suffixes.size() - 1;
    }
  }

  return pair<size_t, size_t>(premier, dernier);
}

int TableSuffixes::find_lcp(size_t i, size_t j){
  size_t lcp = 0;
  bool not_found = true;
  size_t cpt = 0;
  
  return 0;
  while(not_found ){}

}
