CC := g++
CFLAGS = -g -Wall -c
LFLAGS = 
OBJS = test.o
TARGET = histogram
$(TARGET): $(OBJS)
	    $(CC) $(OBJS) -o $(TARGET) $(LFLAGS)
%.o: %.cc
	    $(CC) $(CFLAGS) $<
clean:
	    rm -f $(OBJS) $(TARGET)
