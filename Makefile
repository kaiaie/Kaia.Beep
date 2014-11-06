SRC := Beep.c
RC := Resources.rc
OBJ := $(patsubst %.c,%.o,$(SRC)) $(patsubst %.rc,%.o,$(RC)) 
EXE := Beep.exe

.PHONY: all
all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(OBJ)

-include $(SRC:.c=.d)

%.d: %.c
	gcc -MM -MG $< > $@

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

%.o: %.rc
	windres -i $< -o $@

.PHONY: clean
clean:
	CMD /C DEL /F/Q $(EXE) *.o *.d

