#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds;
//#pragma GCC optimize("Ofast") //#pragma GCC optimize "unroll-loops" //#pragma GCC optimize "prefetch-loop-arrays" //#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#define foru(i,a,b) for(int i=(a);i<(b);i++)
#define ford(i,a,b) for(int i=(a);i>=(b);i--)
#define fori(a,b) foru(i,a,b)
#define forj(a,b) foru(j,a,b)
#define fork(a,b) foru(k,a,b)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
#define pb push_back
#define eb emplace_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcount
#define clz __builtin_clz
#define clzll __builtin_clz
#define ctz __builtin_ctz
#define ctzll __builtin_ctz
#define P2(x) (1LL<<(x))
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)
#if __SIZEOF_INT128__
    typedef __int128_t i128; typedef __uint128_t ui128;
#else
    typedef long long i128; typedef unsigned long long ui128;
#endif
typedef long long ll;  typedef unsigned long long ull; typedef int8_t byte; typedef long double lld;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; typedef pair<lld,lld> pdd;
template<typename T1> using ordered_set=tree<T1,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T1,typename T2> using ordered_map=tree<T1,T2,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T1,typename T2> using hashmap=gp_hash_table<T1,T2>;
inline ll gcd(ll a, ll b){return b==0?a:gcd(b,a%b);}
inline ll fpow(ll a,ll b){if(b==0) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%1000000007*a%1000000007; return t*t%1000000007;}
const ll SEED=chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
mt19937 randgen(SEED); inline int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} inline ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;} template<class T,class...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;} template<class T,class...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{template<class T1,class T2> size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}};
struct chash{int operator()(int x) const { return x ^ SEED; }};

const int N=P2(10),M=1e9+7;
struct SegTree{
    struct node{
        ll v=-INF,lz=0;
    } seg[2*N];
    void pull(int x){
        seg[x].v=max(seg[2*x].v,seg[2*x+1].v);
    }
    void push(int x){
        if(!seg[x].lz) return;
        if(x<N) fori(0,2) seg[2*x+i].lz+=seg[x].lz;
        seg[x].v+=seg[x].lz;
        seg[x].lz=0;
    }
    void build(ll *arr){
        fori(0,N) seg[i+N].v=arr[i];
        ford(i,N-1,1) pull(i);
    }
    void upd(int lo,int hi,int v,int l=0,int r=N-1,int x=1){
        push(x);
        if(hi<l||r<lo) return;
        if(lo<=l&&r<=hi){
            seg[x].lz+=v; push(x);
            return;
        }
        int mid=l+r>>1;
        upd(lo,hi,v,l,mid,2*x); upd(lo,hi,v,mid+1,r,2*x+1); pull(x);
    }
    ll query(int lo,int hi,int l=0,int r=N-1,int x=1){
        if(hi<l||r<lo) return -INF;
        push(x);
        if(lo<=l&&r<=hi) return seg[x].v;
        int mid=l+r>>1;
        return max(query(lo,hi,l,mid,2*x),query(lo,hi,mid+1,r,2*x+1));
    }
} st;
int arr[N]={0,2,5,3};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    st.build(arr);
    cout<<st.query(1,100)<<endl;
    st.upd(6,7,100);
    cout<<st.query(1,2)<<endl;
    cout<<st.query(2,2)<<endl;
    cout<<st.query(3,6)<<endl;
    cout<<st.query(1,100)<<endl;
    return 0;
}
/**

*/
