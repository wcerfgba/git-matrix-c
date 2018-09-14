#include "parser.h"

Parser parser_init(ParserConfig config) {
  config.on_commit(config.on_commit_ctx, (ParserCommit){});
}