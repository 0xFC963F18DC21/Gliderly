CC      = gcc
CFLAGS  = -std=c17 -O2
OBJS    = gliderly.o
TARGET  = gliderly
LDFLAGS = -lncurses

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(OBJS) $(TARGET)

rebuild: clean all

.PHONY: rebuild clean
