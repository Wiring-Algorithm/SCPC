//
//  main.c
//  균일수
//
//  Created by 이준호 on 2018. 5. 7..
//  Copyright © 2018년 이준호. All rights reserved.
//

/*
 You should use the statndard input/output
 
 in order to receive a score properly.
 
 Do not use file input and output
 
 Please be very careful.
 */

#include <stdio.h>
#include <math.h>


int Answer;


// m 자릿수 b 기저
int f(int N, int m, int b){
    int ret=-1;
    int temp=0;

    for(int t=0;t<b;t++){
        temp =0;
        for(int i=0;i<m;i++){
            temp += pow(b,i);
        }
        if(temp*t == N){
            ret = t;
            break;
        }
    }

    return ret;
}

int main(void)
{
    int T, test_case,N;
    /*
     The freopen function below opens input.txt file in read only mode, and afterward,
     the program will read from input.txt file instead of standard(keyboard) input.
     To test your program, you may save input data in input.txt file,
     and use freopen function to read from the file when using scanf function.
     You may remove the comment symbols(//) in the below statement and use it.
     But before submission, you must remove the freopen function or rewrite comment symbols(//).
     */
    // freopen("input.txt", "r", stdin);

    /*
     If you remove the statement below, your program's output may not be rocorded
     when your program is terminated after the time limit.
     For safety, please use setbuf(stdout, NULL); statement.
     */
    setbuf(stdout, NULL);

    scanf("%d", &T);
    for(test_case = 0; test_case < T; test_case++)
    {
        scanf("%d", &N);
        int b=2;
        int std=-1;
        int swt=0;
        Answer=-1;

        int m=0; // 자릿수
        int t=0;

        while(b<N){

            m=0; // 자릿수
            m=log(N)/log(b) + 1;
            Answer = f(N, m, b);
            if(Answer!=-1){
                break;
            }
            b++;
        }

        if(Answer==-1){
            Answer=N+1;
            printf("Case #%d\n", test_case+1);
            printf("%d\n", Answer);
        }
        else {
            Answer = b;
            printf("Case #%d\n", test_case + 1);
            printf("%d\n", Answer);
        }

    }

    return 0;//Your program should return 0 on normal termination.
}

