class Book:
    def __init__(self,code,title):
        self.__code = code
        self.__title = title
        self.__status = True
    def get_book_title(self):
        return self.__title
    def get_book_code(self):
        return self.__code
    def is_available(self):
        return self.__status