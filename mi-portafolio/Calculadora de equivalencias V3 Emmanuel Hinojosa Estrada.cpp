# Project: Calculadora de equivalencias V2 Emmanuel Hinojosa Estrada
# Makefile created by Dev-C++ 5.11

CPP      = g++.exe
CC       = gcc.exe
WINDRES  = windres.exe
OBJ      = "Calculadora\ Equivalencias\ V2\ Emmanuel\ Hinojosa\ Estrada.o"
LINKOBJ  = "Calculadora Equivalencias V2 Emmanuel Hinojosa Estrada.o"
LIBS     = -L"C:/Program Files (x86)/Dev-Cpp/MinGW64/lib" -L"C:/Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib" -static-libgcc
INCS     = -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/include" -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include"
CXXINCS  = -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/include" -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include" -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include/c++"
BIN      = "Calculadora de equivalencias V2 Emmanuel Hinojosa Estrada.exe"
CXXFLAGS = $(CXXINCS) 
CFLAGS   = $(INCS) 
RM       = rm.exe -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

"Calculadora\ Equivalencias\ V2\ Emmanuel\ Hinojosa\ Estrada.o": Calculadora\ Equivalencias\ V2\ Emmanuel\ Hinojosa\ Estrada.cpp
	$(CPP) -c "Calculadora Equivalencias V2 Emmanuel Hinojosa Estrada.cpp" -o "Calculadora Equivalencias V2 Emmanuel Hinojosa Estrada.o" $(CXXFLAGS)
