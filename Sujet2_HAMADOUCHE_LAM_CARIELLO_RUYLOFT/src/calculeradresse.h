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
*  Nom du fichier : calculeradresse.h                                         *
*                                                                             *
******************************************************************************/

#ifndef CALCULERADRESSE_H
#define CALCULERADRESSE_H

// Calcul l'adresse reseau de l'adresse IP
void calculeradressereseau(const char *ip_adresse, char *adresse_reseau);

// Calcul le nombre d'hôte disponible
int calculer_nombre_hotes(const char *ip_adresse);

#endif 