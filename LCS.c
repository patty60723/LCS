#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 255

char str1[MAX];
char str2[MAX];

int table[MAX + 1][MAX + 1];
int c_table[MAX + 1][MAX + 1];

void LCS(int, int);
void print_LCS(int , int);


void LCS(int n1, int n2)
{
     int i, j;
     for (i = 0; i < MAX + 1; i++)
         table[0][i] = table[i][0]= 0;
     
     for (i = 1 ; i <= n1 ; i++)
     {
         for (j = 1; j <= n2 ; j++)
         {
             if (str1[i] == str2[j])
                {
                         table[i][j] = table[i - 1][j - 1] + 1;
                         c_table[i][j] = 3;   //���W�� 
                         }
             else {
                  if(table[i - 1][j] > table[i][j - 1])
                  {
                      table[i][j] = table[i - 1][j];
                      c_table[i][j] = 1;      //�W�� 
                      }
                  else
                      {
                         table[i][j] = table[i][j - 1];
                         c_table[i][j] = 2;   //���� 
                                    }
                         }
             }
         }
     printf("\n�l�r����׬�: %d", table[n1][n2]);
     printf("\n�l�r�ꬰ: \n");
     print_LCS(n1, n2);
     }
void print_LCS(int n1, int n2)
{
     if (n1 == 0 || n2 == 0) 
        {printf("%c", str1[n1]);
        return;}
     if ( c_table[n1][n2] == 3)
     {
          print_LCS(n1 - 1, n2 - 1);
          printf("%c", str1[n1]);
          }
     else if( c_table[n1][n2] == 1)
     {
          print_LCS(n1 - 1, n2);
          }
     else if( c_table[n1][n2] == 2)
     {
          print_LCS(n1, n2 - 1);
          }
     }
int main()
{
    clock_t start = clock();
    int k;
    do{
          printf("�п�J�r��1: (�̤j����255�r��)\n");
          k = scanf("%s", str1);
          while (getchar() != '\n')
          ;
          }
          while (k > 255);
    do{
          printf("�п�J�r��2: (�̤j����255�r��)\n");
          k = scanf("%s", str2);
          while (getchar() != '\n')
          ;
          }
          while (k > 255);
    
    LCS(strlen(str1), strlen(str2));
    
    clock_t end = clock();
    
    float totalTime = (float)(end - start) / CLK_TCK;
    printf("\n�p��ɶ���: %6.4f", totalTime);
    system("pause");
    return 0;
    
    
    }
