#include<iostream>
using namespace std;
void test(int arr1[], int arr2[], int n){
  
  int arr3[n];
  for (int i=0;i<n; i++){
    arr3[i]=arr1[i]+arr2[i];
    cout<<arr3[i]<<endl;
  }

 

}
int main(){
  int a[5]={1,2,3,4,5};
  int b[5]={1,2,3,4,5};
  int n=sizeof(a)/sizeof(a[0]);
  cout<<n<<endl;
  test(a,b,n);     
  }
