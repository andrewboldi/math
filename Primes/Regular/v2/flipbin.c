#include <stdlib.h>
#include <stdio.h>
#define ll long long

ll flipbin(ll pos) {
    return 4294967295 - (1 << (31 - (pos % 32)));
}

void main() {
//    int primes[4];
    ll a = 8;
    ll b = 24;
    ll c = 23981;
    ll d = 13231898;

//    primes = [a, b, c, d];

    printf("a in beginning: %d.  a in flipbin: %lld\n", a, flipbin(a));
    printf("b in beginning: %d.  b in flipbin: %lld\n", b, flipbin(b));
    printf("c in beginning: %d.  c in flipbin: %lld\n", c, flipbin(c));
    printf("d in beginning: %d.  d in flipbin: %lld\n", d, flipbin(d));


    _exit;
}
