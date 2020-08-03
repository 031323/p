/* github.com/031323/yugyntrm */

#include "yugyntrm.h"

#include <malloc.h>
#include <stdio.h>

#include <math.h>

#define DISTRUPKM 1
#define SVYKM 2
#define DKSINKM 3
#define ATIDESYKM 4
#define SMTVKM 5
#define ATIDESKM 6
#define YOGKM 7
#define ANYKM 8

#define RUPM(smbrnpdm, yugm) (smbrnpdm->pdm[yugm])

static yugm suddm(const smbrnpdm, const yugpdm, const yugm);

/* = malloc */
static yugm nvyugm(const smbrnpdm pdm)
{
	const yugm prtmriktm = pdm->prtmriktm;
	if(prtmriktm == pdm->vrima) {
		const yugsnkya vrima = prtmriktm ? prtmriktm * VRDNM : 1;
		const yugruppdm nvpdm = malloc(vrima * sizeof(yugrupm));
		for(yugm ekm = 0; ekm < prtmriktm; ekm++) {
			nvpdm[ekm] = RUPM(pdm, ekm);
		}
		for(yugm ekm = prtmriktm; ekm < vrima; ekm ++) {
			nvpdm[ekm].dksinm = ekm + 1;	
		}
		pdm->pdm = nvpdm;
		pdm->vrima = vrima;

#ifdef PRIKSNM
		printf("%d vrima\n", vrima);
#endif

	}
	pdm->prtmriktm = RUPM(pdm, prtmriktm).dksinm;
	return prtmriktm;
}
/* = free */
static void recnm(const smbrnpdm pdm, const yugm riktm)
{
	RUPM(pdm, riktm).dksinm = pdm->prtmriktm;
	pdm->prtmriktm = riktm;
}

static void atmksyh(const smbrnpdm, const yugm);

static void visvangksyh(const smbrnpdm pdm, const yugm kspyitvym)
{
	if(kspyitvym > 8) {
		atmksyh(pdm, RUPM(pdm, kspyitvym).svym);
		atmksyh(pdm, RUPM(pdm, kspyitvym).dksinm);
	}
}

static void atmksyh(const smbrnpdm pdm, const yugm kspyitvym)
{
	if(kspyitvym > 8 && !--(RUPM(pdm, kspyitvym).snkya)) {
		visvangksyh(pdm, kspyitvym);
		recnm(pdm, kspyitvym);
	}
}

static void vrdnm(const smbrnpdm pdm, const yugm vrditvym)
{
	if(vrditvym > 8)
		RUPM(pdm, vrditvym).snkya++;
}

static yugm sndanm(const smbrnpdm pdm, yugm nivesnm,
	const yugdrm drm, const yugm svym, const yugm dksinm)
{
	if(nivesnm > 8)
		visvangksyh(pdm, nivesnm);
	else nivesnm = nvyugm(pdm);
	RUPM(pdm, nivesnm).drm = drm;
	vrdnm(pdm, svym);
	vrdnm(pdm, dksinm);
	RUPM(pdm, nivesnm).svym = svym;
	RUPM(pdm, nivesnm).dksinm = dksinm;
	return nivesnm;
}

smbrnm nvsmbrnm()
{
	smbrnm nvmsmbrnm = { 0, 0, 0 };
	const smbrnpdm nvpdm = &nvmsmbrnm;
	for(yugsnkya i = 0; i <= 8; i++) {
		sndanm(nvpdm, 0, PRAKRTM, 0, 0);
	}
	nvmsmbrnm.murda = 0;
	return nvmsmbrnm;
}

yugm nvm(const smbrnpdm pdm, const yugm prtmm, const yugm dvitiym, const yugm trtiym, dvym yogtvm, dvym svytvm)
{
	yugdrm cturtdrm = PRAKRTM;
	if(yogtvm)
		cturtdrm = YOGH;
	const yugm cturtm = sndanm(pdm, 0, cturtdrm, dvitiym, trtiym);
	yugm nvmurda;
	if(svytvm)
		nvmurda = sndanm(pdm, 0, PRAKRTM, cturtm, prtmm);
	else nvmurda = sndanm(pdm, 0, PRAKRTM, prtmm, cturtm);
	RUPM(pdm, nvmurda).snkya = 1;
	atmksyh(pdm, pdm->murda);
	pdm->murda = nvmurda;
	return nvmurda;
}

