#include <stdio.h>
#include <stdlib.h>

unsigned long long read_longlong() {
    char buffer[32];
    fgets(buffer, 32, stdin);
    return strtoull(buffer, NULL, 16);
}

int main()
{
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);
	setbuf(stderr, NULL);
	fprintf(stderr, "puts @ %#lx\n", (unsigned long)puts);

	char buffer[32];
    unsigned long long choice, address, size;

	while(1) {
        printf("1. Read\n");
        printf("2. Write\n");
        printf("3. Trigger\n");
        printf("4. Exit\n");
        printf("> ");

		choice = read_longlong();
        switch(choice) {
            case 1:
                printf("Address: ");
                address = read_longlong();
                printf("Value: %p\n", *((void**)(address)));
                break;
            case 2:
                printf("Address: ");
                address = read_longlong();
                printf("Size: ");
                size = read_longlong();
                fread((void*)address, 1, size, stdin);
                break;
			case 3:
                // fprintf(stderr, "Error!\n");
                fflush(stderr);
				break;
            default:
                return 0;
        }
	}
}