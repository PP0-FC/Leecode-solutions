/**
 * @problem: 和为k的子数组
 * @approach: 哈希表
 * @time_complexity: O(n)
 * @space_complexity: O(n)
*/

#include <stdlib.h>
#include "uthash.h"   //这个是开源的库，提交时要注释掉

struct hashTable
{
    int key;
    int val;
    UT_hash_handle hh;
};


int subarraySum(int* nums, int numsSize, int k) {
    struct hashTable* hashtable = NULL;
    struct hashTable* new = malloc(sizeof(struct hashTable));
    new->key = 0;
    new->val = 1;
    HASH_ADD_INT(hashtable, key, new);

    int pre_sum = 0;
    int count = 0;
    for(int i = 0; i < numsSize; i++) {
        pre_sum += nums[i];

        int target = pre_sum - k;
        struct hashTable* temp = NULL;
        HASH_FIND_INT(hashtable, &target, temp);
        if(temp != NULL) {
            count += temp->val;
        }

        HASH_FIND_INT(hashtable, &pre_sum, temp);
        if(temp != NULL) {
            temp->val++;
        }
        else {
            struct hashTable* cur = malloc(sizeof(struct hashTable));
            cur->key = pre_sum;
            cur->val = 1;
            HASH_ADD_INT(hashtable, key, cur);
        }
    }
    return count;
}