#include "balanced_task.h"
#include "../stack/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static bool balanced_string_verified (char* s8L_string, uint8_t u8L_num_of_elements, uint8_t* u8L_num_of_valid_elements);
static bool is_string_balanced (char* s8L_string, uint8_t u8L_num_of_valid_elements);
static char get_pair (char s8L_bracket);

void balanced_task_run(void)
{
  uint8_t u8L_number_of_elements;
  uint8_t u8L_num_of_valid_elements;

  printf("Enter num of elements\n");
  scanf("%d", &u8L_number_of_elements);
  printf("%d\n", u8L_number_of_elements);
  char* cL_string = malloc(sizeof(char) * u8L_number_of_elements);
  if (cL_string != NULL)
  {
    printf("Enter string\n");
    getchar();
    scanf("%[^\n]s",cL_string);
    printf("%s\n", cL_string);

    if (balanced_string_verified(cL_string, u8L_number_of_elements, &u8L_num_of_valid_elements))
      (is_string_balanced(cL_string, u8L_num_of_valid_elements)) ? printf("String is balanced\n") : printf("String is not balanced\n");

    free(cL_string);
  }
}

static bool balanced_string_verified (char* cPL_string, uint8_t u8L_num_of_elements, uint8_t* u8L_num_of_valid_elements)
{
  if (cPL_string == NULL)
    return false;
  
  for (uint8_t i = 0; i < u8L_num_of_elements; i++)
  {
    if (*(cPL_string + i) == '\0' || *(cPL_string + i) == NULL)
    {
      *u8L_num_of_valid_elements = i;
      break;
    }

    if (*(cPL_string + i) != 0x20 && *(cPL_string + i) != 0x28 && *(cPL_string + i) != 0x29 
      && *(cPL_string + i) != 0x5B && *(cPL_string + i) != 0x5D && *(cPL_string + i) != 0x7B && *(cPL_string + i) != 0x7D)
    {
      printf("invalid input\n");
      return false;
    }
  }

  printf("valid input\n");
  return true;
}

static bool is_string_balanced (char* cPL_string, uint8_t u8L_num_of_valid_elements)
{
  if (cPL_string == NULL && u8L_num_of_valid_elements == 0)
    return false;

  stack_t* objPL_stack = create(sizeof(char), u8L_num_of_valid_elements);

  for (uint8_t i = 0; i < u8L_num_of_valid_elements; i++)
  {
    if (*(cPL_string + i) != 0x20)
    {
      if (is_empty(objPL_stack))
      {
        if (get_pair(*(cPL_string + i)) == 0x20)
          return false;

        push(objPL_stack, (cPL_string + i));
      }
      else if (get_pair(*(cPL_string + i)) != 0x20)
      {
        push(objPL_stack, (cPL_string + i));
      }
      else if (get_pair(*(cPL_string + i)) == 0x20)
      {
        char cL_last_open_brasket;
        pop(objPL_stack, &cL_last_open_brasket);
        if (get_pair(cL_last_open_brasket) != *(cPL_string + i))
        {
          return false;
        }
      }
    }
  }
  return true;
}

static char get_pair (char cL_bracket)
{
  switch (cL_bracket)
  {
    case 0x28: return 0x29; break;
    
    case 0x5b: return 0x5d; break;
    
    case 0x7b: return 0x7d; break;

    default: return 0x20; break;
  }
}