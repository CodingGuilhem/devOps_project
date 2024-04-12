# Compilator
CXX = g++
# Flags
CXXFLAGS = -Wall -Wextra -ansi -pedantic -std=c++11
# Linker flags
LDFLAGS =
# Hide compilation commands
MSQ = @
# Dependencies directory
DEPDIR = .dep
# Programs to generate
PROGS = test_seq

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
