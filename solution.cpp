
// Problem: #3123. [Sdoi2013]森林
// Contest: UOJ
// URL: https://darkbzoj.tk/problem/3123
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

																																																	#ifndef OUUAN
																																																	#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
																																																	#endif
																																																	#include<bits/stdc++.h>

// #define int ll
// #define FAST_IOSTREAM 1

																																																	#define For(i,l,r)for(int i=(l),i##end=(r);i<=i##end;++i)
																																																	#define FOR(i,r,l)for(int i=(r),i##end=(l);i>=i##end;--i)
																																																	#define SON(i,u)for(int i=head[u];i;i=nxt[i])
																																																	#define BE(x)(x).begin(),(x).end()
																																																	#define BE1(x)((x).begin()+1),(x).end()
																																																	#define fi first
																																																	#define se second
																																																	#define pb push_back
																																																	#define eb emplace_back
																																																	#define pq priority_queue
																																																	#define min minOfDifferentTypes
																																																	#define max maxOfDifferentTypes
																																																	#define y1 why_is_there_a_function_called_y1
																																																	using namespace std;typedef long long ll;typedef vector<ll>vll;typedef vector<vll>vvll;typedef vvll v2ll;typedef vector<v2ll>v3ll;typedef vector<v3ll>v4ll;typedef unsigned long long ull;typedef vector<ull>vull;typedef vector<vull>vvull;typedef vvull v2ull;typedef vector<v2ull>v3ull;typedef vector<v3ull>v4ull;typedef long double ld;typedef vector<ld>vld;typedef vector<vld>vvld;typedef vvld v2ld;typedef vector<v2ld>v3ld;typedef vector<v3ld>v4ld;typedef pair<int,int>pii;typedef vector<int>vi;typedef vector<vi>vvi;typedef vvi v2i;typedef vector<vvi>v3i;typedef vector<v3i>v4i;typedef vector<bool>vb;typedef vector<vb>vvb;typedef vvb v2b;typedef vector<vvb>v3b;typedef vector<v3b>v4b;typedef vector<pii>vpii;typedef vector<vpii>vvpii;typedef vvpii v2pii;typedef vector<vvpii>v3pii;typedef vector<v3pii>v4pii;typedef vector<double>vd;typedef vector<vd>vvd;typedef vvd v2d;typedef vector<v2d>v3d;typedef vector<v3d>v4d;const double inf=1e121;const double eps=1e-10;mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());int randint(int l,int r){int out=rng()%(r-l+1)+l;return out>=l?out:out+r-l+1;}template<typename A,typename B>string to_string(pair<A,B>p);template<typename A,typename B,typename C>string to_string(tuple<A,B,C>p);template<typename A,typename B,typename C,typename D>string to_string(tuple<A,B,C,D>p);string to_string(const string&s){return'"'+s+'"';}string to_string(const char*s){return to_string((string)s);}string to_string(bool b){return(b?"true":"false");}string to_string(vector<bool>v){bool first=true;string res="{";for(int i=0;i<static_cast<int>(v.size());i++){if(!first){res+=", ";}first=false;res+=to_string(v[i]);}res+="}";return res;}template<size_t N>string to_string(bitset<N>v){string res="";for(size_t i=0;i<N;i++){res+=static_cast<char>('0'+v[i]);}return res;}template<typename A>string to_string(A v){bool first=true;string res="{";for(const auto&x:v){if(!first){res+=", ";}first=false;res+=to_string(x);}res+="}";return res;}template<typename A,typename B>string to_string(pair<A,B>p){return"("+to_string(p.first)+", "+to_string(p.second)+")";}template<typename A,typename B,typename C>string to_string(tuple<A,B,C>p){return"("+to_string(get<0>(p))+", "+to_string(get<1>(p))+", "+to_string(get<2>(p))+")";}template<typename A,typename B,typename C,typename D>string to_string(tuple<A,B,C,D>p){return"("+to_string(get<0>(p))+", "+to_string(get<1>(p))+", "+to_string(get<2>(p))+", "+to_string(get<3>(p))+")";}template<typename A,typename B,typename C,typename D,typename E>string to_string(tuple<A,B,C,D,E>p){return"("+to_string(get<0>(p))+", "+to_string(get<1>(p))+", "+to_string(get<2>(p))+", "+to_string(get<3>(p))+","+to_string(get<4>(p))+")";}void debug_out(){cerr<<endl;}template<typename Head,typename...Tail>void debug_out(Head H,Tail...T){cerr<<" "<<to_string(H);debug_out(T...);}template<typename T>struct is_pair{static const bool value=false;};template<typename T,typename U>struct is_pair<std::pair<T,U>>{static const bool value=true;};
																																																	#ifdef OUUAN
																																																	#define debug(...)cerr<<"["<<#__VA_ARGS__<<"]:",debug_out(__VA_ARGS__)
																																																	#else
																																																	#define debug(...)42
																																																	#endif
																																																	#ifdef int
																																																	const int INF=0x3f3f3f3f3f3f3f3fll;
																																																	#else
																																																	const int INF=0x3f3f3f3f;
																																																	#endif
																																																	#ifdef FAST_IOSTREAM
																																																	#define br cout<<'\n'
																																																	#define sp cout<<' '
																																																	#define fl cout.flush()
																																																	ll read(){ll x;cin>>x;return x;}template<typename T>void read(T&x){cin>>x;}template<typename T>void write(const T&x){cout<<x;}void write(double x){cout<<fixed<<setprecision(12)<<x;}
																																																	#else
																																																	#define br putchar('\n')
																																																	#define sp putchar(' ')
																																																	#define fl fflush(stdout)
																																																	template<typename T>typename enable_if<!is_integral<T>::value&&!is_pair<T>::value,void>::type read(T&x){cin>>x;}ll read(){char c;ll out=0,f=1;for(c=getchar();!isdigit(c)&&c!='-';c=getchar()){}if(c=='-'){f=-1;c=getchar();}for(;isdigit(c);c=getchar())out=(out<<3)+(out<<1)+c-'0';return out*f;}template<typename T>typename enable_if<is_integral<T>::value,T>::type read(T&x){char c;T f=1;x=0;for(c=getchar();!isdigit(c)&&c!='-';c=getchar()){}if(c=='-'){f=-1;c=getchar();}for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';return x*=f;}char read(char&x){for(x=getchar();isspace(x);x=getchar()){}return x;}double read(double&x){scanf("%lf",&x);return x;}template<typename T>typename enable_if<!is_integral<T>::value&&!is_pair<T>::value,void>::type write(const T&x){cout<<x;}template<typename T>typename enable_if<is_integral<T>::value,void>::type write(const T&x){if(x<0){putchar('-');write(-x);return;}if(x>9)write(x/10);putchar(x%10+'0');}void write(char x){putchar(x);}void write(double x){printf("%.12lf",x);}void write(ld x){cout<<fixed<<setprecision(12)<<x;}
																																																	#endif
																																																	template<typename T>typename enable_if<is_pair<T>::value,void>::type read(T&x){read(x.fi);read(x.se);}template<typename T>typename enable_if<is_pair<T>::value,void>::type write(const T&x){write(x.fi);sp;write(x.se);}template<typename T,typename...Args>void read(T&x,Args&...args){read(x);read(args...);}template<typename OutputIt,typename=typename enable_if<is_same<output_iterator_tag,typename iterator_traits<OutputIt>::iterator_category>::value||(is_base_of<forward_iterator_tag,typename iterator_traits<OutputIt>::iterator_category>::value&&!is_const<OutputIt>::value)>::type>void read(OutputIt __first,OutputIt __last){for(;__first!=__last;++__first)read(*__first);}template<typename InputIt,typename=typename enable_if<is_base_of<input_iterator_tag,typename iterator_traits<InputIt>::iterator_category>::value>::type>void wts(InputIt __first,InputIt __last){bool isFirst=true;for(;__first!=__last;++__first){if(isFirst)isFirst=false;else sp;write(*__first);}br;}template<typename InputIt,typename=typename enable_if<is_base_of<input_iterator_tag,typename iterator_traits<InputIt>::iterator_category>::value>::type>void wtb(InputIt __first,InputIt __last){for(;__first!=__last;++__first){write(*__first);br;}}template<typename T>void wts(const T&x){write(x);sp;}template<typename T>void wtb(const T&x){write(x);br;}template<typename T>void wte(const T&x){write(x);exit(0);}template<typename T,typename...Args>void wts(const T&x,Args...args){wts(x);wts(args...);}template<typename T,typename...Args>void wtb(const T&x,Args...args){wts(x);wtb(args...);}template<typename T,typename...Args>void wte(const T&x,Args...args){wts(x);wte(args...);}template<typename T1,typename T2>inline bool up(T1&x,const T2&y){return x<y?x=y,1:0;}template<typename T1,typename T2>inline bool dn(T1&x,const T2&y){return y<x?x=y,1:0;}template<typename T1,typename T2,typename T3>inline bool inRange(const T1&x,const T2&l,const T3&r){return!(x<l)&&!(r<x);}template<typename T1,typename T2>inline auto minOfDifferentTypes(const T1&x,const T2&y)->decltype(x<y?x:y){return x<y?x:y;}template<typename T1,typename T2>inline auto maxOfDifferentTypes(const T1&x,const T2&y)->decltype(x<y?y:x){return x<y?y:x;}template<typename T1,typename T2,typename T3>inline T1&madd(T1&x,const T2&y,const T3&modulo){return x=(ll)(x+y+modulo)%modulo;}template<typename T1,typename T2,typename T3>inline T1&mmul(T1&x,const T2&y,const T3&modulo){return x=(ll)x*y%modulo;}inline int modadd(int x,int y,int modulo){return x+y>=modulo?x+y-modulo:x+y;}inline int isinf(int x){return x<INF?x:-1;}inline void yesno(bool x){wtb(x?"Yes":"No");}

/* ------------------------------------------------------------------------------------------------------------------- */

struct Node;

Node *empty;

struct Node
{
	Node *ls = empty;
	Node *rs = empty;
	int siz = 0;
};

#define mid ((l + r) >> 1)

Node *insert(Node *u, int l, int r, int p)
{
	assert(u);
	Node *v = new Node();
	*v = *u;
	++v->siz;
	if (l == r - 1) return v;
	if (p < mid) v->ls = insert(v->ls, l, mid, p);
	else v->rs = insert(v->rs, mid, r, p);
	return v;
}

int kth(Node *u, Node *v, Node *lca, Node *pa, int l, int r, int k)
{
	assert(u);
	assert(v);
	assert(lca);
	assert(pa);
	if (l == r - 1) return l;
	int lsiz = u->ls->siz + v->ls->siz - lca->ls->siz - pa->ls->siz;
	if (lsiz >= k) return kth(u->ls, v->ls, lca->ls, pa->ls, l, mid, k);
	else return kth(u->rs, v->rs, lca->rs, pa->rs, mid, r, k - lsiz);
}

void destroy(Node *u)
{
	assert(u);
	if (u == empty) return;
	destroy(u->ls);
	destroy(u->rs);
	delete u;
}

#undef mid

signed main()
{
#ifdef FAST_IOSTREAM
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#endif
	
	read();
	
	int n, m, q;
	read(n, m, q);
	
	vi a(n + 1);
	read(BE1(a));
	
	vi lsh = a;
	sort(BE1(lsh));
	lsh.resize(unique(BE1(lsh)) - lsh.begin());
	For (i, 1, n) a[i] = lower_bound(BE1(lsh), a[i]) - lsh.begin();

	empty = new Node();
	empty->ls = empty->rs = empty;
	
	vector<Node *> rt(n + 1, empty);
	For (i, 1, n) rt[i] = insert(empty, 1, lsh.size(), a[i]);
	
	vi f(n + 1), siz(n + 1);
	For (i, 1, n) siz[i] = 1;
	
	function<int(int)> find = [&](int x)
	{
		return x == f[x] ? x : f[x] = find(f[x]);
	};
	
	vi dep(n + 1);
	vvi pa(n + 1, vi(17));
	
	function<int(int, int)> lca = [&](int u, int v)
	{
		if (dep[v] > dep[u]) swap(u, v);
		For (i, 0, 16)
		{
			if (((dep[u] - dep[v]) >> i) & 1)
			{
				u = pa[u][i];
			}
		}
		if (u == v) return u;
		FOR (i, 16, 0)
		{
			if (pa[u][i] != pa[v][i])
			{
				u = pa[u][i];
				v = pa[v][i];
			}
		}
		return pa[u][0];
	};
	
	vvi g(n + 1);
	
	auto link = [&](int u, int v)
	{
		if (siz[find(u)] < siz[find(v)]) swap(u, v);
		destroy(rt[find(v)]);
		
		g[u].pb(v);
		g[v].pb(u);
		
		siz[u] += siz[v];
		f[find(v)] = find(u);
		
		function<void(int, int)> dfs = [&](int x, int p)
		{
			dep[x] = dep[p] + 1;
			
			rt[x] = insert(rt[p], 1, lsh.size(), a[x]);
			
			pa[x][0] = p;
			For (i, 1, 16) pa[x][i] = pa[pa[x][i - 1]][i - 1];
			
			for (auto y : g[x])
			{
				if (y == p) continue;
				dfs(y, x);
			}
		};
		
		dfs(v, u);
	};
	
	auto query = [&](int x, int y, int k)
	{
		int l = lca(x, y);
		return kth(rt[x], rt[y], rt[l], rt[pa[l][0]], 1, lsh.size(), k);
	};
	
	while (m--) link(read(), read());
	
	int ans = 0;
	
	while (q--)
	{
		char op;
		int x, y;
		read(op, x, y);
		
		x ^= ans;
		y ^= ans;
		
		if (op == 'L') link(x, y);
		else wtb(ans = lsh[query(x, y, read() ^ ans)]);
	}
	
	return 0;
}
