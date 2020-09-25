#ifndef _MTIME
#define _MTIME

#include <stdio.h>
#include <windows.h>

class Mtime{
public:
	/* retorna "a - b" en segundos */
	double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);
};
#endif
