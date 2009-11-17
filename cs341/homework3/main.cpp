// Terry Lorber
// tgl@rideside.net
// U61244526

// MET CS341
// Fall 2009
// Maslanka

// Homework #3

#include "Queue.h"

#include <cassert>
#include <cstdlib>
#include <iostream>

static void
self_test()
{
  Queue queue;

  queue.push(5.);
  queue.push(3.);
  queue.push(2.);

  assert(!queue.empty());
  assert(3 == queue.size());

  assert(5. == queue.front());

  queue.pop();

  assert(!queue.empty());
  assert(2 == queue.size());

  assert(3. == queue.front());

  queue.pop();

  assert(!queue.empty());
  assert(1 == queue.size());

  assert(2. == queue.front());

  queue.pop();

  assert(queue.empty());
}// self_test

int
main(int argc, char* argv[])
{
  self_test();

  return EXIT_SUCCESS;
}// main
