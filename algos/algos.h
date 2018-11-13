#ifndef ALGOS_H
#define ALGOS_H

#define WORD_IS_NULL "w est null\n"
#define WORDLEN_IS_NULL "la longueur de w n'est pas définie\n"
#define PAT_IS_NULL "le pattern fourni est null\n"
#define PATLEN_IS_NULL "la longueur du pattern fourni est null\n"
#define UNCOHERENT_LENGTHS "les longueurs de w et pat sont incoherentes\n"

#define FIRST_CAR 0

struct pattern_finder {
	char* w;
	size_t wlen;
	char* pat;
	size_t patlen;
}; 
typedef struct pattern_finder* PatFinder;

int structural_integrity_checker(PatFinder patfinder);

int morris_pratt(PatFinder patfinder, int* bon_pref);

int kmp(PatFinder patfinder);

int bm(PatFinder patfinder);

int turbo_bm(PatFinder patfinder);

int horspool(PatFinder patfinder);

int quick_search(PatFinder patfinder);

#endif
