class QuadraticEquation:
    def __init__(self, coeff_a=1, coeff_b=1, coeff_c=1):
        self.__coeff_a = coeff_a
        self.__coeff_b = coeff_b
        self.__coeff_c = coeff_c
    
    def get_coeff_a(self):
        return self.__coeff_a
    
    def get_coeff_b(self):
        return self.__coeff_b
    
    def get_coeff_c(self):
        return self.__coeff_c
    def get_discriminant(self):
        
        return self.__coeff_b**2 - 4*self.__coeff_a*self.__coeff_c
    def has_solution(self):
        if self.__coeff_b**2 - 4*self.__coeff_a*self.__coeff_c<0:
            return False
        else:
            return True
    def get_root1(self):
        panduan = self.__coeff_b**2 - 4*self.__coeff_a*self.__coeff_c
        r1 = (-self.__coeff_b + panduan**(1/2))/2*self.__coeff_a
        if panduan >=  0:
        
            return r1
    def get_root2(self):
        panduan = self.__coeff_b**2 - 4*self.__coeff_a*self.__coeff_c
        r2 = (-self.__coeff_b - panduan**(1/2))/2*self.__coeff_a
        if panduan >=  0:
            return r2
equation1 = QuadraticEquation(4, 4, 1)
print(equation1.has_solution())
print(equation1.get_root1(), equation1.get_root2())