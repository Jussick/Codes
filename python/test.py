# 闭包
def test(num):
    print("---1---")
    def test_in(num_in):
        print("test_in")
        print(num+num_in)
    print("---2---")
    return test_in(100)

test(100)
# -------------------------------------------- #

