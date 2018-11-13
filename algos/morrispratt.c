#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/stat.h>


#include "algos.h"

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

int morris_pratt(PatFinder patfinder, int * bonpref) {
    int m=0;
    int i=0;
    while(patfinder->w[m+i]!='\0' && patfinder->pat[i] != '\0'){
        if(patfinder->w[m+i]==patfinder->pat[i]) {
            ++i;
        } else {
            
        }
    }
    return 0; //TODO !!!!!!!!!!
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
    PatFinder patfind = (PatFinder) malloc(sizeof(struct pattern_finder));
    
    patfind->w = malloc(sizeof(char)* strlen(w)+1);
    patfind->pat=malloc(sizeof(char)* strlen(pat)+1);
    
    if(patfind->w==NULL){
		perror("malloc de w échoué");
		exit(EXIT_FAILURE);
	}else if(patfind->pat==NULL){
		perror("malloc de pat échoué");
		exit(EXIT_FAILURE);
	}
    
    patfind->wlen = wlen;
    patfind->patlen = patlen;
    
    strcpy(patfind->w,w);
    if(patfind->w==NULL){
		perror("copie de w échouée");
		exit(EXIT_FAILURE);
	}
	
    strcpy(patfind->pat,pat);
    if(patfind->pat==NULL){
		perror("copie de pat échouée");
		exit(EXIT_FAILURE);
	}
    
    printf("Nombre d'occurences : %d\n", morris_pratt(patfind));
    free(w);
    free(patfind);
    return 0;
}

