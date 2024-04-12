# Compilateur C++
CXX = g++
# Options de compilation
CXXFLAGS = -Wall -Wextra -std=c++11
# Options pour l'édition des liens
LDFLAGS =

all : test_seq

test_seq : test_seq.cpp seq.o fasta_seq.o fastq_seq.o encoded_sequence.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

seq.o : seq.cpp seq.h encoded_sequence.o 
	$(CXX) $(CXXFLAGS) -c $<

fasta_seq.o : fasta_seq.cpp fasta_seq.h seq.o
	$(CXX) $(CXXFLAGS) -c $<

fastq_seq.o : fastq_seq.cpp fastq_seq.h seq.o
	$(CXX) $(CXXFLAGS) -c -o $@ $<

encoded_sequence.o : encoded_sequence.cpp encoded_sequence.h
	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -f *.o test_seq
