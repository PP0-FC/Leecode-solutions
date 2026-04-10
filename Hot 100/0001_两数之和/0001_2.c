/**
 * @problem: 两数之和,返回数组下标
 * @approach: 哈希表
 * @time_complexity: O(n)
 * @space_complexity: O(1)
 */ 

#include <stdlib.h>
#include "uthash.h"   //这个是开源的库，提交时要注释掉

struct hashTable
{
    int key;
    int val;
    UT_hash_handle hh;
};

struct hashTable* hashTable;

struct hashTable* find(int ikey)
{
    struct hashTable* temp;
    HASH_FIND_INT(hashTable, &ikey, temp);
    return temp;
}

void insert(int ikey, int ival)
{
    struct hashTable* cur = find(ikey);
    if(cur == NULL)
    {
        struct hashTable* temp = malloc(sizeof(struct hashTable));
        temp->key = ikey, temp->val = ival;
        HASH_ADD_INT(hashTable, key, temp);
    }
    else
    {
        cur->val = ival;
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    hashTable = NULL;
    for(int i = 0; i < numsSize; i++)
    {
        struct hashTable* it = find(target - nums[i]);
        if(it != NULL)
        {
            int* ans = malloc(sizeof(int) * 2);
            ans[0] = i;
            ans[1] = it->val;
            *returnSize = 2;
            return ans;
        }
        else
        {
            insert(nums[i], i);
        }
    }

    *returnSize = 0;
    return NULL;
}