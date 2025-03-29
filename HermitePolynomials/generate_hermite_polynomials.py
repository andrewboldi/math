#!/usr/bin/python3
from typing import Self

# Polynomial representation as array of coefficients.
class Polynomial:
    def __init__(self, coefs):
        self.coefs = coefs

    def __add__(self, other: Self):
        return Polynomial(new_coefs)

    # Do I want to return a new polynomial?
    # Do I want to edit the given polynomial?

    def return_polynomial(self):
        return lambda x: sum([self.coefs[i] * (x ** i) for i in range(len(self.coefs))])

    def add_polynomials(self, other: Self):
        # Add elementwise


class HermitePolynomial(Polynomial):
    def get_hermite_n(self, n: int):
        if n == 0:
            return [1]
        if n == 1:
            return [0, 2]

        # TODO: something is broken lol too tired to fix
        a = self.get_hermite_n(n - 1)
        a.insert(0, 0)
        b = self.get_hermite_n(n - 2)
        b.append(0)
        return [2 * (a_i - n * b_i) for a_i, b_i in zip(a, b)]

        #return [2 * (a_i - b_i) for a_i, b_i in zip((a := [get_hermite_n(n - 1)]).insert(0, 0) - (b := [x * n for x in get_hermite_n(n - 2)]))]
        #return lambda x: 2 * (x * get_hermite_n(n - 1)(x) - (n - 1) * get_hermite_n(n - 2)(x))

    # runs in O(n) time where n is the length of the polynomial
    def is_hermite(self):
        for i in range(len(coefs)):
            pass


    def get_next_hermite(self):
        return

fourxsquared = Polynomial([0, 0, 4])
func = fourxsquared.return_polynomial()
print(func(5))

herm = HermitePolynomial(fourxsquared)
print(herm.get_hermite_n(3))
