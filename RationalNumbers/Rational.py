class Rational():
    def __init__(self, num, denom):
        self.num = num
        self.denom = denom
    
    def __add__(self, r):
        return Rational(self.__get_num() * r.__get_denom() + r.__get_num() * self.__get_denom(), self.__get_denom() * r.__get_denom())
    
    def __sub__(self, r):
        return Rational(self.__get_num() * r.__get_denom() - r.__get_num() * self.__get_denom(), self.__get_denom() * r.__get_denom())

    def __mul__(self, r):
        return Rational(self.__get_num() * r.__get_num(), self.__get_denom() * r.__get_denom())

    def __truediv__(self, r):
        return Rational(self.__get_num() * r.__get_denom(), self.__get_denom() * r.__get_num())

    def __floordiv__(self, r):
        return self.__truediv__(r)

    def __pow__(self, p):
        return Rational(self.get_num() ** p, self.get_denom() ** p)

    def __get_num(self):
        return self.num

    def __get_denom(self):
        return self.denom
    
    def __gcd(self):
        num = self.get_num()
        denom = self.get_denom()
        raise NotImplementedErorr("Implement GCD lol")
    
    def __simplify(self):
        gcd = self.__gcd()
        return Rational(self.get_num() // gcd, self.get_denom() // gcd)
    
    def __str__(self):
        return f"<Rational> {self.__get_num()} / {self.__get_denom()}"
