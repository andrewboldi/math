#include <stdio.h>
#include <gmp.h>

int main() {
    mpf_t ans;   mpf_init(ans);   mpf_set_ui(ans, 0);
    mpf_t tmp;   mpf_init(tmp);   mpf_set_ui(tmp, 0);
    mpf_t i;     mpf_init(i);     mpf_set_ui(i, 1);
    mpf_t one;   mpf_init(one);   mpf_set_ui(one, 1);
    mpf_t range; mpf_init(range); mpf_set_ui(range, 10);
    mpz_t tmp2;  mpz_init(tmp2);  mpz_set_ui(tmp2, 0);

    while (mpf_cmp(range, i)) {
        mpf_set_ui(tmp, 0);
        mpf_div(tmp, one, i);
        // mpf_add(ans, ans, tmp);
        mpf_add(i, i, one);
        gmp_printf("%Zd \n", tmp);
    }



    return 0;
}
