output: main.o Piano.o Keyboard.o Song.o FileManager.o Rest.o Note.o
    g++ main.o Piano.o Keyboard.o Song.o FileManager.o Rest.o Note.o -o piano

main.o: main.cpp
    g++ -c main.cpp

Piano.o: src/Piano.cpp include/Piano.hpp
    g++ -c Piano.cpp

Keyboard.o: src/Keyboard.cpp include/Keyboard.hpp
    g++ -c Keyboard.cpp

Song.o: src/Song.cpp include/Song.hpp
    g++ -c Song.cpp

FileManager.o: src/FileManager.cpp include/FileManager.hpp
    g++ -c FileManager.cpp

Rest.o: src/Rest.cpp include/Rest.hpp
    g++ -c Rest.cpp

Note.o: src/Note.cpp include/Note.hpp
    g++ -c Note.cpp

clean:
    rm *o piano