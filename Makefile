tetris5:tetris5.o genMino.o MinoS.o MinoS.h MinoI.o MinoI.h MinoL.o MinoL.h MinoT.o MinoT.h MinoJ.o MinoJ.h Mino.o Mino.h 
	g++ -o tetris5 tetris5.o genMino.o MinoS.o MinoI.o MinoL.o MinoT.o MinoJ.o Mino.o
tetris5.o:tetris5.cpp genMino.o genMino.h
	g++ -c tetris5.cpp
genMino.o:genMino.cpp genMino.h MinoS.o MinoS.h MinoI.o MinoI.h MinoL.o MinoL.h MinoT.o MinoT.h MinoJ.o MinoJ.h Mino.o Mino.h
	g++ -c genMino.cpp
MinoS.o:MinoS.cpp MinoS.h Mino.o
	g++ -c MinoS.cpp
MinoI.o:MinoI.cpp MinoI.h Mino.o
	g++ -c MinoI.cpp
MinoL.o:MinoL.cpp MinoL.h Mino.o
	g++ -c MinoL.cpp
MinoT.o:MinoT.cpp MinoT.h Mino.o
	g++ -c MinoT.cpp
MinoJ.o:MinoJ.cpp MinoJ.h Mino.o
	g++ -c MinoJ.cpp
Mino.o:Mino.cpp Mino.h
	g++ -c Mino.cpp

 
