  CC = gcc
  CCFLAGS  = -O3 -std=c99

  TARGET = pcea-cflp-ci
  FUNCTIONS = functions

  all: $(TARGET)

  $(TARGET): $(TARGET).c $(FUNCTIONS).c
	$(CC) $(CCFLAGS) -o $(TARGET) $(TARGET).c $(FUNCTIONS).c

  clean:
	$(RM) $(TARGET)
