build:
	gcc -Wfatal-errors \
	-std=c99 \
	./*.c \
	-I"C:\libsdl\include" \
	-L"C:\libsdl\lib" \
	-lmingw32 \
	-lSDLmain \
	-lSDL \
	-o Evil_bear.exe
	