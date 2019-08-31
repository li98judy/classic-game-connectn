connectn.out: winner.o makeboard.o connectn.o
	gcc -g -Wall -Werror -o connectn.out winner.o makeboard.o connectn.o
	
winner.o: winner.c winner.h
	gcc -g -Wall -Werror -c winner.c
	
makeboard.o: makeboard.c makeboard.h 
	gcc -g -Wall -Werror -c makeboard.c
	
connectn.o: connectn.c makeboard.h
	gcc -g -Wall -Werror -c connectn.c
	
clean:
	rm -fr *.o *.out