yugm svym(const smbrnpdm pdm, const yugm ekm)
{
	return suddm(pdm, &RUPM(pdm, ekm).svym, 0);
}

yugm dksinm(const smbrnpdm pdm, const yugm ekm)
{
	return suddm(pdm, &RUPM(pdm, ekm).dksinm, 0);
}

#ifdef PRIKSNM
static void srtlekh(const smbrnpdm pdm, const yugm murda, char * srnm)
{
	char * svysrnm = malloc(strlen(srnm) + strlen("|") + 1);
	char * dksinsrnm = malloc(strlen(srnm) + 1);
	char * stmbh = "│";
	int i;
	for(i = 0; i < strlen(srnm); i++) {
		svysrnm[i] = srnm[i];
		dksinsrnm[i] = srnm[i];
	}
	dksinsrnm[i] = ' ';
	dksinsrnm[i + 1] = 0;
	for(int j = 0; j < strlen(stmbh); j++, i++) {
		svysrnm[i] = stmbh[j];
	}
	svysrnm[i] = 0;
	printf("%d\n", murda);
	if(murda > 8) {
		printf("%s├", srnm);
		srtlekh(pdm, svym(pdm, murda), svysrnm);
		printf("%s└", srnm);
		srtlekh(pdm, dksinm(pdm, murda), dksinsrnm);
	}
	free(svysrnm);
	free(dksinsrnm);
}

void lekh(const smbrnpdm pdm)
{
	char * srnani = "";
	srtlekh(pdm, pdm->murda, srnani);
}
#endif

void visrgh(const smbrnpdm pdm)
{
#ifdef PRIKSNM
	for(yugsnkya i = 0; i <= 8; i++) {
		printf("%d ", RUPM(pdm, i).snkya);
	}
	atmksyh(pdm, pdm->murda);
	yugm riktm = pdm->prtmriktm;
	yugsnkya i = 0;
	while(riktm != pdm->vrima) {
		i++;
		riktm = RUPM(pdm, riktm).dksinm;
	}
	printf("\n%d\n", pdm->vrima - i - 9);
#else
	free(pdm->pdm);
#endif
}

static void distrupm(const smbrnpdm pdm, const yugm desym, const yugm distm)
{
	sndanm(pdm, desym, DISTRUPM, distm, 0);
}

