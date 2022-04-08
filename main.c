#include "smolforthc.h"

int main(void) {
  smolforth_tok toks[5] = {
      smolforth_new_tok_double(3.14), smolforth_new_tok_integer(2),
      smolforth_new_tok_word("dup"),  smolforth_new_tok_word("*"),
      smolforth_new_tok_word("*"),
  };

  smolforth_word_list words = smolforth_word_list_default();

  smolforth_unit_stack stack =
      smolforth_unit_stack_new(malloc(sizeof(smolforth_unit) * 16), 0);

  smolforth_do(&toks[0], sizeof toks / sizeof toks[0], &words, &stack);

  return 0;
}
