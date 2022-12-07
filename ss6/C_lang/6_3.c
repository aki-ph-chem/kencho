#include <stdio.h>

int main(void){
    int age_min = 20, age_max = 36;
    while(age_max - age_min > 1){
        int mid = age_min + (age_max - age_min)/2;
        printf("Is the age less than %d ?(1/0)\n",mid);

        int q;
        scanf("%d",&q);
        if(q == 1)age_max = mid;
        else  age_min = mid; 
    }
    printf("Your age = %d\n",age_max);
}
