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
P = read_seq

# Files dependencies





# Clean	
clean:
	@echo "Cleaning the dependencies files"
	$(MSQ)rm -f $(DEPDIR)
	@echo "Cleaning the $(P) project"
	$(MSQ)rm -f $(P) $(P:=.o) $(P:=.d)


