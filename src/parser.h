#ifndef GIT_MATRIX_PARSER_H
#define GIT_MATRIX_PARSER_H

#include "utils.h"

typedef struct ParserCommit {
  char *committerEmail;
} ParserCommit;

typedef void (*ParserOnCommitCallback)(void *receiver, ParserCommit commit);

typedef struct ParserConfig {
  Continuation on_commit;
} ParserConfig;

typedef struct Parser {
  Continuation on_commit;
} Parser;

Parser parser_init(ParserConfig config);

void parser_add_chunk(Parser *parser, char *chunk);

#endif