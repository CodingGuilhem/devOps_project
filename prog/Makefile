# Compiler
CXX = g++
# Compilation options
CXXFLAGS = -Wall -Wextra -ansi -pedantic -std=c++11
# Linking options
LDFLAGS =
# Hide compilation commands
MSQ = @
# Dependencies directory
DEPDIR = .dep
# Default project files
P = seq test_seq

# Files sources
seq_SRC = seq.cpp seq.h

test_seq_SRC = test_seq.cpp seq.h



# Clean	
clean:
	@echo "Cleaning the dependencies files"
	$(MSQ)rm -f $(DEPDIR)
	@echo "Cleaning the $(P) project"
	$(MSQ)rm -f $(P) $(P:=.o) $(P:=.d)


