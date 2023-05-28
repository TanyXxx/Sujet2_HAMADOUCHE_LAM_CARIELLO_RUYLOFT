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
*  Nom du fichier : decoderip.h                                               *
*                                                                             *
******************************************************************************/

#ifndef DECODERIP_H
#define DECODERIP_H

// Enumération définissant les types d'adresses IP possibles
typedef enum {
  TYPE_PUBLIQUE,
  TYPE_PRIVEE,
  TYPE_LOCALHOST,
  TYPE_BROADCAST,
  TYPE_MULTICAST,
  TYPE_RESEAU,
  TYPE_INCONNU
} TypeAdresseIP;

// Enumération définissant les classes d'adresses IP possibles
typedef enum {
  CLASSE_A,
  CLASSE_B,
  CLASSE_C,
  CLASSE_D,
  CLASSE_E,
  CLASSE_INCONNUE
} ClasseAdresseIP;

// Affiche le type de l'adresse IP
void afficher_type_adresse_ip(TypeAdresseIP type);

// Affiche la classe de l'adresse IP
void afficher_classe_adresse_ip(ClasseAdresseIP classe);

// Détermine le type de l'adresse IP
// Retorune un type d'adresse IP
TypeAdresseIP decoder_type_adresse_ip(const char *ip_adresse);

// Détermine la classe de l'adresse IP
// Retorune une classe d'adresse IP
ClasseAdresseIP decoder_classe_adresse_ip(const char *ip_adresse);

#endif