#include <stdio.h>
#include <string.h>
#define MAX_SIZE 129

typedef char string[MAX_SIZE];
typedef string stringArr[MAX_SIZE];

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
int main()
{
    string sentenceInput, formulaInput;
    stringArr chorusLines[2];
    int i, totalLine0, totalLine1;
    
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
	binasphereSplit(sentenceInput, formulaInput, chorusLines, &totalLine0, &totalLine1);
	printf("\nDEFRAGMENTED CHORUS:\n");
	for (i = 0; i < totalLine0; i++){
	    printf("%s ", chorusLines[0][i]);
	}
	printf("\n");
	for (i = 0; i < totalLine0; i++){
	    printf("%s ", chorusLines[1][i]);
	}

    return 0;
}