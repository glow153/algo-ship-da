#include <stdio.h>
typedef struct _sbj{
    int k;
    int s;
}sbj;
void swap(sbj* a, sbj* b){
    sbj tmp = *a;
    *a = *b;
    *b = tmp;
}
void sort(sbj* arr, int len){
    int swaped;
    while(1){
        swaped = 0;
        for(int i=0;i<len-1;i++){
            if(arr[i].s<arr[i+1].s){
                swap(&arr[i],&arr[i+1]);
                swaped = 1;
            }
        }
        if(!swaped)
            break;
    }
}

int main(){
    int n, t, ret=0;
    sbj arr[100];
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;i++)
        scanf("%d%d",&arr[i].k,&arr[i].s);

    //print
    // for(int i=0;i<n;i++)
    //  printf("%d %d\n",arr[i].k,arr[i].s);

    sort(arr, n);

    //print
    // for(int i=0;i<n;i++)
    //  printf("%d %d\n",arr[i].k,arr[i].s);

    for(int i=0;i<n;i++){
        if(t>=arr[i].k){
            t-=arr[i].k;
            ret+=arr[i].s;
        } else {
            continue;
        }
    }

    printf("%d\n",ret);
    return 0;
}