def solve_package_all_solutions(W, n, T):

    S = [] 
    i = 1  
    remain_T = T  
    solution_count = 0  

    print("开始搜索所有可能的解...")

    while True:
        while i <= n and remain_T - W[i] >= 0:
            S.append(i) 
            remain_T -= W[i] 
            if remain_T == 0:
                solution_count += 1
                print(f"解 {solution_count}：物品序号 {S}", end="")
                volumes = [W[idx] for idx in S]
                print(f" | 体积 {volumes} | 总体积={sum(volumes)}")


                top_item = S.pop()
                remain_T += W[top_item]
                i = top_item + 1
                continue

            i += 1

        if not S: 
            if solution_count == 0:
                print("无解！无法恰好装满背包。")
            else:
                print(f"搜索完成，共找到 {solution_count} 个解。")
            return


        top_item = S.pop()
        remain_T += W[top_item]
        i = top_item + 1 




if __name__ == "__main__":

    print("=" * 70)
    print("测试用例1".center(70))
    print("=" * 70)
    W1 = [0, 2, 3, 5, 7] 
    n1 = 4
    T1 = 10

    print(f"物品体积：{W1[1:n1+1]}")
    print(f"背包容量：{T1}\n")


    solve_package_all_solutions(W1, n1, T1)


    print("\n" + "=" * 70)
    print("测试用例2".center(70))
    print("=" * 70)
    W2 = [0, 2, 3, 5]
    n2 = 3
    T2 = 8

    print(f"物品体积：{W2[1:n2+1]}")
    print(f"背包容量：{T2}\n")

    solve_package_all_solutions(W2, n2, T2)

    #无解的情况
    print("\n" + "=" * 70)
    print("测试用例3 (无解)".center(70))
    print("=" * 70)
    W3 = [0, 3, 5, 7]
    n3 = 3
    T3 = 11

    print(f"物品体积：{W3[1:n3+1]}")
    print(f"背包容量：{T3}\n")

    solve_package_all_solutions(W3, n3, T3)
