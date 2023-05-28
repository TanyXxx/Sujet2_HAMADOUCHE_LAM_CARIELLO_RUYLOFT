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
 *  Nom du fichier : calculeradresse.c                                         *
 *                                                                             *
 ******************************************************************************/

#include "calculeradresse.h"
#include "decoderip.h"
#include "extraireleschamps.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calcul l'adresse reseau de l'adresse IP
void calculeradressereseau(const char *ip_adresse, char *adresse_reseau) {

  // Stock les octets dans des variables
  int octet1, octet2, octet3, octet4, masque;
  extraire_champs_ip(ip_adresse, &octet1, &octet2, &octet3, &octet4, &masque);

  // Variable Supérieur ou égal à 0
  unsigned int octet_adr_res[4] = {0};
  // Variable qui décale les bits par rapport au masque
  unsigned int masque_binaire = 0xFFFFFFFF << (32 - masque);

  
  octet_adr_res[0] = octet1 & (masque_binaire >> 24);
  octet_adr_res[1] = octet2 & (masque_binaire >> 16);
  octet_adr_res[2] = octet3 & (masque_binaire >> 8);
  octet_adr_res[3] = octet4 & masque_binaire;

  // Vérifie si le masque est inférieur à 32 et ajuste l'adresse réseau
  if (masque < 32) {
    unsigned int ajustement = 1 << (32 - masque);
    octet_adr_res[3] = (octet_adr_res[3] / ajustement) * ajustement;
  }

  // Assigne chaque octet de l'adresse réseau sous forme
  // xxx.xxx.xxx.xxx 
  sprintf(adresse_reseau, "%d.%d.%d.%d", octet_adr_res[0], octet_adr_res[1],
          octet_adr_res[2], octet_adr_res[3]);
}

// Calcul le nombre d'hôte disponible
int calculer_nombre_hotes(const char *ip_adresse) {
  
  // Stock les octets dans des variables
  int octet1, octet2, octet3, octet4, masque;
  extraire_champs_ip(ip_adresse, &octet1, &octet2, &octet3, &octet4, &masque);

  // Vérifie si c'est une adresse de type localhost
  // Alors retourne 1 Sinon retourne (2**(32-masque))-2
  if ((decoder_classe_adresse_ip(ip_adresse)) == TYPE_LOCALHOST) {
    return 1;
  } else {
    return (pow(2, (32 - masque)) - 2);
  }
}