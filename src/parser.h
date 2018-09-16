#ifndef GIT_MATRIX_PARSER_H
#define GIT_MATRIX_PARSER_H

typedef struct ParserCommit {

} ParserCommit;

typedef void (*ParserOnCommitCallback)(void *ctx, ParserCommit commit);

typedef struct ParserOnCommitClosure {
  ParserOnCommitCallback on_commit;
  void *on_commit_ctx;
} ParserOnCommitClosure;

typedef struct ParserConfig {
  struct ParserOnCommitClosure;
} ParserConfig;

typedef struct Parser {

} Parser;

Parser parser_init(ParserConfig config);

void parser_add_chunk(Parser *parser, char *chunk);

#endif