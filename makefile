a.out: main.o contact.o dummy_contact.o
	gcc -o a.out main.o contact.o dummy_contact.o
main.o: main.c
	gcc -c main.c
contact.o: contact.c
	gcc -c contact.c
dummy_contact.o: dummy_contact.c
	gcc -c dummy_contact.c
clear:
	rm *.out *.o
