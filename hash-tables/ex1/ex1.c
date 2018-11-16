#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

typedef struct Answer {
  int index_1;
  int index_2;
}Answer;


Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);
  int hashKey = hash(weights, ht->capacity);
  // YOUR CODE HERE

// insert weights and limit into 
Answer *answer = answer;
for (int i = 0; i < length; i++) {
  hash_table_insert(ht, weights, answer);
}

int sumWeights = 0;
for (int i = 0; i < ht->capacity; i++) {
  
}


// pseudo code

// implement get indices of item weights
// finds two items sum of weights equals the weight limit
// will then return a struct





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