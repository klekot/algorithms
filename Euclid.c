#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

long smallestCommonDivider(long a, long b)
{
    long res;
	long r = a % b;
	if (r == 0) {
		return b;
	} else {
		res = smallestCommonDivider(b, r);
	}

	return res;
}

bool isFloatInString(char *string)
{
    char *dot = ".";
    char *c = string;
    while (*c) {
        if (strchr(dot, *c)) {
            return true;
        }

        c++;
    }
    return false;
}

int main(int argc, char *argv[])
{
    long a = atol(argv[1]);
    long b = atol(argv[2]);
    long t, r;

    if (isFloatInString(argv[1]) || isFloatInString(argv[2]) || (a <= 0) || (b <= 0)) {
        printf("Допускаются только целые положительные числа больше нуля.\n");
        exit(EXIT_SUCCESS);
    }

	if (a < b) t = a; a = b; b = t;

	r = smallestCommonDivider(a, b);
	
	printf("Наименьший общий делитель: %ld\n", r);
	exit(EXIT_SUCCESS);
}