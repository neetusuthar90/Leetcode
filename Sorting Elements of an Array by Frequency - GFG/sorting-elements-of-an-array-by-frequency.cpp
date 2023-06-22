#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2){
    if(p1.first > p2.first){
        return true;
    }else if(p1.first == p2.first && p1.second < p2.second){
        return true;
    }
    return false;
}

vector<int> sortELem(int arr[], int size){
    vector<int> ans;
    
    unordered_map<int,int> mpp;
    for(int i = 0; i < size; i++){
        mpp[arr[i]]++;
    }
    
    vector<pair<int,int>> vec;
    for(auto it:mpp){
        vec.push_back({it.second, it.first});
    }
    
    sort(vec.begin(), vec.end(),comp);
    for(auto it:vec){
        int count = it.first;
        while(count--){
            ans.push_back(it.second);
        }
    }
    
    return ans;
}

int main() {
	//code
	
	int T;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int j = 0; j < n; j++){
	        cin >> arr[j];
	    }
	    
	    vector<int> v = sortELem(arr,n);
	    
	    for(int i = 0; i < n; i++){
	        cout << v[i] << " ";
	    }
	    cout << endl;
	}
	
	
	
	
	return 0;
}