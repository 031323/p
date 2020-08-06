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

#define DISTRUPKM 1
#define SVYKM 2
#define DKSINKM 3
#define ATIDESYKM 4
#define SMTVKM 5
#define ATIDESKM 6
#define YOGKM 7
#define ANYKM 8

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