#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int f[maxn];
int n;
struct pii{
	int x,y,c;
	bool f;
};
pii a[maxn];
bool cmp(pii a,pii b){return a.y<b.y||(a.y==b.y&&a.x<b.x);}
map<pair<int,int>,int>M;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].f=a[i].x+a[i].y>=n;
		a[i].x=n-a[i].x;
		a[i].y++;
		if(a[i].x>a[i].y)swap(a[i].x,a[i].y);
		a[i].c=min(M[make_pair(a[i].x,a[i].y)]+=a[i].f^1,a[i].y-a[i].x+1);
	}sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(a[i].f){f[i]=f[i-1];continue;}
		int l=lower_bound(a+1,a+i,(pii){-1,a[i].x},cmp)-a-1;
		f[i]=max(f[i-1],f[l]+a[i].c);
	}cout<<n-f[n]<<endl;
	return 0;
}
