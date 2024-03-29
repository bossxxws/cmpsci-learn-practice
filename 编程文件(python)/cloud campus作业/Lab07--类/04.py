class Book:
    def __init__(self, code, title):
        self.__code = code
        self.__title = title
        self.__status = True

    def get_book_title(self):
        return self.__title

    def get_book_code(self):
        return self.__code

    def is_available(self):
        return self.__status

    def borrow_book(self):
        self.__status = False

    def return_book(self):
        self.__status = True

    def __str__(self):
        availability = "Available" if self.__status else "On Loan"
        return f"{self.__title}, {self.__code} ({availability})"
class Member:
    def __init__(self, member_id, name):
        self.__member_id = member_id
        self.__name = name
        self.__on_loan_books_list = []

    def get_name(self):
        return self.__name

    def get_member_id(self):
        return self.__member_id

    def get_on_loan_books(self):
        return self.__on_loan_books_list

    def borrow_book(self, book):
        self.__on_loan_books_list.append(book.get_book_title())

    def return_book(self, book):
        self.__on_loan_books_list.remove(book.get_book_title())

    def __str__(self):
        loaned_books = "\n".join([str(book) for book in self.__on_loan_books_list])
        if loaned_books:

            return f"{self.__name}\nOn loan book(s):\n{loaned_books}"
        else:
            return f"{self.__name}\nOn loan book(s):\n- "