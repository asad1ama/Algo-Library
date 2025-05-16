#include<bits/stdc++.h>
using namespace std;

struct union_find{
	vector<int>parent;
	vector<int>size;
	int components=0;

	union_find(int n=-1){
	    if(n>=0){
	       init(n);
	    }
	}

	void init(int n){
	   parent.resize(n+1);
	   iota(parent.begin(),parent.end(),0);
	   size.assign(n+1,1);
	   components=n;
	}

	int find(int x){
	   if(x==parent[x]){
		return x;
	   }
	   return parent[x]=find(parent[x]);
	}

	bool unite(int x,int y){
        x=find(x);
	    y=find(y);

	    if(x==y){
	    	return false;
	    }
	    
	    if(size[x]<size[y]){
		   swap(x,y);
	    }

	    parent[y]=x;
	    size[x]+=size[y];
	    components--;
	    return true;
	}
};		
