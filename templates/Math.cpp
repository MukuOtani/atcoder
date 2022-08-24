// aのp乗を求める関数
ll mpow(ll a, ll b){
	if(b==0){
		return 1;
	}else if(b%2==0){
		ll memo = mpow(a,b/2);
		return memo*memo%MOD;
	}else{
		return mpow(a,b-1)*a%MOD;
	}
}

// aCbを求める関数
ll mod_combination(int a, int b){
  if(b>a-b) return mod_combination(a,a-b);
  ll ansMul = 1, ansDiv = 1;
  rep(i, b) {
    ansMul *= (a-i); ansDiv *= (i+1);
    ansMul %= MOD; ansDiv %= MOD;
  }
  ll ans = ansMul*mpow(ansDiv, MOD-2)%MOD;
  return ans;
}

// GCD,LCMを求める関数
ll gcd(ll a, ll b){
  if(b==0) return a;
  else return gcd(b, a%b);
}
ll lcm(ll a, ll b){
	return a/gcd(a,b)*b;
}

vector<ll> enum_div(ll n){ //nの約数を列挙
	vector<ll> ret;
	for(ll i=1 ; i*i<=n ; ++i){
		if(n%i==0){
			ret.push_back(i);
			if(i!=1 && i*i!=n) ret.push_back(n/i);
		}
	}
	return ret;
}


// 素数かどうかの判定
bool IsPrime(int num){
    if(num<2) return false;
    else if(num==2) return true;
    else if(num%2==0) return false; // 偶数はあらかじめ除く
    double sqrtNum = sqrt(num);
    for(int i=3; i<=sqrtNum; i+=2){
        if(num%i==0)　return false;
    }
    return true;
}

//////////////////////////////////////////////////////////////////
// 階乗や組合わせの場合の数を求める
ll mpow(ll a, ll b){
  if(b==0) return 1;
  else if(b%2==0){ll memo = mpow(a,b/2); return memo*memo%MOD;}
  else return mpow(a,b-1)*a%MOD;
}
ll lpow(ll a, ll b){
  if(b==0) return 1;
  else if(b%2==0){ll memo = lpow(a,b/2); return memo*memo;}
  else return lpow(a,b-1)*a;
}
ll gcd(ll a, ll b){
  if(b==0) return a;
  else return gcd(b,a%b);
}
vector<ll> kaijo_memo;
ll kaijo(ll n){
  if(kaijo_memo.size()>n) return kaijo_memo[n];
  if(kaijo_memo.size()==0) kaijo_memo.push_back(1);
  while(kaijo_memo.size()<=n) kaijo_memo.push_back(kaijo_memo[kaijo_memo.size()-1]*kaijo_memo.size()%MOD);
  return kaijo_memo[n];
}
vector<ll> gyaku_kaijo_memo;
ll gyaku_kaijo(ll n){
  if(gyaku_kaijo_memo.size()>n) return gyaku_kaijo_memo[n];
  if(gyaku_kaijo_memo.size()==0) gyaku_kaijo_memo.push_back(1);
  while(gyaku_kaijo_memo.size()<=n) gyaku_kaijo_memo.push_back(gyaku_kaijo_memo[gyaku_kaijo_memo.size()-1]*mpow(gyaku_kaijo_memo.size(),MOD-2)%MOD);
  return gyaku_kaijo_memo[n];
}

ll nCr(ll n, ll r){
  if(n==r) return 1;
  if(n<r||r<0) return 0;
  ll ret=1;
  if(n<=1e7){
    ret*=kaijo(n); ret%=MOD;
    ret*=gyaku_kaijo(r); ret%=MOD;
    ret*=gyaku_kaijo(n-r); ret%=MOD;
  }else{
    rep(i,r){
      ret*=n-i; ret%=MOD;
      ret*=mpow(r-i,MOD-2); ret%=MOD;
    }
  }
  return ret;
}

/////////////////////////////////////////////////////////////////////
// nが小さいときの組合せ
ll c[51][51];

void comb_table(int n){
	rep(i,n+1){
		rep(j,i+1){
			if(j==0||j==i){
				c[i][j]=1LL;
			}else{
				c[i][j]=(c[i-1][j-1]+c[i-1][j]);
			}
		}
	}
}
