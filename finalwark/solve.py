def neng_zhuang_man_bu(W, T):
    a = [0] #用来装"可以通过W内数字相加达到的数字"的数组，初始为0，这是不证自明的
    for i in W:
        if i > T:
            continue
        d = [x + i for x in a] #为a中每个元素都加上本次遍历到的数字
        a = a + d #把新数组与旧数组合并
        if T in a:
            print(f"体积{T}刚好能被填满")
            return True

    print(f"体积{T}没法被{W}刚好填满")
    return False


if __name__ == "__main__":
    # 测试示例
    W = [2, 3, 5]
    T = 8
    neng_zhuang_man_bu(W, T)