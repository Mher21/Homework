TARGET=squaretarget
cc=g++
PATH_SRC=./src/
PATH_OBJ=./obj/
SRC=$(wildcards $(PATH_SRC)*.cpp)
OBJ=$(patsubs $(PATH_SRC)%.cpp,$(PATH_OBJ)%.o,$(SRC))
all: $(TARGET)
$(TARGET): $OBJ
	$(cc) $(OBJ) -o $(TARGET)
$(PATH_OBJ)%.o : $(PATH_SRC)%.cpp
	$(cc) -c $ < -o $@
# main.o: main.cpp
# 	$(cc) -c main.cpp -o main.o
# sq.o: square.cpp
# 	$(cc) -c square.cpp -o sq.o
# su.o: sum.cpp
# 	$(cc) -c sum.cpp -o su.o 
# mi.o: min.cpp
# 	$(cc) -c min.cpp -o mi.o   
clear:
	rm -f *.o $(TARGET)
install: 
	sudo install ./$(TARGET) /usr/local/bin
uninstall: 
	sudo rm /usr/local/bin/$(TARGET)