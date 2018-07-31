def line_conf(k, b):
    def line(x):
        return k*x + b

if __name__ == '__main__':
    line1 = line_conf(2, 3)
    line2 = line_conf(4, 5)
    print("line1=%d" %line1)
    print("line2=%d" %line2)
