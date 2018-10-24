#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/stat.h>


#include "naive.h"

int structural_integrity_checker(PatFinder patfinder){
	if(strlen(patfinder->w)==0) {
		perror(WORD_IS_NULL);
		return -1;
	} else if (patfinder->wlen==0) {
		perror(WORDLEN_IS_NULL);
		return -1;
	} else if (strlen(patfinder->pat)==0){
		perror(PAT_IS_NULL);
		return -1;
	} else if (patfinder->patlen==0){
		perror(PATLEN_IS_NULL);
		return -1;
	} else if (patfinder->wlen<patfinder->patlen){
		perror(UNCOHERENT_LENGTHS);
		return -1;
	}
	return 0;
}

char* get_content(char* filename){
	int fd = 0;

    struct stat st;
    stat(filename, &st);
    size_t buflen = st.st_size;
    if((fd=open(filename, O_RDONLY))==-1){
        perror("open");
        exit(EXIT_FAILURE);
    }

    char buf[buflen];
    ssize_t howmanybytesreads = read(fd,buf,buflen);

    if(howmanybytesreads==-1){
        perror("echec de read");
        exit(EXIT_FAILURE);
    }
    
    char * w = malloc(howmanybytesreads);

    strncpy(w,buf,howmanybytesreads-1);
    close(fd);

    return w;
}

int naif_interne(PatFinder patfinder) {
	if(structural_integrity_checker(patfinder)==-1){
		return -1;
	}
	int occurences = 0;
	for(size_t k=0; k<patfinder->wlen; ++k){
		if(memcmp(
			(void *)patfinder->pat,    /*Pattern a trouver*/
			(patfinder->w)+k,          /*Decale le pointeur de k positions*/
			 patfinder->patlen)==0){   /*On compare une longueur = |pat|*/
			++occurences;
		}
	}
	return occurences;
}

int main (int argc, char *argv[]) {
	if(argc<2){
        perror("pas assez d'arguments");
        exit(EXIT_FAILURE);
    }

    const char * pat = "comment";
    char* w = get_content(argv[1]);
    size_t wlen = strlen(w);
    size_t patlen = strlen(pat);
    PatFinder patfind = (PatFinder) malloc(sizeof(char)* strlen(w)  +1 *
                                           sizeof(char)* strlen(pat)+1 *
                                           sizeof(pat) *
                                           sizeof(patlen));
    memcpy(patfind->w,w,wlen);
    patfind->wlen = wlen;
    memcpy(patfind->pat,pat,patlen);
    patfind->patlen = patlen;
	
	printf("Nombre d'occurences : %d\n", naif_interne(patfind));
	free(w);
	free(patfind);
	return 0;
}
