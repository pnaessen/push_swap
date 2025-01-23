# Push_swap

## Description

Push_swap est un projet qui explore la complexité temporelle et introduit à l'optimisation algorithmique. Le but est de trier une liste d'entiers à l'aide de deux piles (A et B) en utilisant un ensemble limité d'instructions, tout en minimisant le nombre de mouvements nécessaires.

Ce README présente une vue d'ensemble de l'algorithme utilisé (l'algorithme coréen) et du checker qui valide les résultats.

## L'algorithme Coréen

L'algorithme coréen est une méthode efficace pour trier une pile en plusieurs étapes :

### Étapes principales :

#### Utilisation d'un Chunk Dynamique :

- Un seul chunk est utilisé, sa taille augmente au fur et à mesure du tri.
- Les éléments sont sélectionnés pour le transfert basé sur ce chunk.

#### Transfert Progressif :

- Les éléments appartenant au chunk actuel sont transférés de la pile A vers la pile B.
- À chaque transfert, la taille du chunk est incrémentée.

#### Pré-tri dans la Pile B :

- Les éléments transférés dans B ne sont pas complètement triés, mais leur ordre est partiellement organisé en fonction des opérations effectuées lors du transfert.

#### Tri Final et Remise en Place :

- Lors du retour des éléments dans A, le tri final est effectué en comparant les index des éléments.
- Les éléments sont réintégrés dans A en respectant l'ordre croissant grâce à des rotations ou des ajustements dans B avant chaque push.

## Checker

Le checker permet de vérifier si les instructions générées par push_swap ont correctement trié la liste.

### Fonctionnement :

- Le checker prend la liste initiale et les instructions générées en entrée.
- Il simule ces instructions sur les piles A et B.
- À la fin, il vérifie que :
  - La pile A est triée dans l'ordre croissant.
  - La pile B est vide.

### Résultats :

- **OK** : Si la pile A est correctement triée.
- **KO** : Si le tri est incorrect ou les instructions sont invalides.

### Pour vérifier les instructions générées :

```bash
./push_swap 3 2 1 | ./checker 3 2 1
```


## Project Structure 📁
```
📁 libft/
📁 src/ 
│ ├── algo.c 
│ ├── algo_tools.c 
│ ├── checker_init.c
│ ├── checker_tools.c 
│ ├── init.c 
│ ├── kr_tools.c 
│ ├── kr_utils.c
│ ├── list.c 
│ ├── pars.c 
│ ├── tools.c 
│ ├── tools2.c 
│ ├── tools_pars.c 
│ └── utils.c 
📁 include/
└── Makefile
```
