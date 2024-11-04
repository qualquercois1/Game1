# Nome do compilador
CC = gcc

# Opções do compilador
CFLAGS = -Wall

# Arquivo executável final
TARGET = main

# Arquivos fonte
SRCS = main.c menu.c play.c

# Arquivos objeto
OBJS = $(SRCS:.c=.o)

# Regras de compilação
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compila cada arquivo .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa os arquivos objeto e o executável
clean:
	rm -f $(OBJS) $(TARGET)
