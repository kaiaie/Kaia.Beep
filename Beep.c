#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int
main(int argc, char *argv[]) {
	UINT uType = MB_OK;
	MessageBeep(uType);
	exit(EXIT_SUCCESS);
}

