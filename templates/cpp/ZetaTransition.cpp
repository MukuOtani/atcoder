inline int ilog2(int x){
    int y = 0;
    while (x > 1) {
        x /= 2;
        ++y;
    }
    return y;
}

template <typename T>
vector<T> zeta(vector<T> f, int type){
    int N = f.size(), K = ilog2(N);
    for(int i=0,b=1; i<K; ++i,b<<=1){ // m = (1<<i)
        for(int j=0; j<N; ++j)
            switch (type) {
            case 1:
                if(!(j&b)) f[j] += f[j|b];
                break;
            case 2:
                if(j&b) f[j] += f[j^b];
                break;
            case 3:
                if(!(j&b)) f[j] -= f[j|b];
                break;
            case 4:
                if(j&b) f[j] -= f[j^b];
                break;
            }
    }
    return f;
}
