Push_swap
Description

Push_swap est un projet qui explore la complexité temporelle et introduit à l'optimisation algorithmique. Le but est de trier une liste d'entiers à l'aide de deux piles (A et B) en utilisant un ensemble limité d'instructions, tout en minimisant le nombre de mouvements nécessaires.

Ce README présente une vue d'ensemble de l'algorithme utilisé (l'algorithme coréen) et du checker qui valide les résultats.
L'algorithme Coréen

L'algorithme coréen est une méthode efficace pour trier une pile en plusieurs étapes :
Étapes principales :

    Découpage en groupes :
        Les nombres dans la pile A sont divisés en sous-groupes basés sur leur taille relative (par exemple, via des intervalles calculés avec des médianes).
        Chaque groupe est trié individuellement et transféré partiellement dans la pile B.

    Utilisation de pivots :
        Pour chaque groupe, un pivot est choisi. Les nombres plus petits que le pivot sont envoyés dans la pile B, tandis que les autres restent dans A.

    Remise en place :
        Une fois triés dans B, les sous-groupes sont réintégrés dans la pile A en respectant l'ordre croissant.

Checker

Le checker permet de vérifier si les instructions générées par push_swap ont correctement trié la liste.
Fonctionnement :

    Le checker prend la liste initiale et les instructions générées en entrée.
    Il simule ces instructions sur les piles A et B.
    À la fin, il vérifie que :
        La pile A est triée dans l'ordre croissant.
        La pile B est vide.

Résultats :

    OK : Si la pile A est correctement triée.
    KO : Si le tri est incorrect ou les instructions sont invalides.

    Pour vérifier les instructions générées :

./push_swap 3 2 1 | ./checker 3 2 1

Project Structure 📁

📁 libft/               # Bibliothèque personnelle contenant des fonctions utilitaires
📁 src/                 # Fichiers source principaux
│   ├── algo.c          # Implémentation de l'algorithme principal
│   ├── algo_tools.c    # Fonctions utilitaires pour l'algorithme
│   ├── checker_init.c  # Initialisation des données pour le checker
│   ├── checker_tools.c # Fonctions utilitaires spécifiques au checker
│   ├── init.c          # Fonctions d'initialisation
│   ├── kr_tools.c      # Outils pour l'algorithme coréen
│   ├── kr_utils.c      # Fonctions supplémentaires pour l'algorithme coréen
│   ├── list.c          # Gestion des listes chaînées
│   ├── pars.c          # Parsing des arguments
│   ├── tools.c         # Fonctions utilitaires diverses
│   ├── tools2.c        # Fonctions utilitaires complémentaires
│   ├── tools_pars.c    # Fonctions utilitaires pour le parsing
│   └── utils.c         # Fonctions générales utilisées dans plusieurs modules
📁 include/             # Fichiers d'en-tête (.h)
📁 libft/               # Implémentation de la bibliothèque personnelle
└── Makefile            # Instructions pour compiler le projet
