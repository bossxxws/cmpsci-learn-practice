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
        
