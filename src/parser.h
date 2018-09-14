#ifndef GIT_MATRIX_PARSER_H
#define GIT_MATRIX_PARSER_H

typedef struct ParserCommit {

} ParserCommit;

typedef struct ParserConfig {
  void (*on_commit)(void *ctx, ParserCommit commit);
  void *on_commit_ctx;
} ParserConfig;

typedef struct Parser {

} Parser;

extern Parser parser_init(ParserConfig config);

#endif