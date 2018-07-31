import xlrd

def testExcel():
    excel = xlrd.open_workbook(r'./addone.xlsx')
    print excel


if __name__ == '__main__':
    testExcel()
