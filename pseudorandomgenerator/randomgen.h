#ifndef RANDOM_GEN
#define RANDOM_GEN

#define CHARSET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
#define ACCEPTED_WORD_LEN {4,5,6,7,8,9,10,15,20,30,40,50}
#define WORDSIZELIST_LEN 11

int generate_random(int taille_alpha, long nb_text_generated, char* name){
	if(taille_alpha == 0){
		return -1;
	} else if(nb_text_generated == 0) {
		return -1;
	} else if(name==""){
		return -1;
	}
    time_t t;
	srand((unsigned) time(&t));

   for(int i = 0; i < taille_alpha; ++i) {
	   if(nb_text_generated==0) {
		   break;
	   }
	   int wordLen = ACCEPTED_WORD_LEN[rand() % WORDSIZELIST_LEN +1];
	   nb_text_generated -= (long) wordLen;
	   if(nb_text_generated<0){
		   wordLen -= 
	   }
	   for(int j = 0; j < wordLen; ++j){
		   
	   }
	   
   }
}

#endif
