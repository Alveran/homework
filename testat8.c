
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int function1(){
	int size;
	printf("Gib die Groesse des Arrays ein:\n");
	scanf("%d", &size);
	return size;
}

int *function2(int size){
	int *arr = (int *) malloc(size * sizeof(int));
	printf("Gibt immer eine ganze Zahl zwischen 1 und 1000 ein und fahre mit ENTER fort:\n");
	for(int i=0; i < size; i++)
		scanf("%d", &arr[i]);
	printArr(arr);
	return *arr;
}

int *function3(int size){
	int *arr = (int *) malloc(size * sizeof(int));
	for(int i=0; i < size; i++)
		arr[i] = rndom();
	printArr(arr);
	return *arr;
}

void bubblesort(int *array, int length){
        int i, j;
        for (i = 0; i < length - 1; ++i){
                for (j = 0; j < length - i - 1; ++j){
                        if (array[j] > array[j + 1]){
                                int tmp = array[j];
                                array[j] = array[j + 1];
                                array[j + 1] = tmp;
                        }
                }
        }
	printArr(*array);
}


void mergesort(int *liste, int groesse){
 
     if(groesse > 1){
  
         int haelfte1[groesse/2];
         int haelfte2[(groesse + 1)/2];
         int i;
         for(i = 0; i < groesse/2; ++i)
             haelfte1[i] = liste[i];
         for(i = groesse/2; i < groesse; ++i)
             haelfte2[i - groesse/2] = liste[i];
  
         MergeSort(haelfte1,groesse/2);
         MergeSort(haelfte2,(groesse + 1)/2);
  
         int *pos1 = &haelfte1[0];
         int *pos2 = &haelfte2[0];
         for(i = 0; i < groesse; ++i){
             if(*pos1 <= *pos2){
                 liste[i] = *pos1;
                 if (pos1 != &haelfte2[(groesse+1)/2 - 1]) { // pos1 nicht verändern, wenn der größte Wert mehrmals vorkommt
                     if(pos1 == &haelfte1[groesse/2 - 1]){
                         pos1 = &haelfte2[(groesse+1)/2 - 1];
                     }
                     else{
                         ++pos1;
                     }
                 }
             }
             else{
                 liste[i] = *pos2;
                 if(pos2 == &haelfte2[(groesse + 1)/2 - 1]){
                     pos2 = &haelfte1[groesse/2 - 1];
                 }
                 else{
                     ++pos2;
                 }
             }
         }
     }
 }

int rndom(){
	const int x=0, y=1000;
	srand (time (NULL));
	return ((rand () % ((y + 1) - x)) + x);
}

void printArr(int *arr){
	for(int i=0; i < sizeof(arr); i++)
		printf("%d\n", arr[i]);
	printf("\n");
}

int main (){

	//init variables
	int run=1, arrSize=0;
	int *arr = (int *) malloc(arrSize * sizeof(int));

	while(run){

		//print menu
		printf("_________________________________________________________\n");
		printf("1) Array−Groesse festlegen      4) Bubblesort (downwards)\n");
		printf("2) Zahlen von Tastatur einlesen 5) Mergesort\n");
		printf("3) Zufallszahlen erzeugen       6) Programm beenden\n");
		printf("_________________________________________________________\n");
		printf("Menuewahl: ");

		//choose menu
		int menuInput;
		scanf("%d", &menuInput);
		printf("\n");

		//case evaluation
		switch(menuInput) {
			case 1: arrSize = function1(); break;
			case 2: arr = function2(arrSize); break;
			case 3: arr = function3(arrSize); break;
			case 4: bubblesort(*arr, arrSize); break;
                	case 5: mergesort(*arr, arrSize); break;
                	case 6: printf("Programm wird beendet ...\n"); run = 0; break;
			default: printf("Diese Funktion existiert nicht. Wenn du das Programm beenden moechtest, gib '6' ein.\n"); break;
		}
	}
	return 0;
}
