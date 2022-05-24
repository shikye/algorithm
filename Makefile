VPATH:=linear_table/sequence:linear_table/linked_list:linear_table/Stack_seq:linear_table/Stack_linked
sequence_path=./linear_table/sequence
linked_path=./linear_table/linked_list
stack_line_path=./linear_table/Stack_seq
stack_linked_path=./linear_table/Stack_linked


.PHONY: out main.o sequence.o linklist.o

out: main.o sequence.o linklist.o Stack_line.o Stack_linked.o
	gcc -g main.o sequence.o linklist.o Stack_line.o Stack_linked.o -o a.out 

main.o:main.c
	gcc -g -c main.c -I $(sequence_path) -I $(linked_path) -I $(stack_line_path) -I $(stack_linked_path) -I . -o main.o

sequence.o:sequence.c
	gcc -g -c $(sequence_path)/sequence.c -I $(sequence_path) -I . -o sequence.o

linklist.o:linklist.c
	gcc -g -c $(linked_path)/linklist.c -I $(linked_path) -I . -o linklist.o

Stack_line.o:Stack_line.c
	gcc -g -c $(stack_line_path)/Stack_line.c -I $(stack_line_path) -I . -o Stack_line.o

Stack_linked.o:Stack_linked.c
	gcc -g -c $(stack_linked_path)/Stack_linked.c -I $(stack_linked_path) -I . -o Stack_linked.o


.PHONY:clean

clean:
	rm *.o a.out
