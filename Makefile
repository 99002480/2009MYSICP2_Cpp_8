all:all.out
all.out:projectmini.o
	g++ $^ -o $@ 
%.o:%.cpp
	g++ $< -c
clean:  
	rm -rf *.o *.out
run:all.out
	./all.out
