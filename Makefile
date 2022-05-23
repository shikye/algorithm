VPATH:=linear_table/sequence:linear_table/linked_list
sequence_path=./linear_table/sequence
linked_path=./linear_table/linked_list

.PHONY: out main.o sequence.o linklist.o

out: main.o sequence.o linklist.o
	gcc -g main.o sequence.o linklist.o -o a.out

main.o:main.c
	gcc -g -c main.c -I $(sequence_path) -I $(linked_path) -I . -o main.o

sequence.o:sequence.c
	gcc -g -c $(sequence_path)/sequence.c -I $(sequence_path) -I . -o sequence.o

linklist.o:linklist.c
	gcc -g -c $(linked_path)/linklist.c -I $(linked_path) -I . -o linklist.o


.PHONY:clean

clean:
	rm *.o a.out
