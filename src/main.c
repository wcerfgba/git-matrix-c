#include <stdio.h>

#include "matrix.h"
#include "parser.h"

#define GIT_LOG_CMD "GIT_FLUSH=0 git --no-pager log --format='%n%n%ct %cE' --numstat --no-renames"
#define GIT_READ_BUFFER_LENGTH 1024

typedef struct GodContext {
	Matrix *matrix;
} GodContext;

void on_commit(GodContext *ctx, ParserCommit commit) {
	printf(ctx->matrix->qwe);
}

int main() {
	Matrix matrix = matrix_init();

	Parser parser = parser_init((ParserConfig){
		.on_commit = on_commit,
		.on_commit_ctx = &(GodContext){ .matrix = &matrix }
	});

	char buf[GIT_READ_BUFFER_LENGTH];
	FILE *git = popen(GIT_LOG_CMD, "r");
	while (fgets(buf, GIT_READ_BUFFER_LENGTH, git)) {
		printf(buf);
	}
}