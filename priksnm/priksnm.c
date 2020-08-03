#include "yugyntrm.h"

int main()
{
	smbrnm s = nvsmbrnm();
	for(int i = 0; i < 4096; i++)
		sndanm(&s, 0, PRAKRTM, 0, 0);
	return 0;
}