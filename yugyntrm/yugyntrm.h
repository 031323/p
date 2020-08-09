/* github.com/031323/yugyntrm */

#include <stdint.h>

#ifndef YUGYNTRM_H
#define YUGYNTRM_H

typedef char dvym;
#define ST 1
#define AST 0

#ifndef yugsnkya
#define yugsnkya uint32_t
#endif

#ifndef VRDNM
#define VRDNM 2
#endif

typedef yugsnkya yugm;

#define SVH 1 // स्वः
#define SVYH 2 // स॒व्यः
#define DKSINH 3 // दक्षि॑णः
#define STANI 4 // स्था॒नी
#define DRUVH 5 // ध्रु॒वः
#define ADESH 6 // आ॒दे॒शः
#define YNTA 7 // य॒न्ता
#define VIVICIH 8 // विवि॑चिः

typedef enum { PRAKRTM, YOGH, DISTRUPM, ATIDESH, RIKTM } yugdrm;

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
	yugm murda;
} smbrnm;

typedef smbrnm * smbrnpdm;
typedef yugm * yugpdm;

smbrnm nvsmbrnm();
yugm nvm(const smbrnpdm, const yugm, const yugm, const dvym);
void murdgrhnm(const smbrnpdm, const yugm);
void visrgh(const smbrnpdm);
yugm svym(const smbrnpdm, const yugm);
yugm dksinm(const smbrnpdm, const yugm);

void gopnm(const smbrnpdm pdm, void(*gopah)(char, void *), void *);
smbrnm ropnm(char(*ropkm)(void *), void *);

#ifdef PRIKSNM
void lekh(const smbrnpdm);
#endif

#endif