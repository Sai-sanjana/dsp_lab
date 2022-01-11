#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

struct Stack_Structure
{
      int top;
      int *array;
      int high;
};

struct Stack_Structure* createStack(int high)
{
      struct Stack_Structure* stack_object = (struct Stack_Structure*)malloc(sizeof(struct Stack_Structure));
      stack_object -> high = high;
      stack_object -> top = -1;
      stack_object -> array = (int*)malloc(stack_object -> high*sizeof(int));
      return stack_object;
}

int isEmpty(struct Stack_Structure* stack_object)
{
      return (stack_object->top == -1);
}

int isFull(struct Stack_Structure* stack_object)
{
      return (stack_object->top == stack_object->high - 1);
}

void print_shift(char fromT, char toT, int disk)
{
      printf("Move Disk %d from \'%c\' to \'%c\'\n", disk, fromT, toT);
}

void send_element(struct Stack_Structure *stack_object, int item)
{
      if(isFull(stack_object))
      {
            return;
      }
      stack_object -> array[++stack_object -> top] = item;
}

int remove_element(struct Stack_Structure* stack_object)
{
      if(isEmpty(stack_object))
      {
            return INT_MIN;
      }
      return stack_object -> array[stack_object -> top--];
}

void shift_Disks(struct Stack_Structure *st, struct Stack_Structure *dt, char source, char destination)
{
      int tower1 = remove_element(st);
      int tower2 = remove_element(dt);
      if(tower1 == INT_MIN)
      {
            send_element(st, tower2);
            print_shift(destination, source, tower2);
      }
      else if(tower2 == INT_MIN)
      {
            send_element(dt, tower1);
            print_shift(source, destination, tower1);
      }
      else if(tower1 > tower2)
      {
            send_element(st, tower1);
            send_element(st, tower2);
            print_shift(destination, source, tower2);
      }
      else
      {
            send_element(dt, tower2);
            send_element(dt, tower1);
            print_shift(source, destination, tower1);
      }
}

void tower_of_hanoi(int limit, struct Stack_Structure *st, struct Stack_Structure *temporary_tower, struct Stack_Structure *dt)
{
      int count, shift;
      char destination = 'D', source = 'S', temporary = 'A';
      if(limit % 2 == 0)
      {
            char x = destination;
            destination = temporary;
            temporary  = x;
      }
      shift = pow(2, limit) - 1;
      for(count = limit; count >= 1; count--)
      {
            send_element(st, count);
      }
      for(count = 1; count <= shift; count++)
      {
            if(count%3 == 1)
            {
                  shift_Disks(st, dt, source, destination);
            }
            else if(count%3 == 2)
            {
                  shift_Disks(st, temporary_tower, source, temporary);
            }
            else if(count%3 == 0)
            {
                  shift_Disks(temporary_tower, dt, temporary, destination);
            }
      }
}

int main()
{
      int n;
      struct Stack_Structure *st, *dt, *tt;
      while(1){
      printf("Enter The Number of Disks:\t");
      scanf("%d", &n);
      if(n == 0) break;
      printf("\nSequence of Disk Moves:\n");
      st = createStack(n);
      tt = createStack(n);
      dt = createStack(n);
      tower_of_hanoi(n, st, tt, dt);
      printf("\n");
      }
      return 0;
}
