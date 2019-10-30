CC=g++
CFLAGS=-std=c++17 -MMD -MP -g -O0

IDIR=.
SDIR=.
ODIR=obj

SRC=$(wildcard $(SDIR)/*.cpp)

OBJ=$(patsubst $(SDIR)/%.cpp,$(ODIR)/%.o,$(SRC))

DEP=$(wildcard $(IDIR)/*.h)

EXE=run

all: $(OBJ) $(EXE)

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LIBS)

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

-include $(wildcard $(ODIR)/*.d)

.PHONY: clean
clean:
	-rm -f $(ODIR)/*.o $(ODIR)/*.d *~ core $(IDIR)/*~ rel