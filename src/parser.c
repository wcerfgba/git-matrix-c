#include "parser.h"

Parser parser_init(ParserConfig config) {
  return (Parser){
    .on_commit = config.on_commit,
    .on_commit_ctx = config.on_commit_ctx
  };
}

void parser_add_chunk(Parser *parser, char *chunk) {
  parser->on_commit(parser->on_commit_ctx, (ParserCommit){
    .committerEmail = "qwe@asd.com"
  });
}