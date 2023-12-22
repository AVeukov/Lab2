EXECUTABLE = lab2

.PHONY: all clean run
# Phony purposes.
all: 
	$(EXECUTABLE)
clean: 
	rm $(EXECUTABLE) *.o
run: $(EXECUTABLE)
	./$(EXECUTABLE)
# Actual purposes.
CFLAGS = -Wall -Wextra -Werror	
main.o: main.c
	gcc -c main.c
functions.o: functions.c
	gcc -c functions.c
$(EXECUTABLE): main.o functions.o
	gcc main.o functions.o -o $(EXECUTABLE)
