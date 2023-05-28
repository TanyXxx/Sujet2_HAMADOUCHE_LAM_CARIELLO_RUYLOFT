# Mini Projet C

Ce projet contient un programme en C qui effectue diverses opérations liées à l'adressage IP. 

## Objectif de l'application

L'objectif de cette application est de fournir diverses fonctionnalités liées à l'adressage IP, telles que le calcul d'adresse, le décodage d'adresse IP, l'extraction des champs d'une adresse IP et la vérification du format d'une adresse IP.

## Auteurs

- Nom & Prénom 1 : Hamadouche Soltan
- Nom & Prénom 2 : Lam Clément
- Nom & Prénom 3 : Ruyloft Joppe
- Nom & Prénom 4 : Cariello Luppo

## Contenu du projet

- `main.c` : Le fichier source principal contenant la fonction `main()` qui exécute le programme.
- `calculeradresse.c`, `decoderip.c`, `extraireleschamps.c`, `verifierleformat.c` : Les fichiers source contenant les différentes fonctionnalités du programme.
- `calculeradresse.h`, `decoderip.h`, `extraireleschamps.h`, `verifierleformat.h` : Les fichiers d'en-tête correspondant aux fichiers source respectifs.
- `Makefile` : Le fichier de configuration Makefile pour automatiser les étapes de compilation.

## Compilation du programme

1. Assure-toi d'avoir GCC (GNU Compiler Collection) installé sur ton système.
   - Sur Ubuntu : `sudo apt-get install build-essential`
   - Sur Fedora : `sudo dnf install gcc`

2. Place tous les fichiers source (".c" et ".h") dans le répertoire `src`.

3. Ouvre un terminal et accède au répertoire contenant le fichier `Makefile`.

4. Exécute la commande `make`. Cela compilera les fichiers source et créera l'exécutable final.

5. Une fois la compilation terminée, l'exécutable `MakeFile` sera généré dans le répertoire `bin`.

## Exécution du programme

- Dans un terminal, accède au répertoire contenant l'exécutable `MakeFile`.

- Exécute la commande `./MakeFile` pour lancer le programme.

## Nettoyage

- Pour supprimer les fichiers objets et l'exécutable générés, exécute la commande `make clean`.

## Documentation des fonctions

### Fonction : ip_format_valide()

```c
int ip_format_valide(const char *ip_adresse); 
```
Cette fonction vérifie si le format d'une adresse IP est valide. Les octets de l'adresse IP doivent être compris entre 0 et 255, et le masque doit être compris entre 0 et 32. La fonction renvoie un entier qui vaut 1 si le format est valide et 0 sinon. Le paramètre d'entrée de cette fonction est le suivant :

- `ip_adresse` : une chaîne de caractères représentant l'adresse IP à vérifier.

### Fonction : decoderIP()

```c
void decoderIP(char* adresseIP, int* octet1, int* octet2, int* octet3, int* octet4);
```
Cette fonction prend une adresse IP sous la forme d'une chaîne de caractères et décode les octets de l'adresse IP dans les variables `octet1`, `octet2`, `octet3` et `octet4`. Les paramètres d'entrée sont les suivants :

### Fonction : extraire_champs_ip()

```c
void extraire_champs_ip(const char* ip_adresse, int* octet1, int* octet2, int* octet3, int* octet4, int* masque);
```
Cette fonction extrait chaque octet et le masque d'une adresse IP et les stocke dans les variables respectives. Les paramètres d'entrée de cette fonction sont les suivants :

- `ip_adresse` : une chaîne de caractères représentant l'adresse IP à traiter.

Les paramètres de sortie sont les suivants :

- `octet1` : un pointeur vers une variable entière où le premier octet sera stocké.
- `octet2` : un pointeur vers une variable entière où le deuxième octet sera stocké.
- `octet3` : un pointeur vers une variable entière où le troisième octet sera stocké.
- `octet4` : un pointeur vers une variable entière où le quatrième octet sera stocké.
- `masque` : un pointeur vers une variable entière où le masque sera stocké.

### Fonction : afficher_type_adresse_ip() 

