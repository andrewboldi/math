#include <stdio.h>
#include <math.h>
#include <gmp.h>


int main() {
    mpf_set_default_prec(8192);
    int irange = 1;
    int counter = 0;
    mpf_t ans;   mpf_init(ans);   mpf_set_si(ans, 1);
    mpf_t tmp;   mpf_init(tmp);   mpf_set_si(tmp, 0);
    mpf_t tmp2;  mpf_init(tmp2);  mpf_set_si(tmp2, 0);
    mpf_t tmp3;  mpf_init(tmp3);  mpf_set_si(tmp3, 0);
    mpf_t i;     mpf_init(i);     mpf_set_si(i, 1);
    mpf_t one;   mpf_init(one);   mpf_set_si(one, 1);
    mpf_t qt;    mpf_init(qt);    mpf_set_si(qt, 0.25);
    mpf_t range; mpf_init(range); mpf_set_si(range, 2023);

    while (mpf_cmp(range, i)) {
        mpf_add(tmp, i, one); // x + 1
	mpf_mul(tmp3, i, i); // x ** 2
	mpf_add(tmp2, tmp3, one); // x ** 2 + 1
        mpf_div(tmp, tmp, tmp2); // (x + 1)/(x ** 2 + 1)
        mpf_add(tmp, tmp, qt); // (x+1)/(x ** 2 + 1) + 1/4
	mpf_mul(ans, ans, tmp);
        printf("\rProgress: %.4f %%", 100*counter/(pow(10, irange)));
        counter += 1;
        fflush(stdout);
	mpf_add(i, i, one);
    }
    mpf_div(ans, one, ans);

    mpf_clears(tmp, i, one, range, tmp2, NULL); 
    gmp_printf("%.Ff \n", ans);
    mpf_clears(ans, qt, tmp3, NULL); 

    return 0;
}
