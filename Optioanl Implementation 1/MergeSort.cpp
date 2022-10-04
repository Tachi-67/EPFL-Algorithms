#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int a[100005] = {0};
int n;
int templ[50005] = {0};
int tempr[50005] = {0};
void Merge(int *a, int l, int mid, int r){
	// Merging two arrays: a[l, ..., mid]; a[mid+1, ..., r]
	//memset(templ, 0, sizeof(templ));
	//memset(tempr, 0, sizeof(tempr));
	int idxl = 1, idxr = 1;
	int lidx, ridx;
	lidx = l, ridx = mid + 1;
	// Copying the subarrays to templ and tempr
	while(lidx <= mid){
		templ[idxl] = a[lidx];
		idxl++;
		lidx++;
	}
	while(ridx <= r){
		tempr[idxr] = a[ridx];
		idxr++;
		ridx++;
	}
	// Adding the sentinel value
	templ[idxl] = 100001;
	tempr[idxr] = 100001;
	// Doing the merge
	int Expected_Length = r - l + 1;
	int cnt = 1;
	int idx_ret = l;
	lidx = 1, ridx = 1;
	int added_value;
	while(cnt <= Expected_Length){
		if(templ[lidx] < tempr[ridx]){
			added_value = templ[lidx];
			lidx++;
		}
		else{
			added_value = tempr[ridx];
			ridx++;
		}
		a[idx_ret] = added_value;
		idx_ret++;
		cnt++;
	}
}
void MergeSort(int l, int r, int *a){
	if(l >= r) return; // Only deal with siuations where l < r
	int mid = floor((l + r) / 2);
	MergeSort(l, mid, a);
	MergeSort(mid + 1, r, a);
	Merge(a, l, mid, r);
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    MergeSort(1, n, a); 
    for(int i = 1; i <= n; i++)cout << a[i] << " ";
    return 0;
}
