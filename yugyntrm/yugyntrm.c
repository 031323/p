/* github.com/031323/yugyntrm */

#include "yugyntrm.h"

#include <malloc.h>
#include <stdio.h>

#include <math.h>

typedef char dvym;
#define st 1
#define ast 0

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

int vrdnani = 0;

/* = malloc */
yugm nvm(const smbrnpdm pdm)
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
		vrdnani++;
		printf("%d vrdnani\n", vrdnani);
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
	if(kspyitvym) {
		atmksyh(pdm, RUPM(pdm, kspyitvym).svym);
		atmksyh(pdm, RUPM(pdm, kspyitvym).dksinm);
	}
}

static void atmksyh(const smbrnpdm pdm, const yugm kspyitvym)
{
	if(kspyitvym && !--(RUPM(pdm, kspyitvym).snkya)) {
		visvangksyh(pdm, kspyitvym);
		recnm(pdm, kspyitvym);
	}
}

static void vrdnm(const smbrnpdm pdm, const yugm vrditvym)
{
	if(vrditvym)
		RUPM(pdm, vrditvym).snkya++;
}

yugm sndanm(const smbrnpdm pdm, yugm nivesnm,
	const yugdrm drm, const yugm svym, const yugm dksinm)
{
	if(nivesnm)
		visvangksyh(pdm, nivesnm);
	else nivesnm = nvm(pdm);
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
	for(int i = 0; i <= 8; i++) {
		sndanm(nvpdm, 0, PRAKRTM, 0, 0);
	}
	return nvmsmbrnm;
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