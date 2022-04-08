#include <stdio.h>

#define SMOLFORTH_USE_EXT_DEFAULT_BUILTINS_LIST
#include "smolforthc.h"

int main(void) {
  smolforth_tok toks[10] = {
      smolforth_new_tok_double(111),  smolforth_new_tok_double(3.14),
      smolforth_new_tok_integer(-2),  smolforth_new_tok_word("abs"),
      smolforth_new_tok_word("noop"), smolforth_new_tok_word("dup"),
      smolforth_new_tok_word("*"),    smolforth_new_tok_word("*"),
      smolforth_new_tok_word("swap"), smolforth_new_tok_word("drop"),
  };

  smolforth_word_list builtins = smolforth_word_list_default();
  smolforth_ctx ctx = smolforth_ctx_new(&toks[0], 10, &builtins);

  size_t i = 0;
  size_t len = sizeof toks / sizeof toks[0];
  for (i = 0; i < len; i++) {
    smolforth_status_ret status = smolforth_do_step(&ctx, i);

    if (status != SMOLFORTH_STATUS_OK) {
      printf("exited with status %d.\n", status);
      return 1;
    }

    printf("|");
    size_t j = 0;
    for (j = 0; j < ctx.stack.len; j++) {
      switch (ctx.stack.units[j].kind) {
      case SMOLFORTH_UNIT_DOUBLE:
        printf(" %e", ctx.stack.units[j].as_double);
        break;
      case SMOLFORTH_UNIT_INTEGER:
        printf(" %d", ctx.stack.units[j].as_integer);
        break;
      }
    }
    printf("\n");
  }

  return 0;
}
