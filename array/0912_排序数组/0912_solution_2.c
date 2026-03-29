/**
 * @problem: 将数组排序为升序
 * @approach: 归并排序
 * @time_complexity: O(nlogn)
 * @space_complexity: O(n)
 */


int* merge(int *nums , int left , int right ,int mid)
{
    int *L = (int *)malloc(sizeof(int) * (mid - left + 1));
    int *R = (int *)malloc(sizeof(int) * (right - mid));

    int n1 = mid - left + 1;
    int n2 = right - mid;

    for(int i = 0; i < n1 ; i++)
    {
        L[i] = nums[left + i];
    }
    for(int j = 0 ; j < n2 ; j++)
    {
        R[j] = nums[mid + 1 + j];
    }

    int i = 0 , j = 0 , k = left;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            nums[k] = L[i];
            i++;
        }
        else
        {
            nums[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        nums[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        nums[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);

    return nums;
}

void mergesort(int* nums , int left , int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;

        mergesort(nums , left , mid);
        mergesort(nums , mid + 1 , right);

        merge(nums , left , right ,mid);
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize) 
{
    int left = 0 , right = numsSize - 1;
    mergesort(nums , left , right);
    *returnSize = numsSize;
    return nums;
}