/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   number.c
 * Author: binxu
 * 
 * Created on 2017年7月23日, 下午6:31
 */
#include<time.h>
#include<stdlib.h>
#include "number.h"

// 随机数组生成
int * producer_array(int length){
  int *r;
  r = malloc(sizeof(int)*length);
  int i;
  /* 设置种子 */
  srand( (unsigned)time( NULL ) );
  for ( i = 0; i < length; i++)
  {
     r[i] = rand()%length;
 
  }

  return r;
}

// 复制数组
int * copy_array(int arr[],int length){
  int *r;
  r = malloc(sizeof(int)*length);
  int i;

  // 循环传入数组
  for ( i = 0; i < length; i++)
  {
      //复制数组
      r[i]= *(arr+i);
 
  }

  return r;
}

// 交换函数
void swap(int *a,int *b){
    int t =  *a;
    *a = *b;
    *b = t;
}

