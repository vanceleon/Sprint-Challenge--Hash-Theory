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

  // YOUR CODE HERE

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

