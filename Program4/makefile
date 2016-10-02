OBJECTS = Term.o Autocomplete.o main.o
        #(listing all of your object files here, seperated by space)
Project3: $(OBJECTS)
	g++ $^ -o Project3
%.o: %.cpp
	g++ -c $< -o $@
HEADERS = Autocomplete.h Term.h
        #(listing all header files here, seperated by spaces)
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@
clean:
	rm -i *.o project2
