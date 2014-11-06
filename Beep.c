#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/** Prints usage information */
void usage(const char *appName, FILE *out);

int
main(int argc, char *argv[]) {
	UINT uType = MB_OK;
	if (argc > 1) {
		if (strcmp(argv[1], "/?") == 0 || strcmp(argv[1], "-?") == 0) {
			usage(argv[0], stdout);
			exit(EXIT_SUCCESS);
		}
		else if (strcasecmp(argv[1], "/e") == 0 || strcasecmp(argv[1], "-e") == 0) {
			uType = MB_ICONHAND;
		}
		else if (strcasecmp(argv[1], "/w") == 0 || strcasecmp(argv[1], "-w") == 0) {
			uType = MB_ICONEXCLAMATION;
		}
		else if (strcasecmp(argv[1], "/i") == 0 || strcasecmp(argv[1], "-i") == 0) {
			uType = MB_ICONASTERISK;
		}
		else {
			usage(argv[0], stderr);
			exit(EXIT_FAILURE);
		}
	}
	MessageBeep(uType);
	exit(EXIT_SUCCESS);
}

void
usage(const char *appName, FILE *out) {
	fprintf(out, "%s - Generates a system alert sound.\n", appName);
	fprintf(out, "Usage: %s [/E | /W | /I]\n", appName);
	fprintf(out, "\t/E - Plays the system error sound\n");
	fprintf(out, "\t/W - Plays the system warning sound\n");
	fprintf(out, "\t/I - Plays the system information sound\n");
	fprintf(out, "If no argument is given, the default system sound is played.\n");
}
