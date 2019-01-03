#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

// typedef struct Ticket {
//   char *source;
//   char *destination;
// } Ticket;


char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *hash = create_hash_table(16);
  char **route = malloc(length * sizeof(char *));

  // YOUR CODE 
  // Setup hash table, with sources as keys and destinations as values
  for (int i = 0; i < length; i++ ){
    hash_table_insert(hash, tickets[i]->source, tickets[i]->destination);
  }

  char *midFlight;
  char *source = "NONE";
  for (int j = 0; j < length; j++) {
  
    midFlight = hash_table_retrieve(hash, source); //next flight
    source = midFlight;

    route[j] = strdup(midFlight);

  }
  print_route(route, length);
  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++) {
    printf("%s\n", route[i]);
  }
  printf("\n");
}


#ifndef TESTING
int main(void)
{
  Ticket **tickets = malloc(3 * sizeof(Ticket *));

  Ticket *ticket_1 = malloc(sizeof(Ticket));
  ticket_1->source = "NONE";
  ticket_1->destination = "PDX";
  tickets[0] = ticket_1;

  Ticket *ticket_2 = malloc(sizeof(Ticket));
  ticket_2->source = "PDX";
  ticket_2->destination = "DCA";
  tickets[1] = ticket_2;

  Ticket *ticket_3 = malloc(sizeof(Ticket));
  ticket_3->source = "DCA";
  ticket_3->destination = "NONE";
  tickets[2] = ticket_3;

  // char *expected[] = { "PDX", "DCA", "NONE" };
  print_route(reconstruct_trip(tickets, 3), 3);

  return 0;
}
#endif