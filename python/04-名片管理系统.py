# -*- coding:utf-8 -*-
def main():
    print("*" * 50)
    print("名片管理系统")
    print("1)添加名片")
    print("2)删除名片")
    print("3)修改名片")
    print("4)查询名片")
    print("5)显示所有")
    print("6)退出")
    print("*" * 50)

    infors = []  # 列表：存放所有名片信息


    while True:
        selection = int(input("请输入操作序号："))
        if selection == 1:
            flag = True
            # 输入添加的名片信息
            new_name = input("请输入要添加的姓名：")
            new_age = input("请输入要添加的年龄：")
            new_sex = input("请输入要添加的性别：")
            new_qq = input("请输入要添加的QQ：")

            # 将输入的信息添加到字典中
            info = {}  # 每个名片是一个字典
            info["name"] = new_name
            info["age"] = new_age
            info["sex"] = new_sex
            info["qq"] = new_qq


            # 判断姓名是否重复
            for item in infors:
                if item["name"] == new_name:
                    flag = False
                    print("已经存在该名字！请重新输入！")
            if flag:
                # 将字典添加到列表中
                infors.append(info)

            print(infors)

        elif selection == 2:

            del_name = input("请输入要删除的姓名：")

            if search(infors, del_name) != -1:
                i = search(infors, del_name)
                del infors[i]
                print("已成功删除了%s" % del_name)
            else:
                print("没有找到要删除的人！")
                continue


        elif selection == 3:
            pass


        elif selection == 4:
            search_name = input("请输入要查找的姓名：")
            for item in infors:
                if item["name"] == search_name:
                    find_flag = 1
                    print("姓名\t年龄\t性别\t QQ")
                    print("%s\t%s\t%s\t%s" % (item["name"], item["age"], item["sex"], item["qq"]))
            if find_flag == 0:
                print("查无此人。。。")
        elif selection == 5:
            print("姓名\t年龄\t性别\t QQ")
            for item in infors:
                print("%s\t%s\t%s\t%s"%(item["name"],item["age"],item["sex"],item["qq"]))
        elif selection == 6:
            print("bye")
            break
        else:
            print("请重新输入。")
            continue
        print("")


def search(card, name):
    i = 0  # 列表的下标
    flag = -1  # 默认表示没有找到
    for item in card:
        if item["name"] == name:
            flag = 1
            return i
        else:
            i += 1
    return flag

if __name__ == "__main__":
    main()

