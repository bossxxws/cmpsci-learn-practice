class City:
    def __init__(self,name=None,popu=1,area=1) -> None:
        self.__name=name
        self.__population=popu
        self.__area=area
    def set_name(self,name):
        self.__name=name
    def set_population(self,popu):
        if popu>0:
            self.__population=popu
    def set_area(self,area):
        if area>0:
            self.__area = area
    def get_name(self):
        return self.__name
    def get_population(self):
        return self.__population
    def get_area(self):
        return self.__area
    def get_population_density(self):
        return self.__population/self.__area
    def __str__(self):
        s = f"{self.__name}"
        k = "{:.2f}".format(self.__population/self.__area,2)
        k =str(k)
        k = f"({k})"
        r = s+k
        return r

    
    
        
        