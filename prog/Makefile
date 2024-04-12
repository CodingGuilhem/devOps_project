# Compilateur C++
CXX = g++
# Options de compilation
CXXFLAGS = -Wall -Wextra -std=c++11
# Options pour l'édition des liens
LDFLAGS =

all : test_read_fasta #test_seq

test_read_fasta : read_file.cpp read_fasta.o read_fastq.o fasta_seq.o seq.o encoded_sequence.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

read_fasta.o : read_fasta.cpp read_fasta.h fasta_seq.o seq.o encoded_sequence.o
	$(CXX) $(CXXFLAGS) -c $< 

read_fastq.o : read_fastq.cpp read_fastq.h fastq_seq.o seq.o encoded_sequence.o
	$(CXX) $(CXXFLAGS) -c $<

# test_seq : test_seq.cpp seq.o fasta_seq.o fastq_seq.o encoded_sequence.o
# 	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

seq.o : seq.cpp seq.h encoded_sequence.o 
	$(CXX) $(CXXFLAGS) -c $<

fasta_seq.o : fasta_seq.cpp fasta_seq.h seq.o
	$(CXX) $(CXXFLAGS) -c $<

fastq_seq.o : fastq_seq.cpp fastq_seq.h seq.o
	$(CXX) $(CXXFLAGS) -c $<

encoded_sequence.o : encoded_sequence.cpp encoded_sequence.h
	$(CXX) $(CXXFLAGS) -c $<



clean :
	rm -f *.o test_seq test_read_fasta