static yugm suddm(const smbrnpdm pdm, const yugpdm sodypdm, yugm atidesh)
{
	yugm sodym;
	yugdrm drm;
	while ((sodym = *sodypdm) && (drm = pdm->pdm[sodym].drm) != PRAKRTM) {
		if (drm == YOGH || (drm == ATIDESH && (atidesh = RUPM(pdm, sodym).svym))) {
			yugm yogh;
			if(atidesh)
				yogh = RUPM(pdm, sodym).dksinm;
			else yogh = sodym;
			const yugm svym = suddm(pdm, &RUPM(pdm, yogh).svym, 0);
			if (!svym)
				distrupm(pdm, sodym, 0);
			else if (svym == DISTRUPKM)
				distrupm(pdm, sodym, RUPM(pdm, yogh).dksinm);
			else if (svym == SVYKM) {
				const yugm dksinm = suddm(pdm, &RUPM(pdm, yogh).dksinm, 0);
				if (!dksinm)
					distrupm(pdm, sodym, 0);
				else distrupm(pdm, sodym, RUPM(pdm, dksinm).svym);
			}
			else if (svym == DKSINKM) {
				const yugm dksinm = suddm(pdm, &RUPM(pdm, yogh).dksinm, 0);
				if (!dksinm)
					distrupm(pdm, sodym, 0);
				else distrupm(pdm, sodym, RUPM(pdm, dksinm).dksinm);	
			}
			else if (svym == ATIDESYKM)
				sndanm(pdm, yogh, YOGH, atidesh, RUPM(pdm, yogh).dksinm);
			else {
				const yugm svysvym = suddm(pdm, &RUPM(pdm, svym).svym, 0);
				if(svysvym == SMTVKM) {
					yugm nvyogh = sndanm(pdm, 0, YOGH, RUPM(pdm, svym).dksinm, RUPM(pdm, yogh).dksinm);
					RUPM(pdm, nvyogh).snkya = 1;
					vrdnm(pdm, nvyogh);
					if (!suddm(pdm, &nvyogh, atidesh))
						distrupm(pdm, sodym, 0);
					else {
						const yugm nvdksinm = suddm(pdm, &RUPM(pdm, nvyogh).dksinm, 0);
						if (! nvdksinm)
							distrupm(pdm, sodym, 0);
						else {
							const yugm nvsvym = suddm(pdm, &RUPM(pdm, nvyogh).svym, 0);
							if (!nvsvym)
								distrupm(pdm, sodym, 0);
							else {
								if (!nvsvym || suddm(pdm, &RUPM(pdm, nvsvym).svym, 0) == suddm(pdm, &RUPM(pdm, nvsvym).svym, 0))
									distrupm(pdm, sodym, RUPM(pdm, nvdksinm).svym);
								else
									distrupm(pdm, sodym, RUPM(pdm, nvdksinm).dksinm);
							}
						}
					}
					atmksyh(pdm, nvyogh);
				} else if (svysvym == ATIDESKM) {
					const yugm svydksinm = RUPM(pdm, svym).dksinm;
					if(yogh != sodym) {
						sndanm(pdm, sodym, ATIDESH, svydksinm, yogh);
						sndanm(pdm, yogh, YOGH, svydksinm, RUPM(pdm, yogh).dksinm);
					}
					else {
						const yugm nvyogh = sndanm(pdm, 0, YOGH, svydksinm, RUPM(pdm, yogh).dksinm);
						sndanm(pdm, sodym, ATIDESH, svydksinm, nvyogh);
					}
				} else if (svysvym == YOGKM) {
					const yugm svydksinm = suddm(pdm, &RUPM(pdm, svym).dksinm, 0);
					if (!svydksinm)
						distrupm(pdm, sodym, 0);
					else {
						const yugm dksinm = RUPM(pdm, yogh).dksinm;
						yugm svyyogh = sndanm(pdm, 0, YOGH, RUPM(pdm, svydksinm).svym, dksinm);
						yugm dksinyogh = sndanm(pdm, 0, YOGH, RUPM(pdm, svydksinm).dksinm, dksinm);
						if (atidesh) {
							svyyogh = sndanm(pdm, 0, ATIDESH, atidesh, svyyogh);
							dksinyogh = sndanm(pdm, 0, ATIDESH, atidesh, dksinyogh);
						}
						sndanm(pdm, yogh, YOGH, svyyogh, dksinyogh);
					}
				} else if (svysvym == ANYKM)
					distrupm(pdm, sodym, RUPM(pdm, svym).dksinm);
				else {
					const yugm dksinm = RUPM(pdm, yogh).dksinm;
					yugm svyyogh = sndanm(pdm, 0, YOGH, svysvym, dksinm);
					yugm dksinyogh = sndanm(pdm, 0, YOGH, RUPM(pdm, svym).dksinm, dksinm);
					if (atidesh) {
						svyyogh = sndanm(pdm, 0, ATIDESH, atidesh, svyyogh);
						dksinyogh = sndanm(pdm, 0, ATIDESH, atidesh, dksinyogh);
					}
					sndanm(pdm, sodym, PRAKRTM, svyyogh, dksinyogh);
				}
			}
			
		} else if (drm == DISTRUPM) {
			const yugm distm = RUPM(pdm, sodym).svym;
			vrdnm(pdm, distm);
			atmksyh(pdm, sodym);
			*sodypdm = distm;
		}
	}
	return sodym;
}