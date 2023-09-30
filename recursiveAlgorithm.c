#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//function calcul
float puissance(float x, int n);
int factorielle(int x);
int detectPalyndrome(char phr[], int debut, int fin);
void deplacer(int nbDisk, int depart, int arrivee, int intermediaire);


//function call
void callPuissance();
void callFactorielle();
void callDetectPalyndrome();
void callHanoiTower();

int main(){
    callHanoiTower();
    return 0;
}

void callHanoiTower(){
    int nbd;
    printf("Entrer le nombre de disques: ");
    scanf("%d",&nbd);
    printf("cout deplacement\n");
    printf("-------------\n");
    deplacer(nbd,1,2,3);
}


void deplacer(int nbDisk, int depart, int arrivee, int intermediaire){
    static int coup = 0;
    if (nbDisk ==1){
        printf("%4d %d ->%d\n", ++coup,depart,arrivee);
    }
    else{
        deplacer(nbDisk-1, depart, intermediaire, arrivee);
        deplacer(1,depart,arrivee,intermediaire);
        deplacer(nbDisk-1, intermediaire,arrivee,depart);
    }
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


