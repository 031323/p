/* github.com/031323/yugyntrm */

#include "yugyntrm.h"

#include <malloc.h>

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define RUPM(smbrnpdm, yugm) (smbrnpdm->pdm[yugm])

#define UTTRRIKTM(smbrnpdm, riktm) (RUPM(smbrnpdm, riktm).dksinm)

static yugm suddm(const smbrnpdm, const yugpdm, const yugm);

static void riktopkrmh(const smbrnpdm pdm, const yugm purvym, const yugm prmm)
{
	for(yugsnkya snkya = purvym; snkya < prmm; snkya++) {
		UTTRRIKTM(pdm, snkya) = snkya + 1;
	}
}

/* = malloc */
static yugm nvyugm(const smbrnpdm pdm)
{
	const yugm prtmriktm = pdm->prtmriktm;
	if(prtmriktm == pdm->vrima) {
		const yugsnkya vrima = prtmriktm ? prtmriktm * VRDNM : 1;
		const yugruppdm nvpdm = malloc(vrima * sizeof(yugrupm));
		for(yugsnkya snkya = 0; snkya < prtmriktm; snkya++) {
			nvpdm[snkya] = RUPM(pdm, snkya);
		}
		pdm->pdm = nvpdm;
		riktopkrmh(pdm, prtmriktm, vrima);
		pdm->vrima = vrima;

#ifdef PRIKSNM
		printf("%d vrima\n", vrima);
#endif

	}
	pdm->prtmriktm = UTTRRIKTM(pdm, prtmriktm);
	return prtmriktm;
}

