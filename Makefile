TARGET = executable

all: $(TARGET)

$(TARGET):
	g++ -Iheaders classes/variables.cpp classes/renderer.cpp classes/collision.cpp classes/shape2D.cpp classes/text.cpp classes/engine.cpp src/main.cpp -Iinclude -Llib -lsfml-graphics -lsfml-window -lsfml-system -o $(TARGET)

run:$(TARGET)
	./$(TARGET)