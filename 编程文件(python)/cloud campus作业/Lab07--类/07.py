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
        

              
