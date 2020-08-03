#include "yugyntrm.h"

#include <stdio.h>

int main()
{
	smbrnm s = nvsmbrnm();
	yugm m = nvm(&s, 0, 1, 2, 0, 1);
	nvm(&s, m, m, 0, 0, 0);
	lekh(&s);
	visrgh(&s);
	return 0;
}