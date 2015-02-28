CC=g++

CXXFLAGS= -g 
LDFLAGS= -g

MST: mst.cc 
	$(CC) $(CXXFLAGS) -o MST mst.cc

.PHONY:clean

clean:
	@rm -f *.o
	@rm -f MST
	@rm -fr MST.dSYM
