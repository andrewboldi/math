#include <stdio.h>
#include <math.h>
#include <gmp.h>
#include "ln2.h"


int main() {
    mpf_set_default_prec(64);
    int irange = 6;
    int counter = 0;
    mpf_t ans;   mpf_init(ans);   mpf_set_si(ans, 0);
    mpf_t tmp;   mpf_init(tmp);   mpf_set_si(tmp, 0);
    mpf_t i;     mpf_init(i);     mpf_set_si(i, 1);
    mpf_t one;   mpf_init(one);   mpf_set_si(one, 1);
    mpf_t range; mpf_init(range); mpf_set_si(range, pow(10, irange));
    mpf_t tmp2;  mpf_init(tmp2);  mpf_set_d(tmp2, solveLn2());

    while (mpf_cmp(range, i)) {
        mpf_div(tmp, one, i);
        mpf_add(ans, ans, tmp);
        mpf_add(i, one, i);
        printf("\rProgress: %.4f %%", 100*counter/(pow(10, irange)));
        counter += 1;
        fflush(stdout);
    }

    mpf_mul_ui(tmp2, tmp2, irange);
    mpf_sub(ans, ans, tmp2);


    mpf_clears(tmp, i, one, range, tmp2, NULL); 
    gmp_printf("%.Ff \n", ans);

    return 0;
}
