#include <iostream>
#include <stack>
#include <vector>
using namespace std;


bool solvePackage(int W[], int n, int T) {
    stack<int> S;           // 栈S存放放入背包内物品的序号
    int i = 1;              // 待选物品序号，从1开始
    int remainT = T;        // 剩余容量
    
    while (true) {
       
        while (i <= n && remainT - W[i] >= 0) {
            S.push(i);              // 物品i可选，进栈
            remainT -= W[i];        // 减去该物品的体积
            
            if (remainT == 0) {
                cout << "找到解！装入背包的物品序号为：";
                
                // 输出解（需要临时栈来保持顺序）
                stack<int> temp;
                while (!S.empty()) {
                    temp.push(S.top());
                    S.pop();
                }
                while (!temp.empty()) {
                    cout << temp.top() << " ";
                    temp.pop();
                }
                cout << endl;
                return true;
            }
            
            i++;                    
        }
        
        // 当前路径无解，需要回溯
        // 若i>n或者remainT-W[i]<0，需要退栈
        if (S.empty()) {
            // 栈空，说明无解
            cout << "无解！无法恰好装满背包。" << endl;
            return false;
        }
        
        // 退栈，回溯
        int topItem = S.top();
        S.pop();
        remainT += W[topItem];      // 恢复容量
        i = topItem + 1;            // 尝试下一件物品
    }
}

/**
 * 打印所有解的版本
 */
void solvePackageAllSolutions(int W[], int n, int T) {
    stack<int> S;           // 栈S存放放入背包内物品的序号
    int i = 1;              // 待选物品序号
    int remainT = T;        // 剩余容量
    int solutionCount = 0;  // 解的数量
    
    cout << "开始搜索所有可能的解..." << endl;
    
    while (true) {
        // 尝试将物品i放入背包
        while (i <= n && remainT - W[i] >= 0) {
            S.push(i);              // 物品i可选，进栈
            remainT -= W[i];        // 减去该物品的体积
            
            // 如果恰好装满背包，找到一个解
            if (remainT == 0) {
                solutionCount++;
                cout << "解 " << solutionCount << "：";
                
                // 输出当前解
                stack<int> temp;
                int totalVolume = 0;
                while (!S.empty()) {
                    temp.push(S.top());
                    S.pop();
                }
                while (!temp.empty()) {
                    int item = temp.top();
                    cout << item << "(体积" << W[item] << ") ";
                    totalVolume += W[item];
                    S.push(item);  // 恢复栈
                    temp.pop();
                }
                cout << " 总体积=" << totalVolume << endl;
                
                // 继续寻找其他解，需要退栈
                int topItem = S.top();
                S.pop();
                remainT += W[topItem];
                i = topItem + 1;
                continue;
            }
            
            i++;                    // 继续尝试下一件物品
        }
        
        // 当前路径无解，需要回溯
        if (S.empty()) {
            // 栈空，搜索结束
            if (solutionCount == 0) {
                cout << "无解！无法恰好装满背包。" << endl;
            } else {
                cout << "搜索完成，共找到 " << solutionCount << " 个解。" << endl;
            }
            return;
        }
        
        // 退栈，回溯
        int topItem = S.top();
        S.pop();
        remainT += W[topItem];      // 恢复容量
        i = topItem + 1;            // 尝试下一件物品
    }
}

int main() {
    // 测试用例1
    cout << "========== 测试用例1 ==========" << endl;
    int W1[] = {0, 2, 3, 5, 7};  // 索引0不用，从1开始
    int n1 = 4;
    int T1 = 10;
    
    cout << "物品体积：";
    for (int i = 1; i <= n1; i++) {
        cout << W1[i] << " ";
    }
    cout << "\n背包容量：" << T1 << endl << endl;
    
    solvePackage(W1, n1, T1);
    
    cout << "\n查找所有解：" << endl;
    solvePackageAllSolutions(W1, n1, T1);
    
    // 测试用例2
    cout << "\n========== 测试用例2 ==========" << endl;
    int W2[] = {0, 2, 3, 5};
    int n2 = 3;
    int T2 = 8;
    
    cout << "物品体积：";
    for (int i = 1; i <= n2; i++) {
        cout << W2[i] << " ";
    }
    cout << "\n背包容量：" << T2 << endl << endl;
    
    solvePackage(W2, n2, T2);
    
    cout << "\n查找所有解：" << endl;
    solvePackageAllSolutions(W2, n2, T2);
    
    // 测试用例3 - 无解的情况
    cout << "\n========== 测试用例3 (无解) ==========" << endl;
    int W3[] = {0, 3, 5, 7};
    int n3 = 3;
    int T3 = 11;
    
    cout << "物品体积：";
    for (int i = 1; i <= n3; i++) {
        cout << W3[i] << " ";
    }
    cout << "\n背包容量：" << T3 << endl << endl;
    
    solvePackage(W3, n3, T3);
    
    return 0;
}
