
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void main(){
int a[10] = { 31, 0, 25, 0, 0, 17,21,0,0,15 };
vector <int> a1, a2(10);
for( int k = 0 ; k < 10 ; k ++)
    a1.push_back(a[k]);

copy (a1.begin(), a1.end(), a2.begin(), 0);


for ( unsigned int j = 0 ; k< a.size() ; j ++){
    if(a[j]==0) continue;
    cout << a[j] << ", ";
    cout << endl;
}
}
