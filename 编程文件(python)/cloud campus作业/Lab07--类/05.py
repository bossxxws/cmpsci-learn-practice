class Record:
    def __init__(self, book, member, issue_date):
        self.__book = book
        self.__member = member
        self.__is_on_loan = True
        self.__issue_date = issue_date
        self.__book.borrow_book()
        self.__member.borrow_book(book)

    def get_member_id(self):
        return self.__member.get_member_id()

    def get_book_code(self):
        return self.__book.get_book_code()

    def get_issue_date(self):
        return self.__issue_date

    def is_on_loan(self):
        return self.__is_on_loan

