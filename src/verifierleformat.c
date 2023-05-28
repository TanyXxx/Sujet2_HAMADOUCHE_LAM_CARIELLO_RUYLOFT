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
*  Nom du fichier : verifierleformat.c                                        *
*                                                                             *
******************************************************************************/

#include "verifierleformat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Vérifie le format de l'adresse IP
// Les octets compris entre 0 à 255 et
// Le masque entre 0 et 32
int ip_format_valide(const char *ip_adresse) {
  int octet1, octet2, octet3, octet4, subnet;

  int numScanned = sscanf(ip_adresse, "%d.%d.%d.%d/%d", &octet1, &octet2,
                          &octet3, &octet4, &subnet);

  if (numScanned == 5) {
    if (octet1 >= 0 && octet1 <= 255 && octet2 >= 0 && octet2 <= 255 &&
        octet3 >= 0 && octet3 <= 255 && octet4 >= 0 && octet4 <= 255) {
      if (subnet >= 0 && subnet <= 32) {
        return 1;
      } else {
        return 0;
      }
    } else {
      return 0;
    }
  } else {
    return 0;
  }
}