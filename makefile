OBJ := $(patsubst %.c, %.o, $(wildcard *.c))
proj.exe: $(OBJ)
	gcc -o $@ $^
clean:
	rm *.exe *.o
