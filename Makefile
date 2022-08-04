#подключаемые файлы
include Make_dir.mk

TARGET = aircraft_model

CC = g++

CFLAGS += -Wall -Wextra -Werror -std=c++17 

LIBS += -lboost_program_options -lGLEW -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lSOIL


BILD_DIR = obj/



CFILES += $(SRC_DIR)/main.cpp



all:
	mkdir -p obj
	$(CC) $(CFILES) $(LIBS) -o $(BILD_DIR)$(TARGET) $(CFLAGS) 


clean_dir:
	rm -Rf $(BILD_DIR)

clean:clean_dir