#include <stdio.h>
#include <string.h>
#define MAX_SIZE 321
#define MAX_ARR 129

typedef char string[MAX_SIZE];
typedef string stringArr[MAX_ARR];

void splitSentence(string sentence, stringArr words, int* totalWords){
    int i = 0, j = 0, k = 0;
    while(k <= strlen(sentence)){
        
        words[j][i] = sentence[k]; 
        i++;
        
        if (sentence[k] == ' '){
            words[j][i-1] = '\0';
            i = 0;
            j++;
        }
        
        if (sentence[k] == '\0'){
            j++;
        }
        
        k++;
    }
    
    *totalWords = j;
}

int wordCount(string sentence){
    int j = 0, k = 0;
    while(k <= strlen(sentence)){
        
        if (sentence[k] == ' '){
            j++;
        }
        
        if (sentence[k] == '\0'){
            j++;
        }
        
        k++;
    }
    
    return j;
}

int scanFormula(string formula){
	int i;

	for (i = 0; i < strlen(formula); i++){
		if (formula[i] != '0' && formula[i] != '1'){
			return 1;
		}
	}
	
	return 0;
}

void binasphereSplit(string chorus, string formula, stringArr chorusLines[2], int* totalLine0, int* totalLine1){
	
	int totalWords;
	stringArr words;
	int i, j = 0, k = 0;
	
	splitSentence(chorus, words, &totalWords);
	for (i = 0; i < totalWords; i++){
		if (formula[i] == '0'){
			strcpy(chorusLines[0][j], words[i]);
			j++;
		}
		if (formula[i] == '1'){
		    strcpy(chorusLines[1][k], words[i]);
		    k++;
		}
	}
	
	*totalLine0 = j;
	*totalLine1 = k;
	
	
}

void formulaRepeater(string formula, string newFormula, int totalWords){
  int size = totalWords;
  char repeated[size+1];
  int i = 0, j = 0;
  while (i < size){
    repeated[i] = formula[j];
    i++;
    j++;
    if (j >= strlen(formula)){
    	j = 0;	
	}
  }
  
  strcpy(newFormula, repeated);
}

// unused
void appendFragment(string base, string appended, string newWord){
	
	int i;
	for (i = 0; i < strlen(base); i++){
		if (base[i] == 'x'){
			base[i] = '\0';
			base[i+1] = '\0';
			strcat(base, appended);
			break;
		}
	}
	
}

// to be cleaned
void displayActual(stringArr chorusLines[2], int totalLine0, int totalLine1){
	
	
	int i = 0, j = 0;
	int k = 0, l = 0;
	
	printf("\nACTUAL CHORUS:\n");
	while (i < totalLine0){
		if (chorusLines[0][i][k] == 'x'){
			chorusLines[0][i][k] = '\0';
			
			if (chorusLines[0][i][k+1] == ' ');
				chorusLines[0][i][k+1] = '\0';
		}
		else{
			
			if (i == 0 && k == 0){
				printf("%c", chorusLines[0][i][k]);
			}
			else{
				printf("%c", chorusLines[0][i][k] + 32);
			}
		}

	    k++;
	    
	    if (k > strlen(chorusLines[0][i])){
	    	k = 0;
	    	i++;
		}
	}
	
	printf("\n");
	
	while (j < totalLine1){
		
		if (chorusLines[1][j][l] == 'x'){
			chorusLines[1][j][l] = '\0';
			
			if (chorusLines[1][j][l+1] == ' ');
				chorusLines[1][j][l+1] = '\0';

		}
		else{
			if (j == 0 && l == 0){
				printf("%c", chorusLines[1][j][l]);
			}
			else{
				printf("%c", chorusLines[1][j][l] + 32);
			}
		}

	    l++;
		if (l > strlen(chorusLines[1][j])){
			l = 0;
	    	j++;
		}
	}
	
	printf("\n");
	
}

int main()
{
    string sentenceInput, formulaInput, newFormula;
    stringArr chorusLines[2];
    int i, totalLine0, totalLine1, totalWords;
    int loopInput = 0, loop = 0;
    
    scanf("%d", &loopInput);
    while (loop < loopInput){
    
    	printf("\n");
	    printf("Enter Binasphere Chorus:\n=>");
	    scanf(" %[^\n]", sentenceInput);
	    printf("\nEnter Binasphere Formula:\nEXEC hymme 2X1/0>>");
	    scanf(" %[^\n]", formulaInput);
	    
	    int invalidFormula = scanFormula(formulaInput);
	    
	    if (invalidFormula){
	    	while (invalidFormula){
	    		printf("Invalid formula!\n");
	    		printf("Enter Binasphere Formula:\nEXEC hymme 2X1/0>>");
	    		scanf(" %[^\n]", formulaInput);
	    		invalidFormula = scanFormula(formulaInput);
			}
		}
		
		totalWords = wordCount(sentenceInput);
		
		if (totalWords > strlen(formulaInput)){
			formulaRepeater(formulaInput, newFormula, totalWords);
			binasphereSplit(sentenceInput, newFormula, chorusLines, &totalLine0, &totalLine1);
			
			printf("\nCONVERTED FORMULA:\nEXEC hymme 2X1/0>>");
			printf("%s\n", newFormula);
		}
		
		else {
			binasphereSplit(sentenceInput, formulaInput, chorusLines, &totalLine0, &totalLine1);
		}
		
		printf("\nDEFRAGMENTED CHORUS:\n");
		for (i = 0; i < totalLine0; i++){
		    printf("%s ", chorusLines[0][i]);
		}
		printf("\n");
		for (i = 0; i < totalLine1; i++){
		    printf("%s ", chorusLines[1][i]);
		}
		printf("\n");
		displayActual(chorusLines, totalLine0, totalLine1);
		printf("\n");
		loop++;
	}
    return 0;
}
