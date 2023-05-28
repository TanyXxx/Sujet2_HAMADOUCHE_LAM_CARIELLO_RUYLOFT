/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet : 2                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé : Analyse adresse IP                                              *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : Hamadouche Soltan                                            *
*                                                                             *
*  Nom-prénom2 : Lam Clément                                                  *
*                                                                             *
*  Nom-prénom3 : Ruyloft Joppe                                                *
*                                                                             *
*  Nom-prénom4 : Cariello Luppo                                               *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : extraireleschamps.c                                       *
*                                                                             *
******************************************************************************/

#include "extraireleschamps.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Extrait chaque octets et le masque dans les variables respectifs
void extraire_champs_ip(const char *ip_adresse, int *octet1, int *octet2,
                        int *octet3, int *octet4, int *masque) {
  sscanf(ip_adresse, "%d.%d.%d.%d/%d", octet1, octet2, octet3, octet4, masque);
}