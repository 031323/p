#ifndef YUGYNTRM_H
#define YUGYNTRM_H

#ifndef yugsnkya
#define yugsnkya unsigned int
#endif

#ifndef VRDNM
#define VRDNM 2
#endif

typedef yugsnkya yugm;

typedef enum { PRAKRTM, YOGH, DISTRUPM, ATIDESH } yugdrm;

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
typedef yugm * yugpdm;

smbrnm nvsmbrnm();
yugm nvm(const smbrnpdm);
yugm sndanm(const smbrnpdm, const yugdrm, yugm, const yugm, const yugm);

#endif