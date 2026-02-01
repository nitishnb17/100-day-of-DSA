
#include <stdio.h>
int insert(){

    
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("At what position you want to get the elemnt inserted (1based index)");
    n++;
    int pos , ele ;
    scanf("%d",&pos);
    printf("enter the value of element :");
    scanf("%d",&ele);
    
    for(int i=n-1;i>=pos-1;i--){
        arr[i]=arr[i-1];
    }
    arr[pos-1]=ele;
    

   
    printf("Array after insertion:\n");
    for(int i = 0 ; i<=n-1 ; i++){
        printf("%d " , arr[i]);
    }
    
}
int main() {
    insert();

    return 0;
}
