#include <stdio.h>


#include <stdlib.h>

int isPrime(int n){
  if(n<=1) return 0;
  if(n==2) return 1;
  
  for(int i=2;i*i<=n;i++){
    if(n%i==0) return 0;
  }
  
  return 1;
}


int primedig(int n){
  int cnt = 0;
  while(n){
    int r = n%10;
    cnt+= (isPrime(r));
    n = n/10;
  }
  return cnt;
}


void merge(int a[],int n,int b[],int m,int merged[]){
  int i = 0;
  int j = 0;
  int k = 0;
  while(i<n && j<m){
    int x = isPrime(a[i]);
    int y = isPrime(b[j]);
    
    if((x==1 && y==0) || (x==0 && y==1)){
      if(x){
        merged[k++] = a[i++];
      }
      else{
        merged[k++] = b[j++];
      }
    }

    else if(x && y){
      if(a[i]<=b[j]){
        merged[k++] = a[i++];
      }
      else{
        merged[k++] = b[j++];
      }
      
    }

    else{
      int digl = primedig(a[i]);
      int digr = primedig(b[j]);
      

      if(digl < digr){
        merged[k++] = a[i++];
      }
      

      else if(digl > digr){
        merged[k++] = b[j++];
      }
      

      else{
        if(a[i]<=b[j]){
        merged[k++] = a[i++];
        }
        else{
          merged[k++] = b[j++];
        }
      }
      
    } 
  }
  

  while(i<n){
    merged[k++] = a[i++];
  }
  while(j<m){
    merged[k++] = b[j++];
  }
  
}

void customMergeSort(int array[],int n){
  if(n==1) return;

  int n1 = n/2;
  int n2 = n-n1;
  
  int a[n1];
  int b[n2];

  for(int i=0;i<n1;i++){
    a[i] = array[i];
  }

  for(int i=0;i<n2;i++){
    b[i] = array[n1+i];
  }
  
  customMergeSort(l,n1);
  customMergeSort(r,n2);

  merge(l,n1,r,n2,array);
}


int main(){
    int n = 32768;
    int array[n];
    
    for(int i=0;i<n;i++){
        array[i] = (rand()%n)+1;
    }
    
    customMergeSort(array,n);
  
    for(int i=0;i<n;i++){
      printf("%d, ",array[i]);
    }
    
    return 0;
}