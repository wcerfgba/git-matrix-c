#ifndef GIT_MATRIX_PARSER_H
#define GIT_MATRIX_PARSER_H

#include "utils.h"

typedef struct ParserCommitFile {
  char *name;
} ParserCommitFile;

typedef struct ParserCommit {
  char *committerEmail;
  int committerTimestamp;
  ParserCommitFile *files;
} ParserCommit;

typedef struct ParserConfig {
  Continuation on_commit;
} ParserConfig;

typedef struct Parser {
  Continuation on_commit;
} Parser;

Parser parser_init(ParserConfig config);

void parser_add_chunk(Parser *parser, char *chunk);

#endif