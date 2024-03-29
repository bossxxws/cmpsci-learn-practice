import os


# 新增图书信息
def Add():
    id_book = int(input('请输入编号:'))
    name_book = input('请输入书名:')
    author_book = input('请输入作者:')
    type_book = input('请输入种类:')
    num_book = int(input('请输入数量:'))
    surplus_book = int(input('请输入剩余:'))
    book_information = {'编号': id_book, '书名': name_book, '作者': author_book, '种类': type_book, '数量': num_book,
                        '剩余': surplus_book}
    with open('图书信息.txt', 'a', encoding='utf-8') as f:  # 图书信息以字典形式存储，增加信息就用a追加到文件中
        if os.path.getsize('图书信息.txt') != 0:
            f.write('\n')	# 换行\n保证数据在文件中按行存储，这样在查询时用f.readlines()才能正确查询
        f.write(str(book_information))


# 删除图书信息
def Delete():
    del_num = int(input('请输入你要删除图书的编号:'))
    with open('图书信息.txt', 'r', encoding='utf-8') as f:  # 把文件信息全部提取出来
        book_inf = f.readlines()
    for i in range(len(book_inf)):  # 循环查找想要编号的那一项
        if eval(book_inf[i])['编号'] == del_num:
            book_inf.pop(i)  # 找到后把那一项删掉
            break
    with open('图书信息.txt', 'w', encoding='utf-8') as f:  # 把删掉一项信息后的book_inf覆盖存储到文件中
        for temp in book_inf:
            f.write(str(temp))  # 存储必须以str类型，否则就报错


# 修改图书信息
def Alter():
    alt_num = int(input('请输入你要修改图书的编号:'))
    with open('图书信息.txt', 'r', encoding='utf-8') as f:  # 取所有图书信息
        books_inf = f.readlines()
    for temp in books_inf:  # 循环遍历出哪一项是想要修改的
        b = eval(temp)
        if b['编号'] == alt_num:
            print(b)  # 列出所选编号的图书信息，好看着修改
            books_inf.remove(temp)
            b['编号'] = int(input('请输入编号:'))
            b['书名'] = input('请输入书名:')
            b['作者'] = input('请输入作者:')
            b['种类'] = input('请输入种类:')
            b['数量'] = int(input('请输入数量:'))
            b['剩余'] = int(input('请输入剩余:'))
            break
    with open('图书信息.txt', 'w', encoding='utf-8') as f:
        f.write(str(b) + '\n')
    with open('图书信息.txt', 'a', encoding='utf-8') as f:
        for temp in books_inf:
            f.write(str(temp))


# 查询图书信息
def Search():
    sea_num = int(input('请输入你要查找图书的编号:'))
    with open('图书信息.txt', 'r', encoding='utf-8') as f:  # 取所有图书信息
        books_inf = f.readlines()
    for temp in books_inf:  # 循环遍历出哪一项是想要查找的
        b = eval(temp)
        if b['编号'] == sea_num:
            print('编号'.center(5, ' '), '书名'.center(15, ' '), '作者'.center(15, ' '), '种类'.center(15, ' '),
                  '数量'.center(5, ' '),
                  '剩余'.center(5, ' '))
            format_data = '{:^5}\t{:^15}\t{:^10}\t{:^10}\t{:^5}\t{:^5}'
            print(format_data.format(b.get('编号'), b.get('书名'), b.get('作者'), b.get('种类'), b.get('数量'), b.get('剩余')))


# 展示所有图书信息
def Show():
    with open('图书信息.txt', 'r', encoding='utf-8') as f:  # 取所有图书信息
        books_inf = f.readlines()
    print('编号'.center(5, ' '), '书名'.center(15, ' '), '作者'.center(15, ' '), '种类'.center(15, ' '), '数量'.center(5, ' '),
          '剩余'.center(5, ' '))
    format_data = '{:^5}\t{:^15}\t{:^10}\t{:^10}\t{:^5}\t{:^5}'
    for temp in books_inf:
        b = eval(temp)
        print(format_data.format(b.get('编号'), b.get('书名'), b.get('作者'), b.get('种类'), b.get('数量'), b.get('剩余')))


# 选择菜单
def Menu():
    print('-----------------------------功能菜单-----------------------------')
    print('\t\t\t\t1.新增图书信息')
    print('\t\t\t\t2.删除图书信息')
    print('\t\t\t\t3.修改图书信息')
    print('\t\t\t\t4.查询图书信息')
    print('\t\t\t\t5.展示所有图书信息')
    print('\t\t\t\t0.退出')
    print('----------------------------------------------------------------')


# 主程序
def main():
    print('=========================资料室图书管理系统=========================')
    while True:
        Menu()
        select = eval(input('请选择功能:'))
        if select == 1:
            Add()
            print('新增信息完成！')
            print('\n')
        elif select == 2:
            Delete()
            print('删除信息完成！')
            print('\n')
        elif select == 3:
            Alter()
            print('修改信息完成！')
            print('\n')
        elif select == 4:
            Search()
            print('\n')
        elif select == 5:
            Show()
            print('\n')
        elif select == 0:
            print('谢谢使用!')
            break
        else:
            print("输入错误！请重新输入！")

if __name__ == '__main__':
	main()
