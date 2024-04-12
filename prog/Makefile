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

# Sources for test_seq
test_seq_SOURCES = \
  seq.cpp seq.h \
  fasta_seq.cpp fasta_seq.h \
  fastq_seq.cpp fastq_seq.h \	
  test_seq.cpp

# Create the dependency directory if it does not exist
ifeq ($(wildcard $(DEPDIR)), )
	all : $(DEPDIR)
		  $(MAKE)
else # Else generate the programs including the dependencies
	all : $(PROGS)
	include $(wildcard $(DEPDIR)/*.d)
endif

define make_depend =
	
  