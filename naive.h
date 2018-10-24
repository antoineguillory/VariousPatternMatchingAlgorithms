#ifndef NAIVE_H
#define NAIVE_H

#define WORD_IS_NULL "w est null\n"
#define WORDLEN_IS_NULL "la longueur de w n'est pas définie\n"
#define PAT_IS_NULL "le pattern fourni est null\n"
#define PATLEN_IS_NULL "la longueur du pattern fourni est null\n"
#define UNCOHERENT_LENGTHS "les longueurs de w et pat sont incoherentes\n"

#define FIRST_CAR 0

struct pattern_finder {
	char w[512];
	size_t wlen;
	char pat[512];
	size_t patlen;
}; 
typedef struct pattern_finder* PatFinder;

int structural_integrity_checker(PatFinder patfinder);

int naif_interne(PatFinder patfinder);

int naif_interne_rapide(PatFinder patfinder);

int naif_interne_rapide_sentinelle(PatFinder patfinder);

#endif
