#include <iostream>
#include <cstring>
using namespace std;

int main(void){
	double r, w, c, g;
  int n;
	cin >> r >> w >> c >> g;
  while(0!=r+w+c+r){
    n=0;
    while(((r+n*g)/w)<c){
      n++;
    }
    cout << n <<endl;
  	cin >> r >> w >> c >> g;
  }
  return 0;
}
