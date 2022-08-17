#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[])
{
int size;

if(argc==1){
        printf("Enter a size: ");
	scanf("%d", &size);
}

if(argc>2){
        printf("To many arguments, input an Integer\n");
return 0;
}

if(argc==2){
size = atoi(argv[1]);
}

if(size<=0) {
	printf("An incorrect triangle size was inputted. The size must be greater than 0 and an integer number. Syntax: ./triangles SIZE");
	return 0;
}
printf("Size : %d",size);
printf("\n");

    int i, j, k, l;
  l = size-1;
    for(i=1; i<=size; i++){
        for(j=1; j<=l; j++){
            printf(" ");
        }
        l--;
        for(k=1; k<=i; k++){
                printf("*");
        }
        printf("\n");
    }
    return 0; 
}
    
    
