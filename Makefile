des: des.o Queue.o Kiosk.o Customer.o List.o node.o
	gcc -o des des.o Queue.o Kiosk.o Customer.o List.o node.o

des.o: des.c Queue.h Kiosk.h Customer.h
	gcc -c des.c

Queue.o: Queue.c Queue.h List.h node.h
	gcc -c Queue.c

Kiosk.o: Kiosk.c Kiosk.h Customer.h
	gcc -c Kiosk.c

Customer.o: Customer.c Customer.h
	gcc -c Customer.c

List.o: List.c List.h node.h
	gcc -c List.c

node.o: node.c node.h
	gcc -c node.c

clean:
	rm *.o des
