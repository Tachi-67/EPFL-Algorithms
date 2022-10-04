#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int x[100005] = {0};
int m[100005] = {0};
int n,q;
int bsearch(int l, int r, int key, int *a){
	//Find, in array a, the first element that is no bigger than key
	while(l < r){
		int mid = floor(l + r) / 2;
		if(a[mid] > key) r = mid;
		else l = mid + 1;
	} 
	return l;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x[i];
	sort(x+1, x+n+1);
	cin>>q;
	for(int i=1;i<=q;i++)cin>>m[i];
	for(int i=1;i<=q;i++){
		int money = m[i];
		int shop = bsearch(1, n, money, x);
		if(x[shop] > money) shop--;
		cout<<shop<<endl;
	}
return 0;
}

