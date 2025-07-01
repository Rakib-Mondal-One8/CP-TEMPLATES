vector<bool> primeSieve(ll n) {
    vector<bool>Prime(n + 1, true);
    Prime[0] = Prime[1] = false;

    for (ll i = 2;i <= n;i++) {
        if (Prime[i]) {
            for (ll j = i * i; j <= n;j += i)
                Prime[j] = false;
        }
    }
    return Prime;
}