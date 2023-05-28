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
*  Nom du fichier : main.c                                                    *
*                                                                             *
******************************************************************************/

#include "calculeradresse.h"
#include "decoderip.h"
#include "extraireleschamps.h"
#include "verifierleformat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main
int main() {
  char ip_adresse[19];

  // Demande l'adresse IP
  printf("Entrez une adresse IP (ex: xxx.xxx.xxx.xxx/xx) : ");
  scanf("%18s", ip_adresse);

  // Vérification de l'adresse IP
  if (ip_format_valide(ip_adresse)) {
    printf("L'adresse IP est valide.\n");

    // Attribut chaque octet et le masque à une variable
    char adresse_reseau[19];
    int octet1, octet2, octet3, octet4, masque;
    extraire_champs_ip(ip_adresse, &octet1, &octet2, &octet3, &octet4, &masque);

    // Affiche L'octet correspondant
    printf("Champs extraits :\n");
    printf("Octet 1 : %d\n", octet1);
    printf("Octet 2 : %d\n", octet2);
    printf("Octet 3 : %d\n", octet3);
    printf("Octet 4 : %d\n", octet4);
    printf("Masque : %d\n", masque);

    // Attribut les types, les classes et le nombre d'hôtes à une variable
    TypeAdresseIP type_ip = decoder_type_adresse_ip(ip_adresse);
    ClasseAdresseIP classe_ip = decoder_classe_adresse_ip(ip_adresse);
    int nombre_hotes = calculer_nombre_hotes(ip_adresse);
    
    // Affiche Type d'adresse IP :
    afficher_type_adresse_ip(type_ip);

    // Affiche la classe et l'adresse réseau
    // Ne prend pas le type réseau et inconnu
    if (type_ip != TYPE_RESEAU && type_ip != TYPE_INCONNU) {
      afficher_classe_adresse_ip(classe_ip);
      calculeradressereseau(ip_adresse, adresse_reseau);
      printf("Adresse réseau : %s\n", adresse_reseau);

      // Affiche le nombre dôtes disponibles
      // Ne prend pas le type broadcast et multicast
      if (type_ip != TYPE_BROADCAST && type_ip != TYPE_MULTICAST){
        printf("Nombre d'hôtes disponibles : %u\n", nombre_hotes);
      }
    }
    
  // Affiche Adresse IP invalide
  } else {
    printf("L'adresse IP est invalide.\n");
  }
}