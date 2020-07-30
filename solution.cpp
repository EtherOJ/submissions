#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int N=1<<18;
const double PI=acos(-1);
const double eps=1e-6;

struct cp
{
	double re,im;
	cp(double _re=0.0,double _im=0.0) { re=_re; im=_im; }
	cp operator+(const cp& b) const { return cp(re+b.re,im+b.im); }
	cp operator-(const cp& b) const { return cp(re-b.re,im-b.im); }
	cp operator*(const cp& b) const { return cp(re*b.re-im*b.im,re*b.im+im*b.re); }
} a[N],b[N];

void fft(cp* A,int type);

int n,lim,L,r[N],maxx;

int main()
{
	int i;
	
	scanf("%d",&n);
	
	for (i=0;i<n;++i) scanf("%lf%lf",&a[i].re,&b[n-i-1].re);
	
	for (lim=0,L=1;L<=2*n;++lim,L<<=1);
	for (i=1;i<L;++i) r[i]=(r[i>>1]>>1)|((i&1)<<(lim-1));
	
	fft(a,1);
	fft(b,1);
	
	for (i=0;i<L;++i) a[i]=a[i]*b[i];
	
	fft(a,-1);
	
	for (i=n-1;i<=2*n-2;++i) printf("%d\n",int(a[i].re+0.5));
	
	return 0;
}

void fft(cp* A,int type)
{
	int i,j,k;
	for (i=1;i<L;++i) if (i<r[i]) swap(A[i],A[r[i]]);
	for (i=1;i<L;i<<=1)
	{
		cp w1(cos(PI/i),type*sin(PI/i));
		for (j=0;j<L;j+=2*i)
		{
			cp w(1,0);
			for (k=j;k<i+j;++k,w=w*w1)
			{
				cp t=A[k+i]*w;
				A[k+i]=A[k]-t;
				A[k]=A[k]+t;
			}
		}
	}
	if (type==-1) for (i=0;i<L;++i) A[i].re=A[i].re/L;
}
