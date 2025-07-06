vector<pair<int, int>> primeFactorization(int x, vector<int>& spf) {
    vector<pair<int, int>>ans;
    while (x != 1) {
        int prime = spf[x];
        int cnt = 0;
        while (x % prime == 0) {
            cnt++;
            x /= prime;
        }
        ans.push_back({ prime,cnt });
    }
    return ans;
}
vector<int>ShortestPrimeFactor(int maxN){
    vector<bool>Prime(maxN, true);
    vector<int>spf(maxN, 1e9);

    for (ll i = 2; i < maxN;i++) {
        if (Prime[i]) {
            spf[i] = i;
            for (ll j = i * i;j < maxN;j += i) {
                Prime[j] = false;
                spf[j] = min(spf[j], (int)i);
            }
        }
    }
    return spf;
}
