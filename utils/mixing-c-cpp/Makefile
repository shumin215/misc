TARGET=test

CC=/usr/bin/gcc
CXX=/usr/bin/g++

CC_OBJS=app.o
CXX_OBJS=lib.o main.o

CC_SRC=app.c
CXX_SRC=lib.cpp main.cpp

all: $(TARGET)

$(TARGET): $(CC_OBJS) $(CXX_OBJS)
	$(CXX) -o $@ $^

$(CC_OBJS): $(CC_SRC)
	$(CC) -c $^

$(CXX_OBJS): $(CXX_SRC)
	$(CXX) -c $^

clean:
	rm -rf $(TARGET) $(CC_OBJS) $(CXX_OBJS)
