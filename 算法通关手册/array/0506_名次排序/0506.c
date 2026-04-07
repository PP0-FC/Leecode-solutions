/**
 * @problem: 0506相对名次
 * @approach: 三个数组，分别用于存放成绩、序号、最终结果。使用希尔排序。
 * @time_complexity: 平均：O(nlog^2n)。最坏：O(n*n)
 * @space_complexity: O(n)
 */
char** findRelativeRanks(int* score, int scoreSize, int* returnSize) 
{
    /********初始化*******/
    *returnSize = scoreSize;

    //动态分配辅助索引数组和最终返回的字符串指针数组
    int *Index = (int *)malloc(sizeof(int)*scoreSize);
    char **answer = (char **)malloc(sizeof(char*)*scoreSize);

    //初始化序号数组：Index[i]记录第i个人的序号。
    for(int i = 0 ; i < scoreSize ; i++)
    {
        Index[i] = i;
    }

    /*********希尔排序：降序排列********/
    int gap = scoreSize / 2;
    int temp,tempIndex;
    for(gap ; gap > 0 ; gap /= 2)
    {
        //从第gap个元素开始，对每个分组进行插入排序。
        for(int i = gap ; i < scoreSize ; i++)
        {
            int j = i;
            temp = score[i];           //待插入的成绩
            tempIndex = Index[i];      //待插入的序号
            while(j > gap-1 && score[j-gap] < temp)
            {
                score[j] = score[j-gap];
                Index[j] = Index[j-gap];
                j -= gap;
            }
            score[j] = temp;
            Index[j] = tempIndex;
        }
    }

    /********构造结果数组********/
    int ansIndex;
    for(int i = 0 ; i < scoreSize ; i++)
    {
        //结果数组的下标存储在序号数组中
        ansIndex = Index[i];

        //为当前名次分配字符串空间
        answer[ansIndex] = (char *)malloc(sizeof(char *)*15);

        switch(i)
        {
            case 0:
                strcpy(answer[ansIndex] , "Gold Medal");
                break;
            case 1:
                strcpy(answer[ansIndex] , "Silver Medal");
                break;
            case 2:
                strcpy(answer[ansIndex] , "Bronze Medal");
                break;
            default:
                snprintf(answer[ansIndex] , 12 , "%d" , i+1);
                break;
        }
    }
    
    return answer;
}