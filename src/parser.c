#include "parser.h"

Parser parser_init(ParserConfig config) {
  config.on_commit(config.on_commit_ctx, (ParserCommit){});
}

void parser_add_chunk(Parser *parser, char *chunk) {
  
}