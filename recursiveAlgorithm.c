#include <stdio.h>



float puissance(float x, int n);
void callPuissance();


int main(){
    callPuissance();
}



void callPuissance(){
    float nb, res;
    int m;
    printf("Entrer le nombre et sa puissance");
    scanf("%f %d", &nb, &m);
    res = puissance(nb,m);
    printf("%5.2f puissance %d = %10.4f\n", nb, m,res);

}


float puissance(float x, int n){
    float resultat;
    if(n == 0){
        resultat = 1;
    }
    else{
        resultat = x*puissance(x,n-1);
    }
    return resultat;
}


