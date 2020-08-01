/* github.com/031323/yugyntrm */

#include "yugyntrm.h"

#include <malloc.h>
#include <stdio.h>

#include <math.h>

typedef enum { PRAKRTM, YOGH, DISTRUPM } yugdrm;

typedef struct
{
	yugdrm drm;
	yugsnkya snkya;
	yugm svym;
	yugm dksinm;
} yugrupm;

typedef yugrupm * yugruppdm;

typedef struct
{
	yugruppdm pdm;
	yugsnkya vrima;
	yugm prtmriktm;
} smbrnm;

typedef smbrnm * smbrnpdm;

static yugm suddm(const * yugm);

smbrnm nvsmbrnm()
{
	smbrnm ynnvm = { 0, 0, 0 };
	return ynnvm;
}

int vrdnani = 0;

yugm nvm(smbrnpdm pdm)
{
	yugm prtmriktm = pdm->prtmriktm;
	if(prtmriktm == pdm->vrima) {
		yugsnkya vrima = prtmriktm ? prtmriktm * VRDNM : 1;
		yugruppdm nvpdm = malloc(vrima * sizeof(yugrupm));
		for(yugm ekm = 0; ekm < prtmriktm; ekm++) {
			nvpdm[ekm] = pdm->pdm[ekm];
		}
		for(yugm ekm = prtmriktm; ekm < vrima; ekm ++) {
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

void recnm(smbrnpdm pdm, yugm riktm)
{
	pdm->pdm[riktm].dksinm = pdm->prtmriktm;
	pdm->prtmriktm = riktm;
}

int main()
{
	smbrnm s = nvsmbrnm();
	int yugani = 10000;
	for(int i = 0; i < yugani; i++) {
		yugm p = nvm(&s);
		s.pdm[p].dksinm = i * 10;
	}
	for(int i = 0; i < 10; i++) {
		printf("%d\n", s.pdm[i].dksinm);
	}
	printf("%f\n", log2((float)yugani));
	return 0;
}