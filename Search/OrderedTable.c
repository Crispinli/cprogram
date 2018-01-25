#include <stdio.h>
#include <stdlib.h>

/* 折半查找，也叫二分查找 */
int Binary_Search(int *a, int n, int key){
    int low, high, mid;
    low = 1; // 用于标定查询区域下界
    high = n; // 用于标定查询区域上界
    while(low <= high){
        mid = (low + high) / 2;
        if(key < a[mid]){
            high = mid -1;
        }else if(key > a[mid]){
            low = mid + 1;
        }else{
            return mid;
        }
    }
    return 0;
}

/* 插值查找，是对折半查找的改进，适合表长较大且关键字分布均匀的有序表 */
int Interpolation_Search(int *a, int n, int key){
    int low, high, mid;
    low = 1;
    high = n;
    while(low <= high){
        mid = low + (high - low) * (key - a[low]) / (a[high] - a[low]);
        if(key > a[mid]){
            low = mid + 1;
        }else if(key < a[mid]){
            high = mid - 1;
        }else{
            return mid;
        }
    }
    return 0;
}

/* 斐波那契查找，mid 类似于0.618的黄金分割比 */
int Fabonacci_Search(int *a, int n, int key){
    int F[10] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    int low, high, mid;
    int k = 0, i;
    low = 1;
    high = n;
    while(n > F[k] - 1){ // n 不大于 F[k]-1
        k++;
    }
    for(i = n + 1; i < F[k] - 1; i++){ // 把空位用 a[n] 补齐
        a[i] = a[n];
    }
    while(low <= high){
        mid = low + F[k - 1] - 1; // mid = low + F[k-1] - 1
        if(key < a[mid]){
            high = mid - 1;
            k = k -1;
        }else if(key > a[mid]){
            low = mid + 1;
            k = k -2;
        }else{
            if(mid < n){
                return mid;
            }else{
                return n;
            }
        }
    }
    return 0;
}

int main(){
    printf("Hello World!");
    return 0;
}