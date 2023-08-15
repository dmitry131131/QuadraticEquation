/* Head file with prototypes and preprocessor dirictives */

#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
	#define _CRT_SECURE_NO_WARNINGS
	#pragma warning(disable:4996)
#endif

void solving(double a, double b, double c);         // solving finction prototype