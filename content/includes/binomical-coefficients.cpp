#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int MOD=1e9+7;

struct modint {
    int val;
    modint inv() const{
        int tmp,a=val,b=MOD,x=1,y=0;
        while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);
        return modint(x);
    }
public:
    modint():val(0){}
    modint(ll x){if((val=x%MOD)<0)val+=MOD;}
    modint pow(ll t){modint res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;}return res;}
    modint& operator+=(const modint& x){if((val+=x.val)>=MOD)val-=MOD;return *this;}
    modint& operator-=(const modint& x){if((val+=MOD-x.val)>=MOD)val-=MOD; return *this;}
    modint& operator*=(const modint& x){val=(ll)val*x.val%MOD; return *this;}
    modint& operator/=(const modint& x){return *this*=x.inv();}
    bool operator==(const modint& x) const{return val==x.val;}
    bool operator!=(const modint& x) const{return val!=x.val;}
    bool operator<(const modint& x) const{return val<x.val;}
    bool operator<=(const modint& x) const{return val<=x.val;}
    bool operator>(const modint& x) const{return val>x.val;}
    bool operator>=(const modint& x) const{return val>=x.val;}
    modint operator+(const modint& x) const{return modint(*this)+=x;}
    modint operator-(const modint& x) const{return modint(*this)-=x;}
    modint operator*(const modint& x) const{return modint(*this)*=x;}
    modint operator/(const modint& x) const{return modint(*this)/=x;}
};

struct factorial {
    vector<modint> Fact, Finv;
public:
    factorial(int _n): Fact(_n+1), Finv(_n+1) {
        Fact[0]=modint(1); for (int i = 0; i < _n; ++i) Fact[i+1]=Fact[i]*(i+1);
        Finv[_n]=modint(1)/Fact[_n]; for (int i = _n; i > 0; --i) Finv[i-1]=Finv[i]*i;
    }
    modint fact(int n,bool inv=0) { if (inv) return Finv[n]; else return Fact[n]; }
    modint nPr(int n,int r){ if (n<0||n<r||r<0) return modint(0); else return Fact[n]*Finv[n-r]; }
    modint nCr(int n,int r){ if (n<0||n<r||r<0) return modint(0); else return Fact[n]*Finv[r]*Finv[n-r]; }
};

int main() {
  factorial fact(1000010);
  // 6C3 % (1e9+7) = 20
  cout << "6C3: " << fact.nCr(6,3).val << endl;
  // 666C390 % (1e9+7) = 9951876
  cout << "666C390: " << fact.nCr(666,390).val << endl;
}
