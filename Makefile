VPATH:=linear_table/sequence
sequence_path=./linear_table/sequence

.PHONY: out main.o sequence.o

out: main.o sequence.o
	gcc -g main.o sequence.o -o a.out

main.o:main.c
	gcc -g -c main.c -I $(sequence_path) -I . -o main.o

sequence.o:sequence.c
	gcc -g -c $(sequence_path)/sequence.c -I $(sequence_path) -I . -o sequence.o


.PHONY:clean

clean:
	rm *.o a.out
