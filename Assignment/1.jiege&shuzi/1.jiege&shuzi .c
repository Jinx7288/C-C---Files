#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main() {
    int in;
    int ans=0;
    char inshu1[7];
    char inshu2[7];
    char instr[11];
    scanf("%d", &in);
    for (int i = 1; i <= sqrt(in); i++)
    {
        if (in%i==0)
        {
            // itoa(i, inshu1, 10);
            sprintf(inshu1, "%d", i);
            // itoa(in/i, inshu2, 10);
            sprintf(inshu2, "%d", in/i);
            // itoa(in, instr, 10);
            sprintf(instr, "%d", i);
            int flag1 = 0;
            int flag2 = 0;
            for (int j = 0; j < strlen(inshu1); j++)
            {
                for (int k = 0; k < strlen(instr); k++)
                {
                    if(inshu1[j] == instr[k])
                    {
                        ans++;
                        flag1 = 1;
                        break;
                    }
                }
                if (flag1==1)
                {
                    break;
                }
            }
            if (i!=in/i)
            {
                   for (int j = 0; j < strlen(inshu2); j++)
                {
                for (int k = 0; k < strlen(instr); k++)
                {
                    if(inshu2[j] == instr[k])
                    {
                        ans++;
                        flag2 = 1;
                        break;
                    }
                }
                 if (flag2==1)
                {
                    break;
                }
            }     
            }
        }    
    }
    printf("%d", ans);
    return 0;
}