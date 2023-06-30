CXX=g++
CFLAGS= -Wall -Wextra -Werror -g
EXEC= pong
LDFLAGS = -lSDL2 -lSDL2_image

SRC=	source/GameGest/InputHandler.cpp \
		source/GameGest/LoadParams.cpp	\
		source/GameGest/TextureManager.cpp \
		source/GameObject/SDLGameObject.cpp \
		source/GameStates/GameStateMachine.cpp \
		source/GameStates/MenuState.cpp	\
		source/GameStates/GameOverState.cpp \
		source/GameStates/PauseState.cpp \
		source/GameStates/PlayerState.cpp \
		source/Pong/Ennemy.cpp	\
		source/Pong/Game.cpp \
		source/Pong/MenuButton.cpp \
		source/Pong/Player.cpp \
		source/Pong/Vector2D.cpp\
		source/Pong/Background.cpp \
		source/Pong/Ball.cpp \
		pong.cpp

SRC_H=	inc/GameGest/InputHandler.h \
		inc/GameGest/LoadParams.h	\
		inc/GameGest/TextureManager.h \
		inc/GameObject/SDLGameObject.h \
		inc/GameStates/GameStateMachine.h \
		inc/GameStates/MenuState.h	\
		inc/GameStates/GameOverState.h \
		inc/GameStates/PauseState.h \
		inc/GameStates/PlayerState.h \
		inc/Pong/Ennemy.h	\
		inc/Pong/Game.h \
		inc/Pong/MenuButton.h \
		inc/Pong/Player.h \
		inc/Pong/Vector2D.h\
		inc/Pong/Background.h \
		inc/Pong/Ball.h

OBJ = $(SRC:.cpp=.o)

all: $(EXEC)

pong: $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o:.%c
	$(CXX) -o $@ -c $< $(CFLAGS)
pong.o : $(SRC_H)

clean:
	rm	$(OBJ)
re: clean all