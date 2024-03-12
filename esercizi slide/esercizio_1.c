// scrivere una funzione che prende in ingresso 3 valori e ne restituisce la media

#include <stdio.h>

float AVG (int x, int y, int z){
    float Media;
    Media = x + y + z;
    Media = Media / 3;
    return Media;
} 

int main(){
    int x, y, z; 
    float media;

    printf("insert first value: ");
    scanf("%d",&x);
    printf("insert second value: ");
    scanf("%d",&y);
    printf("insert third value: ");
    scanf("%d",&z);

    media = AVG (x, y, z);

    printf( "the avg is : %f", media);
}