#include <iostream>
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<string, string> P;

int main(int argc, char *argv[])
{
  int n, b;
  long a[200000];
  long sum=0;
  cin >> n;
  for(long i=0;i<n;i++){
    cin >> a[i];
    a[i]-=(i+1);
  }
  sort(a, a+n);
  if(n%2==0){
    if(abs(a[n/2-1])>abs(a[n/2])){
      b=a[n/2-1];
    }else{
      b=a[n/2];
    }
  }else{
    b=a[n/2];
  }
  for(int i=0;i<n;i++){
    a[i]-=b;
    a[i]=abs(a[i]);
    sum+=a[i];
  }

  cout << sum << endl;
  return 0;
}
