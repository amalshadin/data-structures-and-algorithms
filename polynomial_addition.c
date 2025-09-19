#include <stdio.h>
struct polynomial{
    int coe,exp;
};

int add(struct polynomial* poly1,int m,struct polynomial* poly2,int n,struct polynomial* polyR) {
    int i=0,j=0,k=0,sum;
    while (i<m && j<n){
        if ( (poly1+i)->exp == (poly2+j)->exp ){
            sum = (poly1+i)->coe + (poly2+j)->coe;
            if (sum != 0){
                (polyR+k)->coe = sum;
                (polyR+k)->exp = (poly1+i)->exp;
                k++;
            }
            i++;
            j++;
        }
        else if ((poly1+i)->exp > (poly2+j)->exp) {
            polyR[k++] = poly1[i++];
        }
        else{
            polyR[k++] = poly2[j++];
        }
    }

    while (i<m){
        polyR[k++] = poly1[i++];
    }
    while (j<n){
        polyR[k++] = poly2[j++];
    }
    return k;
}

int main(){
    int m,n,r,i;
    struct polynomial poly1[20],poly2[20],polyR[20];

    printf("Enter the number of terms in the polynomial 1 and 2 as m<space>n : ");
    scanf("%d %d",&m,&n);

    printf ("Enter polynomial 1 as coefficient<space>exponent\n");
    for (i=0;i<m;i++) {
        scanf ("%d %d",&((poly1+i)->coe),&((poly1+i)->exp));
    }

    printf ("Enter polynomial 2 as coefficient<space>exponent\n");
    for (i=0;i<n;i++) {
        scanf ("%d %d",&((poly2+i)->coe),&((poly2+i)->exp));
    }

    r = add(poly1,m,poly2,n,polyR);

    printf("The resultant polynomial is : \n");
    for (i=0;i<r;i++){
        i==r-1 ? printf("%dx^%d",(polyR+i)->coe,(polyR+i)->exp) : printf("%dx^%d + ",(polyR+i)->coe,(polyR+i)->exp);
    }

    return 0;
}