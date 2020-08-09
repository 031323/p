/* github.com/031323/yugyntrm */

#include "dvyastktntrm.h"

#include "yugyntrm.h"

#include <stdlib.h>

smbrnm dvyastktntrm()
{
	smbrnm tntrm = nvsmbrnm();
	const smbrnpdm pdm = &tntrm;
	for(int i = 0; i < 128; i++) {
		yugm ekm = nvm(pdm, 0, 0, 0);
	}
	return tntrm;
}

yugm dvyastksyyugm(const char dvyastkm)
{
	return ((yugm) (unsigned char) dvyastkm) + 9;
}

char dvyastkm(const yugm ysyestm)
{
	return (char) (ysyestm - 9);
}

yugm dvyastktnteryugtntih(const smbrnpdm pdm, char * dvyastktntih, const int tntivrima)
{
	yugm yugtntih = 0;
	const yugm murda = pdm->murda;
	dvyastktntih = dvyastktntih + tntivrima - 1;
	for(int i = 0; i < tntivrima; i++, dvyastktntih--) {
		yugtntih = nvm(pdm, dvyastksyyugm(*(dvyastktntih)), yugtntih, 0);
		murdgrhnm(pdm, nvm(pdm, yugtntih, murda, 0));
	}
	return yugtntih;
}

char * yugtnterdvyastktntih(const smbrnpdm pdm, const yugm yugtntih, int * vrimnpdm)
{
	yugsnkya tntivrima = 0;
	yugm tntimurda = yugtntih;
	while(tntimurda) {
		tntivrima++;
		tntimurda = dksinm(pdm, tntimurda);
	}
	*vrimnpdm = tntivrima;
	if(! tntivrima) {
		return 0;
	}
	char * dvyastktntih = malloc(tntivrima);
	tntimurda = yugtntih;
	tntivrima = 0;
	while(tntimurda) {
		*(dvyastktntih + tntivrima) = dvyastkm(svym(pdm, tntimurda));
		tntivrima++;
		tntimurda = dksinm(pdm, tntimurda);
	}
	return dvyastktntih;
}