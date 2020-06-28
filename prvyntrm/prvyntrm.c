/* github.com/031323/prvyntrm */

#include "prvyntrm.h"

#include <malloc.h>
#include <stdio.h>

#include <math.h>

typedef enum { PRAKRTM, YOGH, DISTRUPM } prvdrma;

typedef struct
{
	prvdrma drma;
	prvsnkya snkya;
	prv svym;
	prv dksinm;
} prvrupm;

typedef prvrupm * prvruppdm;

typedef struct
{
	prvruppdm pdm;
	prvsnkya vrima;
	prv prtmriktm;
} smbrnm;

typedef smbrnm * smbrnpdm;

smbrnm nvsmbrnm()
{
	smbrnm ynnvm = { 0, 0, 0 };
	return ynnvm;
}

int vrdnani = 0;

prv nvm(smbrnpdm pdm)
{
	prv prtmriktm = pdm->prtmriktm;
	if(prtmriktm == pdm->vrima) {
		prvsnkya vrima = prtmriktm ? prtmriktm * VRDNM : 1;
		prvruppdm nvpdm = malloc(vrima * sizeof(prvrupm));
		for(prv ekm = 0; ekm < prtmriktm; ekm++) {
			nvpdm[ekm] = pdm->pdm[ekm];
		}
		for(prv ekm = prtmriktm; ekm < vrima; ekm ++) {
			nvpdm[ekm].dksinm = ekm + 1;	
		}
		pdm->pdm = nvpdm;
		pdm->vrima = vrima;
		vrdnani++;
		printf("%d vrdnani\n", vrdnani);
	}
	pdm->prtmriktm = pdm->pdm[prtmriktm].dksinm;
	return prtmriktm;
}

void recnm(smbrnpdm pdm, prv muktm)
{
	pdm->pdm[muktm].dksinm = pdm->prtmriktm;
	pdm->prtmriktm = muktm;
}

int main()
{
	smbrnm s = nvsmbrnm();
	int prvani = 10000000;
	for(int i = 0; i < prvani; i++) {
		nvm(&s);
	}
	printf("%f\n", log2((float)prvani));
	return 0;
}