#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//function calcul
float puissance(float x, int n);
int factorielle(int x);
int detectPalyndrome(char phr[], int debut, int fin);


//function call
void callPuissance();
void callFactorielle();
void callDetectPalyndrome();


int main(){
    callDetectPalyndrome();
    return 0;
}

void callDetectPalyndrome(){
    char phrase[100];
    int i=0, isPalindrome;
    printf("Entrer une phrase : ");
    while((phrase[i++] = getchar()) != '\n');
    phrase[--i] = '\0';
    isPalindrome = detectPalyndrome(phrase,0,i-1);
    if (isPalindrome){
        printf("C'est un palindrome");
    }
    else{
        printf("Ce n'est pas un palindrome\n");
    }
}




int detectPalyndrome(char phr[], int debut, int fin){
    static int compteur = 0;
    while (phr[debut] == ' '){
        debut++;
    }
    while( phr[fin] == ' '){
        fin--;
    }
    printf("appel=%d",++compteur);
    printf("début=%d '%c' ",debut, phr[debut]);
    printf("fin=%d '%c'",fin, phr[fin]);
    if (debut>fin){
        return 1;
    }
    else if (phr[debut] != phr[fin]){
        return 0;
    }
    else{
        return detectPalyndrome(phr,debut+1, fin -1);
    }

}




void callFactorielle(){
    int m;
    printf("entrer le nombre qui subit le produit factorielle => ");
    scanf("%d", &m);//call 
    int resultat = factorielle(m);
    printf("%d", resultat);
}

int factorielle(int x){
    int resultat;
    if( x == 1){
        resultat = 1;
    }
    else{
        resultat = factorielle(x-1)*x;
    }
    return resultat;

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


