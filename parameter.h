/*文件路径+名称*/
#include<stdio.h>
#include<stdlib.h>
// #include<string.h>
// #include<math.h>



/*一个手写数字的结构体*/
typedef struct
{
    int pixel[32];
    int label;
}Digit;

/*一个有label的距离结构体*/
typedef struct 
{
    int distance;
    int label;
}Distance;
cint   ntrain = 49;
cint   ntest = 0;
cint   npredict = 1;
 Digit Dtrain[ntrain];
 Digit Dpredict[npredict];

