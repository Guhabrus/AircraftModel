SRC_DIR = src/

# cpp файлы проектов

# Компоненты для вызова окна
CFILES += $(SRC_DIR)Window/Window.cpp

CFILES += $(SRC_DIR)Config/Config.cpp
CFILES += $(SRC_DIR)Window/Handle/CallHandler.cpp
CFILES += $(SRC_DIR)Window/Observer/Observer.cpp
CFILES += $(SRC_DIR)Model/Shader/Shader.cpp
CFILES += $(SRC_DIR)Model/Texture/Texture.cpp
CFILES += $(SRC_DIR)Model/Decorator/Decorator.cpp
CFILES += $(SRC_DIR)Model/Mesh/Mesh.cpp
CFILES += $(SRC_DIR)Model/3DModel/3DModel.cpp