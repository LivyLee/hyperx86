
TARGET		= hyperx86
OBJECTS		= main.o ram_emulation.o cpu.o biosldr.o
CFLAGS		= -O2 -g -pipe -march=native
LDFLAGS		=
CPPFLAGS	= -I../include
CC		= clang

all:	$(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<
	
clean:
	rm -f $(OBJECTS) $(TARGET) *.dSYM
