# Push_swap 🔄

## Description

Push_swap est un projet qui explore la complexité temporelle et introduit à l'optimisation algorithmique. Le but est de trier une liste d'entiers à l'aide de deux piles (A et B) en utilisant un ensemble limité d'instructions, tout en minimisant le nombre de mouvements nécessaires.

## 📝 Project Overview

The project consists of two programs:
- `push_swap`: Calculates and displays the smallest sequence of operations to sort a list of numbers
- `checker`: Verifies if a given sequence of operations correctly sorts the numbers

Ce README présente une vue d'ensemble de l'algorithme utilisé (l'algorithme coréen) et du checker qui valide les résultats.

## 🛠️ Installation

```bash
# Clone the repository
git clone https://github.com/yourusername/push_swap.git
cd push_swap

# Compile the programs
make
```

## 💻 Usage

### Push_swap Program
```bash
# Format: ./push_swap [numbers...]
./push_swap 2 1 3 6 5 8

# Example output:
sa
pb
pb
pb
sa
pa
pa
pa
```

### Checker Program
```bash
# Format: ./checker [numbers...]
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
OK
```

### Résultats :

- **OK** : Si la pile A est correctement triée.
- **KO** : Si le tri est incorrect ou les instructions sont invalides.

## 🔍 Algorithm

The project implements the Korean sorting algorithm, which consists of several key steps:

1. **Chunk Sorting**: 
   - Uses dynamic chunk sizes based on input length
   - Optimized for different input sizes
   
2. **Stack Operations**:
   - Push elements to stack B in chunks
   - Maintain partial ordering during transfers
   
3. **Final Sort**:
   - Sort remaining elements in stack A
   - Efficiently merge back elements from stack B

## 🎯 Performance Targets

| Number of Elements | Maximum Operations |
|-------------------|-------------------|
| 3                 | 2-3              |
| 5                 | 12               |
| 100               | 700              |
| 500               | 5500             |


## Project Structure 📁
```
📁 include/
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
└── Makefile
```
## 🙏 Acknowledgments

- Stack Overflow, pour avoir répondu aux questions que ne savait même pas que j'avait

Happy Coding! 🚀✨