# Projet XYZ

Ce projet contient un programme en C qui effectue diverses opérations liées à l'adressage IP.

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

### Fonction : calculerAdresse()

```c
void calculerAdresse(char* adresseIP, int masque, char* resultat); 
```
**Cette fonction prend une adresse IP sous la forme d'une chaîne de caractères, un masque de sous-réseau et renvoie le résultat du calcul de l'adresse correspondante dans la variable resultat. Les paramètres d'entrée sont les suivants :

- `adresseIP` : la chaîne de caractères représentant l'adresse IP.
- `masque` : le masque de sous-réseau.
**





