#include "smolforthc.h"

int main(void) {
  smolforth_tok toks[5] = {
      smolforth_new_tok_double(3.14), smolforth_new_tok_integer(2),
      smolforth_new_tok_word("dup"),  smolforth_new_tok_word("*"),
      smolforth_new_tok_word("*"),
  };

  smolforth_word_list words = smolforth_word_list_default();

  size_t size = 16;
  size_t stack_size = 0;
  smolforth_unit *stack = malloc(sizeof(smolforth_unit) * size);
  smolforth_do(&toks[0], sizeof toks / sizeof toks[0], &words, &stack[0], 16,
               &stack_size);

  return 0;
}
