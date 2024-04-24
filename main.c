 #include <stdio.h>
#include "LinkedList.h"

int main(int argc, char *argv[]){


  int lineLength = 0;
	//printf("This is lineLength before: %d\n", lineLength);

  FILE *shakeFile;

	shakeFile = fopen("shakespeare-cleaned5.txt", "r"); //open file

	if(shakeFile == NULL){
		printf("ERROR: Could not open file.");
		return 1;
	}


  char line[255];
	fgets(line, 255, shakeFile);
  while(!feof(shakeFile)){
    if(strlen(line) > lineLength){
      lineLength = strlen(line);
    }
		fgets(line, 255, shakeFile);
  }
	fclose(shakeFile);

	//printf("This is lineLength after: %d\n", lineLength);


	
	node* arrayList[lineLength];

	for (int i = 0; i < lineLength; i++){
		arrayList[i] = NULL;
	}
	
	shakeFile = fopen("shakespeare-cleaned5.txt", "r");

	if(shakeFile == NULL){
		printf("ERROR: Could not open file.");
		return 1;
	}


	fgets(line, 255, shakeFile);
	while(!feof(shakeFile)){
		int wordLength = strlen(line) - 1;
		//printf("WordLength is : %d\n", wordLength);
		
		arrayList[wordLength] = insertNode(arrayList[wordLength], line);
		fgets(line, 255, shakeFile);
	}

	fclose(shakeFile);


	for(int i = 0; i <lineLength; i++){

		if(arrayList[i] != NULL && arrayList[i]->next != NULL){

			//printf("\nHere is unsorted %d: \n", i);
			//printList(arrayList[i]);
			arrayList[i] = mergeSort(arrayList[i]);
			//printf("\nHere is sorted: %d: \n", i);
		}

		
	}	


	

	FILE* inputFile = fopen(argv[1], "r");
	FILE* outputFile = fopen(argv[2], "w");

	if(inputFile == NULL || outputFile == NULL){
		printf("ERROR: Could not open file");
		return 1;
	}

	char buffer[255];
	//fgets(buffer,200,inputFile);

	int lengthOfWord;
	int frequencyOfWord;

	fscanf(inputFile, "%d %d", &lengthOfWord, &frequencyOfWord);
	while(fgets(buffer,255,inputFile) != NULL){

		//printf("%d", !feof(inputFile));
		//printf("Length: %d\nFreq: %d\n", lengthOfWord, frequencyOfWord);

		if(lengthOfWord != 0 && lengthOfWord < lineLength){
			//printf("%d\n", lengthOfWord);
			node* current = arrayList[lengthOfWord];
			//printf("Heres arrayList[%d]\n", lengthOfWord);

			for(int i = 0; i < frequencyOfWord ; i++){
				if(current != NULL){
					current = current->next;
				}
			}
			
			if(current != NULL){
				//printf("%s\n", current->word);
				fprintf(outputFile, "%s", current->word);
			}
			else{
				//printf("-\n");
				fprintf(outputFile, "-\n");
			}
		}
		else{
			//printf("-\n");
			fprintf(outputFile, "-\n");
		}
		fscanf(inputFile, "%d %d", &lengthOfWord, &frequencyOfWord);

		
		
	}

	

  return 0;

}

