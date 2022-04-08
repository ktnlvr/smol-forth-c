#ifndef __KITTENLOVER__SMOLFORTH_C__
#define __KITTENLOVER__SMOLFORTH_C__

#include <stdlib.h>

typedef enum smolforth_tok_kind {
  SMOLFORTH_TOK_INTEGER,
  SMOLFORTH_TOK_WORD,
  SMOLFORTH_TOK_DOUBLE,
} smolforth_tok_kind;

typedef struct smolforth_tok {
  smolforth_tok_kind kind;
  union {
    int as_integer;
    const char *as_word;
    double as_double;
  };
} smolforth_tok;

smolforth_tok smolforth_new_tok_integer(long long int integer) {
  smolforth_tok ret;
  ret.kind = SMOLFORTH_TOK_INTEGER;
  ret.as_integer = integer;
  return ret;
}

smolforth_tok smolforth_new_tok_word(const char *word) {
  smolforth_tok ret;
  ret.kind = SMOLFORTH_TOK_WORD;
  ret.as_word = word;
  return ret;
}

smolforth_tok smolforth_new_tok_double(double doublee) {
  smolforth_tok ret;
  ret.kind = SMOLFORTH_TOK_DOUBLE;
  ret.as_double = doublee;
  return ret;
}

#endif
