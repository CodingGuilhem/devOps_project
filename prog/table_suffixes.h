#ifndef __TABLES_SUFFIXES_H__
#define __TABLES_SUFFIXES_H__

#include <string>
#include <vector>
#include <list>
#include <iostream>

class TableSuffixes {
 private:
  const std::string &_ref;
  std::vector<size_t> _suffixes;
  
  int _compare(const std::string &mot, size_t i) const;
  void _affiche(std::ostream &os, size_t i, size_t n = -1) const;
  size_t _cherche(const std::string &mot) const;
  std::pair<size_t, size_t> _chercheTous(const std::string &mot) const;

 public:

  TableSuffixes(const std::string &ref);

  std::list<size_t> occurrences(const std::string &motif) const;

  void affiche(std::ostream &os) const;
  
  bool operator()(size_t i, size_t j) const;

  int find_lcp(size_t i, size_t j);

};

#endif
