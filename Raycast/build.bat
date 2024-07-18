set files=src\*.c 
set lib=.\lib
set include=.\include 
set flags=-Wall -ggdb3 -o0
set link=-lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image
set name=Game
gcc %files% -I%include% -L%lib% %link% %flags% -o %name%
