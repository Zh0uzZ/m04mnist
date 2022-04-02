#include<stdio.h>
#include<stdlib.h>
// #include<string.h>
// #include<math.h>
#include "parameter.h"

typedef const int cint;
typedef const char cchar;

/*每个数据集的数字个数*/


int count_one_bits(int value)
{
    int count = 0;
    while(value)
    {
        value &= (value - 1);
        count++;
    }
    return count;
}

int calDistance(Digit digit1, Digit digit2)
/*求距离*/
{
    int i, squareSum=0;
    int value = 0;
    for(i=0;i<32;i++)
    {
        value = count_one_bits(digit1.pixel[i]^digit2.pixel[i]);
        squareSum += value;
    }
    return squareSum;
}



void showDigit(Digit digit)
/*显示一个Digit 结构体*/
{
    int i, j, id;
    for(i=0;i<32;i++)
    {
        for(j=0;j<32;j++)
        {
            printf("%d", digit.pixel[i*32+j]);
        }
        printf("\n");
    }
    printf(" %d \n", digit.label);
}

void exchange(Distance *in, int index1, int index2) 
/*交换字符串两项*/   
{  
    Distance tmp = (Distance)in[index1];  
    in[index1] = in[index2];  
    in[index2] = tmp;  
}
 
void selectSort(Distance *in, int length)  
/*选择排序*/ 
{  
    int i, j, min;  
    int N = length;  
    for(i=0;i<N-1;i++)  
    {  
        min = i;  
        for(j=i+1;j<N;j++)  
        {  
            if(in[j].distance<in[min].distance) min = j;   
        }  
        exchange(in,i,min);  
    }   
}
int prediction(int K, Digit in, Digit *train, int nt)
/*利用训练数据预测一个数据digit*/
{
    int i, it;
    Distance distance[nt];
    /*求取输入digit与训练数据的距离*///求取欧氏距离
    for(it=0; it<nt; it++)
    {
        distance[it].distance = calDistance(in, train[it]);
        distance[it].label = train[it].label;  
    }
    /*给计算的距离排序(选择排序)*/
    int predict = 0;
    selectSort(distance, nt);
    for(i=0; i<K; i++)
    {
        predict += distance[i].label;
    }
    return (int)(predict);
}

// void knn_classifiy(int K)
// /*用测试数据集进行测试*/
// {
//     printf(".knn_classifiy.\n");
    
//     int i;
    
//     /*读入训练与测试数据集*/
//     int trainCount[10] = {20 , 21 , 21 , 24 , 13 , 18 , 26 , 19 , 23 , 15  };
//     int testCount[10] = {20 , 20 , 25 , 18 , 25 , 16 , 16 , 19 , 17 , 20  };
//     Digit *Dtrain = (Digit*)malloc(ntrain*sizeof(Digit));
//     Digit *Dtest = (Digit*)malloc(ntest*sizeof(Digit));
//     train_digit(Dtrain , Dtest );


//     /*求测试数据与训练数据之间的距离*/
//     printf("..Cal Distance begin.\n");
//     Distance Distance2Train[ntrain];
//     int CorrectCount[10] = {0};
//     int itrain, itest, predict;
//     for(itest=0; itest<ntest; itest++)
//     {
//         predict = prediction(K, Dtest[itest], Dtrain, ntrain);
//         //printf("%d-%d\n",predict, Dtest[itest].label);      
//         /*给预测准确的进行计数*/
//         if(predict == Dtest[itest].label)
//         {
//             CorrectCount[predict] ++;
//         }
//     }
    
//     /*输出测试数据的准确率*/
//     printf("    Correct radio:   \n\n");
//     for(i=0;i<10;i++)
//     {
//         printf("%d:  (  %2d / %2d ) =  %.2f%%\n", 
//                 i, 
//                 CorrectCount[i],
//                 testCount[i],
//                 (float)(CorrectCount[i]*1.0/testCount[i]*100));
//     }
// }
// int loadDigit(Digit *digit, FILE *fp, int *labels)
// /*读取digit*/
// {
//     int index=0;
//     for(index = 0; index<1024; index++)
//     {
//         if(!fscanf(fp, "%d", &(digit->pixel[index])) )
//         {
//             printf("FILE already read finish.\n");
//             return -1;
//         }
//     }
//     fscanf(fp, "%d", &(digit->label));
//     *labels = digit->label; 
    
//     return 1;
// }
int knn_predict(int K)
/*预测数据*/
{
    int i;
    // FILE *fp;
    
    // /*读入训练数据*/
    // Digit *Dtrain = (Digit*)malloc(ntrain*sizeof(Digit));
    // Digit *Dtest = (Digit*)malloc(ntest*sizeof(Digit));
    // train_digit(Dtrain , Dtest );
    // /*读入需要预测的数据*/
    // Digit *Dpredict = (Digit*)malloc(npredict*sizeof(Digit));
    // digit_predict(Dpredict);
    
    /*求输入数据与训练数据之间的距离*/
    printf("..Cal Distance begin.\n");
    Distance Distance2Train[ntrain];
    int predict;
    for(int ipredict=0; ipredict<npredict; ipredict++)
    {
        predict = prediction(K, Dpredict[ipredict], Dtrain, ntrain);
        // printf("%d\n",predict);
    }
    return predict;
}
int main(int argc, char** argv)
{
    int K = 1 , predict;
    /*对已知数据进行测试，统计预测的正确率*/
    // knn_classifiy(K);
    /*对位置数据进行预测*/
    predict = knn_predict(K);
    printf("%d\n" , predict);
    return 1;
}