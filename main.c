#include "smolforthc.h"

int main(void) {
  smolforth_tok toks[5] = {
      smolforth_new_tok_double(3.14), smolforth_new_tok_integer(2),
      smolforth_new_tok_word("dup"),  smolforth_new_tok_word("*"),
      smolforth_new_tok_word("*"),
  };

  return 0;
}
