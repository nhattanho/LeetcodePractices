CC=g++
CFLAGS=
DEPS=
PROGRAM=test
SOURCE=RevertList.cpp
OBJ=RevertList.o

#Generating the execute file base on file object"
$(PROGRAM): $(OBJ)
	#-o $@ means name of output is on the left side of : of line 9
	#$^ means name of object file is on the right side of : of line 9
	$(CC) -o $@ $^ $(CFLAGS)

%.o: $(SOURCE)
	$(CC) -c -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) $(PROGRAM)
