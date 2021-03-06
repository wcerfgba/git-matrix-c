#include "parser.h"

Parser parser_init(ParserConfig config) {
  return (Parser){
    .on_commit = config.on_commit,
  };
}

void parser_add_chunk(Parser *parser, char *chunk) {
  ParserCommitFile *files = NULL;
  sb_push(files, (ParserCommitFile){ .name = "yaya.txt" });
  call(parser->on_commit, (ParserCommit){
    .committerEmail = "qwe@asd.com",
    .files = files
  });
}