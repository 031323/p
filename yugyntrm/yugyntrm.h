/* github.com/031323/yugyntrm */

#include <stdint.h>

#ifndef YUGYNTRM_H
#define YUGYNTRM_H

typedef char dvym;
static const dvym ST = 1;
static const dvym AST = 0;

typedef uint32_t yugsnkya;

static const yugsnkya VRDNM = 2;

typedef yugsnkya yugm;

static const yugm SVH = 1; // स्वः
static const yugm SVYH = 2; // स॒व्यः
static const yugm DKSINH = 3; // दक्षि॑णः
static const yugm DRUVH = 4; // ध्रु॒वः
static const yugm ADESH = 5; // आ॒दे॒शः
static const yugm STANI = 6; // स्था॒नी
static const yugm YNTA = 7; // य॒न्ता
static const yugm VIVICIH = 8; // विवि॑चिः

typedef yugm yugdrm;

static const yugdrm PRAKRTM = (yugdrm) (2ull^32ull - 1ull);
static const yugdrm YOGH = PRAKRTM - 1;
static const yugdrm DISTRUPM = YOGH - 1;
static const yugdrm ATIDESH = DISTRUPM - 1;

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
	yugsnkya bktsnkya;
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