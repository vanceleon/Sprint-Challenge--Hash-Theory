#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);
  int hashKey = hash(weights, ht->capacity);
  // YOUR CODE HERE

  // insert weights and limit into 
  Answer *answer = malloc(sizeof(Answer));
  for (int i = 0; i < length; i++) {
    hash_table_insert(ht, weights[i], i);
  }
  printf("length %d\n ", length);
  printf("weights %d\n ", weights[0]);  
  // int sumWeights = 0;
  // printf("\tBP %d", q++);

  // for(int j = 0; j < 2; j++) {
  //   printf("loops work at this point\n");
  // }

  for (int j = 0; j < length; j++) {
      // get value from each index 
      int w1 = weights[j];
      // subtract that value from limit
      int w2 = limit - w1;
      // test that value weight in hash function 
      int found_index = hash_table_retrieve(ht, w2);
      // printf("\tw1: %d, w2: %d, found_index: %d\n", w1, w2, found_index);
      if(found_index > -1)
      {
        answer->index_1 = j;
        answer->index_2 = found_index;
        return answer;
      }
      // if true return that pair 
      // if false continue 
  }
  return NULL;


  // pseudo code

  // implement get indices of item weights
  // finds two items sum of weights equals the weight limit
  // will then return a struct

  HashTable *itemWeights = hash_table_retrieve(ht, hashKey);



  // each struct field represents the item weights 
  // higher value index at index_1 
  // smaller at index_2






  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};

  Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7);

  if (answer_4->index_1 != 6)
    printf("Your function did not return the expected answer for input {12, 6, 7, 14, 19, 3, 0, 25, 40}");
  if (answer_4->index_2 != 2)
    printf("Your function did not return the expected answer for input {12, 6, 7, 14, 19, 3, 0, 25, 40}");

  return 0;
}
#endif