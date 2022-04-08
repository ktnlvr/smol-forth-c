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
    long long int as_integer;
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

typedef enum smolforth_unit_kind {
  SMOLFORTH_UNIT_INTEGER,
  SMOLFORTH_UNIT_DOUBLE,
} smolforth_unit_kind;

typedef struct smolforth_unit {
  smolforth_unit_kind kind;
  union {
    long long int as_integer;
    double as_double;
  };
} smolforth_unit;

void smolforth_do(smolforth_tok *in, size_t in_len, smolforth_unit *stack,
                  size_t stack_limit, size_t *stack_size_ptr) {
  size_t i = 0;
  for (i = 0; i < in_len; i++) {
    smolforth_tok_kind kind = in[i].kind;
    switch (kind) {
    case SMOLFORTH_TOK_INTEGER:
      stack[i].kind = SMOLFORTH_UNIT_INTEGER;
      stack[i].as_integer = in[i].as_integer;
      ++*stack_size_ptr;
      break;
    case SMOLFORTH_TOK_DOUBLE:
      stack[i].kind = SMOLFORTH_UNIT_DOUBLE;
      stack[i].as_double = in[i].as_double;
      ++*stack_size_ptr;
      break;
    }
  }
}

#endif
