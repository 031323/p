#include "yugyntrm.h"

#include <stdio.h>

#define Y(a, b) (nvm(&s, a, b, 0))
#define M(a) murdgrhnm(&s, a)

int main()
{
	smbrnm s = nvsmbrnm();
	yugm a = Y(0, 0);
	M(a);
	yugm b = Y(0, 0);
	yugm c = Y(0, 0);
	yugm d = Y(0, 0);
	lekh(&s);
	yugm p = Y(a, Y(b, Y(a, Y(a, 0))));
	yugm r = Y(SMTVKM, Y(Y(Y(ANYKM, a), DISTRUPKM), Y(Y(ANYKM, c), Y(ANYKM, d))));
	yugm f = Y(ATIDESKM, Y(SMTVKM, Y(Y(Y(ANYKM, 0), DISTRUPKM), Y(Y(ANYKM, 0), Y(Y(YOGKM, Y(Y(ANYKM, r), SVYKM)), Y(YOGKM, Y(Y(ANYKM, ATIDESYKM), DKSINKM)))))));

	yugm n = nvm(&s, f, p, 1);
	M(n);
	//M(a);
	//M(a);
	//lekh(&s);
	lekh(&s);
	lekh(&s);
	//M(n);
	visrgh(&s);
	return 0;
}