```c
void afficher_type_adresse_ip(TypeAdresseIP type);
```
Cette fonction affiche le type d'une adresse IP en fonction de la valeur de l'énumération `TypeAdresseIP` passée en paramètre. Les paramètres d'entrée de cette fonction sont les suivants :

- `type` : une valeur de l'énumération `TypeAdresseIP` représentant le type de l'adresse IP.

La fonction utilise un `switch case` pour afficher le type d'adresse IP correspondant en fonction de la valeur de `type`.

### Fonction : afficher_classe_adresse_ip()

```c
void afficher_classe_adresse_ip(ClasseAdresseIP classe);
```
Cette fonction affiche la classe d'une adresse IP en fonction de la valeur de l'énumération `ClasseAdresseIP` passée en paramètre. Les paramètres d'entrée de cette fonction sont les suivants :

- `classe` : une valeur de l'énumération `ClasseAdresseIP` représentant la classe de l'adresse IP.

La fonction utilise un `switch case` pour afficher la classe d'adresse IP correspondante en fonction de la valeur de `classe`.

### Fonction : decoder_type_adresse_ip()

```c
TypeAdresseIP decoder_type_adresse_ip(const char* ip_adresse);
```
Cette fonction détermine le type d'une adresse IP en analysant ses octets et son masque. La fonction prend une adresse IP sous la forme d'une chaîne de caractères en paramètre. Les paramètres d'entrée de cette fonction sont les suivants :

- `ip_adresse` : une chaîne de caractères représentant l'adresse IP à décoder.

La fonction extrait les octets et le masque de l'adresse IP en utilisant la fonction `extraire_champs_ip`. Ensuite, elle effectue des vérifications pour déterminer le type d'adresse IP en utilisant différentes conditions. Le type d'adresse IP est renvoyé sous la forme d'une valeur de l'énumération `TypeAdresseIP`.


### Fonction : decoder_classe_adresse_ip()

```c
ClasseAdresseIP decoder_classe_adresse_ip(const char* ip_adresse);
```
Cette fonction détermine la classe d'une adresse IP en analysant le premier octet de l'adresse IP. La fonction prend une adresse IP sous la forme d'une chaîne de caractères en paramètre. Les paramètres d'entrée de cette fonction sont les suivants :

- `ip_adresse` : une chaîne de caractères représentant l'adresse IP à décoder.

La fonction extrait le premier octet de l'adresse IP en utilisant la fonction `sscanf`. Ensuite, elle effectue des vérifications pour déterminer la classe d'adresse IP en utilisant des conditions. La classe d'adresse IP est renvoyée sous la forme d'une valeur de l'énumération `ClasseAdresseIP`.

### Fonction : calculeradressereseau()

```c
void calculeradressereseau(const char* ip_adresse, char* adresse_reseau);
```
Cette fonction calcule l'adresse réseau à partir d'une adresse IP donnée. Elle prend en paramètre une adresse IP sous la forme d'une chaîne de caractères et une variable `adresse_reseau` pour stocker l'adresse réseau calculée. Les paramètres d'entrée de cette fonction sont les suivants :

- `ip_adresse` : une chaîne de caractères représentant l'adresse IP.
- `adresse_reseau` : un tableau de caractères qui sera utilisé pour stocker l'adresse réseau calculée.

La fonction extrait les octets et le masque de l'adresse IP en utilisant la fonction `extraire_champs_ip`. Ensuite, elle effectue des opérations pour calculer l'adresse réseau en appliquant le masque binaire. L'adresse réseau calculée est stockée dans le tableau `adresse_reseau`.

## Cas d'erreur
- Si une adresse IP invalide est fournie en entrée, les fonctions peuvent afficher un message d'erreur approprié ou retourner une valeur indiquant une erreur.

Pour plus de détails sur l'implémentation et l'utilisation des fonctions, veuillez consulter le code source des fichiers correspondants.

Le code source de l'application est disponible dans le dépôt Git suivant : https://github.com/TanyXxx/Sujet2_HAMADOUCHE_LAM_CARIELLO_RUYLOFT.git




