class Country:
    def __init__(self,name=None,popu=1,area=1) -> None:
        self.__name=name
        self.__population=popu
        self.__area=area
        self.__cities_list={}
        self.__cityl=[]
    def add_city(self,name1,popu,area):
        d = "{:.2f}".format(popu/area)
        self.__cities[name1] = d
        self.__cityl.append(name1)
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
    def get_total_population(self):
        return self.__population
    def get_total_area(self):
        return self.__area
    def get_population_density(self):
        return "{:.2f}".format(self.__population/self.__area)
    def get_city(self,num):
        return f"{self.__cityl[num]}({self.__cities_list[num]})"
    def __str__(self):
        ds="{:.2f}".format(self.__population/self.__area)
        s = f"{self.__name} :\n"
        l = len(self.__cityl)
        for i in range(0,l):
            cl = str(self.__cityl[i])
            vl = str(self.__cities_list[i])
            if i<l-1:
                r = r+f"{cl}({vl})\n"
        s=s+r
        r1 = s+f"Population density = {ds}"
        return r1

                