/* = free */
static void recnm(const smbrnpdm pdm, const yugm riktm)
{
	UTTRRIKTM(pdm, riktm) = pdm->prtmriktm;
	RUPM(pdm, riktm).drm = RIKTM;
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
	vrdnm(pdm, svym);
	vrdnm(pdm, dksinm);
	if(nivesnm > 8)
		visvangksyh(pdm, nivesnm);
	else nivesnm = nvyugm(pdm);
	RUPM(pdm, nivesnm).drm = drm;
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

yugm nvm(const smbrnpdm pdm, const yugm svym, const yugm dksinm, const dvym yogtvm)
{
	yugdrm nvdrm = PRAKRTM;
	if(yogtvm)
		nvdrm = YOGH;
	yugm nvmyugm = sndanm(pdm, 0, nvdrm, svym, dksinm);
	yugm nvmurda = sndanm(pdm, 0, PRAKRTM, nvmyugm, pdm->murda);
	murdgrhnm(pdm, nvmurda);
	return suddm(pdm, &RUPM(pdm, nvmurda).svym, 0);
}

void murdgrhnm(const smbrnpdm pdm, const yugm nvmurda)
{
	vrdnm(pdm, nvmurda);
	atmksyh(pdm, pdm->murda);
	pdm->murda = nvmurda;
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
	char * stmbh = "│";
	char * svysrnm = malloc(strlen(srnm) + strlen(stmbh) + 1);
	char * dksinsrnm = malloc(strlen(srnm) + 2);
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
	switch(murda) {
		case 1: printf("SVH"); break;
		case 2: printf("SVYH"); break;
		case 3: printf("DKSINH"); break;
		case 4: printf("STANI"); break;
		case 5: printf("VICETAH"); break;
		case 6: printf("ADESH"); break;
		case 7: printf("YNTA"); break;
		case 8: printf("DRUVH"); break;
		default: printf("%d", murda);
	}
	printf(": %d\n", RUPM(pdm, murda).snkya);
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
	srtlekh(pdm, suddm(pdm, &pdm->murda, 0), srnani);
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
#endif
	free(pdm->pdm);
}

static char snkyakrmh()
{
	uint16_t snkya = 1;
	return *(char *)(&snkya);
}

static void yugsnkyaprivrtnm(const yugpdm pdm, char * anym, const dvym gtih)
{
	for(int i = 0; i < sizeof(yugsnkya); i++, anym++) {
		int j = snkyakrmh() ? i : sizeof(yugsnkya) - i;
		if(gtih)
			*anym = *(((char *) pdm) + j);
		else
			*(((char *) pdm) + j) = *anym;
	}	
}

static void yugsnkyagopnm(yugsnkya snkya, void(*gopah)(char, void *), void * anvyh)
{
	char yugsnkyapdm[sizeof(yugsnkya)];
	yugsnkyaprivrtnm(&snkya, yugsnkyapdm, 1);
	for(int i = 0; i < sizeof(yugsnkya); i++) {
		gopah(yugsnkyapdm[i], anvyh);
	}
}

static yugsnkya yugsnkyaropnm(char(*ropkm)(void *), void * anvyh)
{
	yugsnkya snkya;
	char yugsnkyapdm[sizeof(yugsnkya)];
	for(int i = 0; i < sizeof(yugsnkya); i++) {
		yugsnkyapdm[i] = ropkm(anvyh);
	}
	yugsnkyaprivrtnm(&snkya, yugsnkyapdm, 0);
	return snkya;
}

void gopnm(const smbrnpdm pdm, void(*gopah)(char, void *), void * anvyh)
{
	yugsnkyagopnm(pdm->vrima, gopah, anvyh);
	yugsnkyagopnm(pdm->prtmriktm, gopah, anvyh);
	yugsnkyagopnm(pdm->murda, gopah, anvyh);
	for(yugsnkya snkya = 0; snkya < pdm->vrima; snkya++) {
		gopah((char) RUPM(pdm, snkya).drm, anvyh);
		yugsnkyagopnm(RUPM(pdm, snkya).snkya, gopah, anvyh);
		yugsnkyagopnm(RUPM(pdm, snkya).svym, gopah, anvyh);
		yugsnkyagopnm(RUPM(pdm, snkya).dksinm, gopah, anvyh);
	}
}

smbrnm ropnm(char(*ropkm)(void *), void * anvyh)
{
	smbrnm ropitm;
	ropitm.vrima = yugsnkyaropnm(ropkm, anvyh);
	ropitm.prtmriktm = yugsnkyaropnm(ropkm, anvyh);
	ropitm.murda = yugsnkyaropnm(ropkm, anvyh);
	ropitm.pdm = malloc(ropitm.vrima * sizeof(yugrupm));
	const smbrnpdm ropitpdm = &ropitm;
	for(yugsnkya snkya = 0; snkya < ropitm.vrima; snkya++) {
		RUPM(ropitpdm, snkya).drm = (yugdrm) ropkm(anvyh);
		RUPM(ropitpdm, snkya).snkya = yugsnkyaropnm(ropkm, anvyh);
		RUPM(ropitpdm, snkya).svym = yugsnkyaropnm(ropkm, anvyh);
		RUPM(ropitpdm, snkya).dksinm = yugsnkyaropnm(ropkm, anvyh);
	}
	return ropitm;
}

static void distrupm(const smbrnpdm pdm, const yugm desym, const yugm distm)
{
	sndanm(pdm, desym, DISTRUPM, distm, 0);
}

static yugm suddm(const smbrnpdm pdm, const yugpdm sodypdm, yugm atidesh)
{
	yugm sodym;
	yugdrm drm;
	while ((sodym = *sodypdm) > 8 && (drm = RUPM(pdm, sodym).drm) != PRAKRTM) {
		if (drm != DISTRUPM) {
			yugm yogh;
			if(drm == ATIDESH) {
				atidesh = RUPM(pdm, sodym).svym;
				yogh = RUPM(pdm, sodym).dksinm;
			}
			else yogh = sodym;
			const yugm svym = suddm(pdm, &RUPM(pdm, yogh).svym, 0);
			if (!svym)
				distrupm(pdm, sodym, 0);
			else if (svym == SVH)
				distrupm(pdm, sodym, RUPM(pdm, yogh).dksinm);
			else if (svym == SVYH) {
				const yugm dksinm = suddm(pdm, &RUPM(pdm, yogh).dksinm, 0);
				if (!dksinm)
					distrupm(pdm, sodym, 0);
				else distrupm(pdm, sodym, RUPM(pdm, dksinm).svym);
			}
			else if (svym == DKSINH) {
				const yugm dksinm = suddm(pdm, &RUPM(pdm, yogh).dksinm, 0);
				if (!dksinm)
					distrupm(pdm, sodym, 0);
				else distrupm(pdm, sodym, RUPM(pdm, dksinm).dksinm);	
			}
			else if (svym == STANI)
				sndanm(pdm, yogh, YOGH, atidesh, RUPM(pdm, yogh).dksinm);
			else {
				const yugm svysvym = suddm(pdm, &RUPM(pdm, svym).svym, 0);
				if(svysvym == VICETAH) {
					yugm nvyogh = sndanm(pdm, 0, YOGH, RUPM(pdm, svym).dksinm, RUPM(pdm, yogh).dksinm);
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
								if (!nvsvym || suddm(pdm, &RUPM(pdm, nvsvym).svym, 0) == suddm(pdm, &RUPM(pdm, nvsvym).dksinm, 0))
									distrupm(pdm, sodym, RUPM(pdm, nvdksinm).svym);
								else
									distrupm(pdm, sodym, RUPM(pdm, nvdksinm).dksinm);
							}
						}
					}
					atmksyh(pdm, nvyogh);
				} else if (svysvym == ADESH) {
					const yugm svydksinm = RUPM(pdm, svym).dksinm;
					if(yogh != sodym) {
						sndanm(pdm, sodym, ATIDESH, svydksinm, yogh);
						sndanm(pdm, yogh, YOGH, svydksinm, RUPM(pdm, yogh).dksinm);
					}
					else {
						const yugm nvyogh = sndanm(pdm, 0, YOGH, svydksinm, RUPM(pdm, yogh).dksinm);
						sndanm(pdm, sodym, ATIDESH, svydksinm, nvyogh);
					}
				} else if (svysvym == YNTA) {
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
				} else if (svysvym == DRUVH){
					distrupm(pdm, sodym, RUPM(pdm, svym).dksinm);
				}
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