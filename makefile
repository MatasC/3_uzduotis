vector: vector.o generating.o Time.o
	g++ -o vector Bandymas.cpp vector.o Time.o
	g++ -o generavimas generavimas.cpp generating.o
	./generavimas
	./vector
valymas:
	rm *.o blogi.txt geri.txt mokiniai1.txt mokiniai2.txt mokiniai3.txt mokiniai4.txt mokiniai5.txt vector generavimas