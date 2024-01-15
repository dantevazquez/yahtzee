mac:
	clang++ -std=c++11 -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL ../lib/libraylib.a ../_main.cpp ../gameManager.cpp ../scoreBoard.cpp ../scoreBoardButton.cpp ../diceArray.cpp ../buttons.cpp ../dice.cpp ../buttonLocation.cpp ../sounds.cpp -o yahtzee

windows:
	g++ ../_main.cpp ../gameManager.cpp ../scoreBoard.cpp ../scoreBoardButton.cpp ../diceArray.cpp ../buttons.cpp ../dice.cpp ../buttonLocation.cpp ../sounds.cpp  -o yahtzee.exe -O2 -Wall -Wno-missing-braces -I ../include/ -L ../lib/ -lraylib -lopengl32 -lgdi32 -lwinmm