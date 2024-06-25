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
        return f"{self.__code}, {self.__title} ({availability})"

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
        self.__on_loan_books_list.append(book.get_book_code())

    def return_book(self, book):
        self.__on_loan_books_list.remove(book.get_book_code())

    def __str__(self):
        loaned_books = "\n".join([str(book) for book in self.__on_loan_books_list])
        if loaned_books:

            return f"{self.__name}\nOn loan book(s):\n{loaned_books}"
        else:
            return f"{self.__name}\nOn loan book(s):\n- "
        
class Record:
    def __init__(self, book, member, issue_date):
        self.__book = book
        self.__member = member
        self.__is_on_loan = True
        self.__issue_date = issue_date
        self.__book.borrow_book()
        self.__member.borrow_book(book)
        
    def get_member(self):
        return self.__member


    def get_member_id(self):
        return self.__member.get_member_id()
        
    def get_book(self):
        return self.__book

    def get_book_code(self):
        return self.__book.get_book_title()

    def get_issue_date(self):
        return self.__issue_date

    def is_on_loan(self):
        return self.__is_on_loan

    def return_book(self):
        self.__book.return_book()
        self.__member.return_book(self.__book)
        self.__is_on_loan = False

    def __str__(self):
        availability = "On Loan" if self.__is_on_loan else "Available"
        return f"{self.__member.get_name()}, {self.__book.get_book_code()}, {self.__book.get_book_title()} ({availability}), issued date={self.__issue_date}"


class MyLibrary:
    def __init__(self, filename):
        self.__books_list = []
        self.__on_loan_records_list = []
        self.load_books_from_file(filename)

    def load_books_from_file(self, filename):
        try:
            with open(filename, 'r') as file:
                for line in file:
                    book_info = line.strip().split(',')
                    if len(book_info) >= 2:
                        book = Book(book_info[1], book_info[0])
                        self.__books_list.append(book)
            print(f"{len(self.__books_list)} books loaded.")
        except FileNotFoundError:
            print(f"ERROR: The file '{filename}' does not exist.")

    def show_all_books(self):
        for book in self.__books_list:
            availability = "(Available)" if book.is_available() else "(On Loan)"
            print(f"{book.get_book_code()}",end=", ")
            print(f"{book.get_book_title()}",end=" ")
            print(f"{availability}")


    def find_book(self, code):
        for book in self.__books_list:
            if book.get_book_title() == code and book.is_available():
                return book
        return None

    def borrow_book(self, book, member, issue_date):
        if book is None:
            print("ERROR: could not issue the book.")
            return

        if book in [record.get_book_code() for record in self.__on_loan_records_list]:
            print(f"{book.get_book_code()} is already on loan.")
            return

        record = Record(book, member, issue_date)
        self.__on_loan_records_list.append(record)
        print(f"{book.get_book_code()} is borrowed by {member.get_name()}.")
    
    def show_available_books(self):
       
        for book in self.__books_list:
            if book.is_available():
                print(book)

class MyLibrary:
    def __init__(self, filename):
        self.__books_list = []
        self.__on_loan_records_list = []
        self.load_books_from_file(filename)

    def load_books_from_file(self, filename):
        try:
            with open(filename, 'r') as file:
                for line in file:
                    book_info = line.strip().split(',')
                    if len(book_info) >= 2:
                        book = Book(book_info[1], book_info[0])
                        self.__books_list.append(book)
            print(f"{len(self.__books_list)} books loaded.")
        except FileNotFoundError:
            print(f"ERROR: The file '{filename}' does not exist.")

    def show_all_books(self):
        for book in self.__books_list:
            availability = "(Available)" if book.is_available() else "(On Loan)"
            print(f"{book.get_book_code()}",end=", ")
            print(f"{book.get_book_title()}",end=" ")
            print(f"{availability}")


    def find_book(self, code):
        for book in self.__books_list:
            if book.get_book_title() == code and book.is_available():
                return book
        return None

    def borrow_book(self, book, member, issue_date):
        if book is None:
            print("ERROR: could not issue the book.")
            return

        if book in [record.get_book_code() for record in self.__on_loan_records_list]:
            print(f"{book.get_book_code()} is already on loan.")
            return

        record = Record(book, member, issue_date)
        self.__on_loan_records_list.append(record)
        print(f"{book.get_book_code()} is borrowed by {member.get_name()}.")
    
    def show_available_books(self):
        for book in self.__books_list:
            if book.is_available():
                print(book)

    def find_record(self, code):
        for record in self.__on_loan_records_list:
            if record.get_book_code() == code and record.is_on_loan():
                return record
        return None

    def return_book(self, record):
        if record is None:
            print("ERROR: could not return the book.")
            return

        record.return_book()
        print(f"{record.get_book_code()} is returned successfully.")

    def show_on_loan_records(self):
       
        for record in self.__on_loan_records_list:
            if record.is_on_loan():
                print(f"{record.get_member().get_name()}, {record.get_book().get_book_code()}, {record.get_book().get_book_title()} (On Loan), issued date={record.get_issue_date()}")

    def show_all_records(self):
        for record in self.__on_loan_records_list:
            print(record)
library = MyLibrary('simple_books.txt')
print()
b1 = library.find_book('QS12.02.003')
m1 = Member(1001, "Michael")
library.borrow_book(b1, m1, "2020-08-12")
print()
b2 = library.find_book('QA12.04.004')
library.borrow_book(b2, m1, "2020-08-12")
print()
library.show_available_books()
print()
print(m1)
library = MyLibrary('simple_books.txt')
m1 = Member(1001, "Michael")
library.borrow_book(library.find_book('QS12.02.003'), m1, "2020-08-12")
library.borrow_book(library.find_book('QK12.04.002'), m1, "2020-08-15")
library.show_all_records()
