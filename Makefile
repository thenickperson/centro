CC        = clang++
CFLAGS    = `pkg-config --cflags libnotifymm-1.0`
LDFLAGS   = `pkg-config --libs libnotifymm-1.0`

centro: libnotify_platform.o platform.o notifier.o example_service.o service.o
	$(CC) $^ -o centro $(LDFLAGS)

%.o: %.cpp %.h
	$(CC) -c $*.cpp -o $*.o $(CFLAGS)

clean:
	rm -f *.o centro
