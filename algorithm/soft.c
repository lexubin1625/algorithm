/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   soft.c
 * Author: binxu
 * 
 * Created on 2017年7月23日, 下午10:57
 */
#include <stdio.h>
#include <stdlib.h>
#include "soft.h"
#include "number.h"
#define  min(x,y)  ( x<y?x:y )
// 选择排序
int * select_soft(int arr[],int length){
    int i,j;
    for(i=0;i<length;i++){
        // 当前要比较的索引位置
        int index = i;
        for(j = i+1;j<length;j++){
            
            // 找出比当前索引位置小的数，交换原有值
            if(arr[j]<arr[index]){   
               // 交换函数
               swap(&arr[j],&arr[index]); 
            }
        }
    }  
    return arr;
}

// 插入排序
int * insert_soft(int arr[],int length){
    int i,j;
    for(i=0;i<length;i++){
        
        // 从当前已有数据中最后一个开始比较
        // 亲一定是从后面开始,想想自己玩扑克牌
//        for(j=i;j>0;j--){
//            
//            // 如果当前数值比前一个小，和前一个交换
//            if(arr[j]<arr[j-1]){
//                swap(&arr[j],&arr[j-1]);
//            }else{
//                // 找到合适的位置 提前终止掉
//                break;
//            }
//        }
//    }
//    return arr; 
    
        // 简洁优化
//        for(j=i;j>0&&arr[j]<arr[j-1];j--){
//            swap(&arr[j],&arr[j-1]);
//        }
        
        int t = arr[i];// 拷贝当前的副本，用于交换
        
        // 已比较好的排序范围里 如果出现小于t就终止
        for(j=i;j>0&&arr[j-1]>t;j--){
            arr[j]=arr[j-1];
        }
        // arr[j]  经过for中j-- 实质是最后一次需要交换的位置索引arr[j-1]
        arr[j]=t;
        
    }
    
    return arr;
}

// 希尔排序
int * shell_soft(int arr[],int n){  
    int i,j,
        incre,//比较的数据区间 可以理解为插入排序中的索引j--, j-=incre只不过那时默认incre=1；
        tmp;  
    // 加了一层区间计算的 用于加快数据近似有序，
    for(incre=n/2;incre>0;incre/=2)  
    {  
        for(i=incre;i<n;i++)  
        {  
            tmp=arr[i];  
            for(j=i;j>=incre && arr[j-incre]>tmp;j-=incre)  
            {   
                arr[j]=arr[j-incre];  
            }  
            arr[j]=tmp;  
        }  
    }  
} 

// 归并排序
int * merge_soft(int arr[],int n){
    _merge_sort(arr,0,n-1);
}

// 数据归并
int _merge(int arr[], int l, int mid, int r)
{
    int left_len = mid - l + 1;//分配两个数组 用于辅助排序
    int right_len = r - mid;
    int left[left_len], right[right_len];
    int i, j, k;

    //  注意下标偏移量
    for (i = 0; i < left_len; i++) // 填充左侧数组
        left[i] = arr[l+i];
    for (j = 0; j < right_len; j++) // 填充右侧数组
        right[j] = arr[mid+1+j];

    i = j = 0;
    k = l;
    // 比较俩边数组哪个值小，就把那个放到将要排序的那个键上
    while (i < left_len && j < right_len)
        if (left[i] < right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];

    // 注意要维护数组上值完整性
    // 处理两个数组没有遍历完，一边有部分是小于左边或者右边
    while (i < left_len) // 左边数组没有遍历完 依次将剩余部分填充好
        arr[k++] = left[i++];
    while (j < right_len) // 右边数组没有遍历完
        arr[k++] = right[j++];
}

// 归并排序 自顶向下
int _merge_sort(int arr[], int l, int r)
{
    int mid;
    
    if(l<r){

        // 当左侧小于右边执行，
        mid = (l + r) / 2;
        
        // 排序
        _merge_sort(arr, l, mid); // 递归划分原数组左半边a[l...mid]
        _merge_sort(arr, mid+1, r); // 递归划分[mid+1...r]

        _merge(arr, l, mid, r); // 合并
    }
    return arr;
}
//
// 归并排序 自底向上排序
int non_recursive_merge_soft(int arr[],int n)  
{  
    // 每小段步长，和递归过程相反 1，2，4，8...
    for( int step = 1; step <= n ; step += step )
        for( int i = 0 ; i < n ; i += step+step )
            // 对 arr[i...i+step-1] 和 arr[i+sz...i+2*step-1] 进行归并
            // 注意数组不要越界，右边不要超过最大长度，
            _merge(arr, i, i+step-1, min(i+step+step-1,n-1) );

}  

// 数据分区 返回边界值的那个索引
int _partition(int arr[],int l,int r){
    // 把第一个arr[l]的值为参照
    // 以arr[l]的值为界，左侧小于arr[l]
    int j=l; // 记录小于arr[l]的最后一个游标
    
    for(int i = l+1;i<=r;i++){
        
        //小于arr[l]的值放倒元素左边
        if(arr[i]<arr[l]){
            
            j++;
            swap(&arr[j],&arr[i]);
        }
    }
    // 最后将arr[l]移到数组中小于arr[l]最后一个位置
    // 实现arr[l]左侧都是小于l 右侧大于arr[l]
    swap(&arr[l],&arr[j]);
    return j;
}
int * quick_soft(int arr[],int n){
    _quick_soft(arr, 0, n-1);
    return arr;
}

int _quick_soft(int arr[],int l,int r){
    if(l<r){
        // 数据左右边界的索引值
        int p = _partition(arr,l,r);
        // 左侧分区排序
        _quick_soft(arr,l,p-1);
        // 右侧分区排序
        _quick_soft(arr,p+1,r);
    }
}

// 堆排序
int * heap_soft(int arr[],int n){
    for(int i=0;i<n;i++){
        _insert_heap(arr[i],i);
    }
}

int _insert_heap(int arr[],int n){
    
}