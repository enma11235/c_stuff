#include "chap03.h"

#if defined(_WIN32)
    WSADATA d;
    if (WSAStartup(MAKEWORD(2,2), &d)) {
	fprintf(stderr, "Failed to initialize.\n");
	return 1;
    }
#endif
