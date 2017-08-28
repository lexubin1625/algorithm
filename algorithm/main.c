#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "number.h"

// 定义一个微秒的时间单位
#define CLOCKS_PER_SEC ((clock_t)1000) 
/* 要调用上面定义函数的主函数 */
struct  linkNode{
    int num;
    struct linkNode * next;
};

int main(){
    struct linkNode a,b,c, *head;
    a.num =3;
    b.num =5;
    c.num =1;
    head = &a;
    
    a.next = &b;
    b.next = &c;
    c.next = NULL;
    struct linkNode *p;
    p = head;
    while(p != NULL){
        printf("%d\n",p->num);
        p=p->next;
    }
}
int main_soft()
{
   
    
   int *arr,  // 一个指向整数数组的指针
       i,     //用于循环数组
       length;// 数组长度
   double duration;
   clock_t start_time,end_time;
   
   // 随机数组生成
   length = 10;//数组长度
   arr    = producer_array(length);// 可以理解为 
   //int arr[] ={1,6,4,2,8,0,3,7,5,9};
   
   // 拷贝数组
   int *arr_copy =  copy_array(arr,length);
   //insert_soft(arr_copy,length); 
   //insert_soft(arr,length); 
   start_time = clock();
   
   // 传递一个指向数组的指针
   // 选择排序
   //select_soft(arr,length);
   //insert_soft(arr,length);
   non_recursive_merge_soft(arr,length);
   end_time = clock();
   duration = (double)(end_time - start_time) / CLOCKS_PER_SEC; 
   printf( "函数共执行%f 微秒\n", duration ); 
   
   start_time = clock();
   // 插入排序
   //insert_soft(arr,length);
   
   //归并排序
   //merge_soft(arr_copy,length);
   
   //shell_soft(arr_copy,length);
   
   quick_soft(arr_copy,length);
   end_time = clock();
   duration = (double)(end_time - start_time) / CLOCKS_PER_SEC; 
   printf( "函数共执行%f 毫秒\n", duration ); 
   
   // 显示结果
   for(i=0;i<length;i++){
        printf( "*(p + %d) : %d\n", i, arr[i]);
   }
   
   // 释放内存
   free(arr);
 
   return 0;
}

int main_insert ()
{
   int i,     //用于循环数组
       length;// 数组长度
   double duration;
   clock_t start_time,end_time;
   
   // 随机数组生成
   length = 10;//数组长度
   int arr[] ={1,6,4,2,8,0,3,7,5,9};

   start_time = clock();//开始时间
   
   // 传递一个指向数组的指针
   // 选择排序
   select_soft(arr,length);

   end_time = clock();//结束时间
   //微妙显示运行时间
   duration = (double)(end_time - start_time) / ((clock_t)1000) ; 
   printf( "函数共执行%f 微秒\n", duration ); 
   
   // 显示结果
   for(i=0;i<length;i++){
        //printf( "第%d个: %d\n", i, arr[i]);
   }
   
   return 0;
}
