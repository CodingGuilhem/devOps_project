.PHONY: all clean

# Variables
CXX = g++
MSG = @
CXXFLAGS = -Wall -Wextra -std=c++11
LDFLAGS = 
PROGS = test_sequence
SRC = seq.cpp encoded_sequence.cpp test_seq.cpp

# Targets
all: $(PROGS)

clean:
	$(MSG) "Cleaning..."
	$(MSG) $(RM) $(PROGS)

# Compilation rules
$(PROGS): $(SRC:.cpp=.o)
	$(MSG) "Linking $@..."
	$(MSG) $(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

%.o: %.cpp
	$(MSG) "Compiling $<..."
	$(MSG) $(CXX) $(CXXFLAGS) -c $< -o $@

# Dependencies
seq.o: seq.cpp seq.h encoded_sequence.h 
encoded_sequence.o: encoded_sequence.cpp encoded_sequence.h seq.h
fasta_seq.o: fasta_seq.cpp fasta_seq.h seq.h
fastq_seq.o: fastq_seq.cpp fastq_seq.h seq.h
test_seq.o: test_seq.cpp encoded_sequence.h fasta_seq.h fastq_seq.h seq.h