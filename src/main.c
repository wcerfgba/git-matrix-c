#define _POSIX_C_SOURCE 2

#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "parser.h"
#include "render_csv.h"
#include "utils.h"

#define GIT_LOG_CMD "GIT_FLUSH=0 git --no-pager log --format='%n%n%ct %cE' --numstat --no-renames"
#define GIT_READ_BUFFER_LENGTH 1024

typedef struct GodContext {
	Matrix *matrix;
	Parser *parser;
} GodContext;

void on_git_chunk(GodContext *ctx, char *chunk) {
	parser_add_chunk(ctx->parser, chunk);
}

void on_commit(GodContext *ctx, ParserCommit commit) {
	matrix_add_commit(ctx->matrix, commit);
}

int main() {
	Matrix matrix = matrix_init((MatrixConfig){ .type = MATRIX_TYPE_CHANGE_COUNT });

	Parser parser = parser_init((ParserConfig){
		.on_commit = on_commit,
		.on_commit_ctx = &(GodContext){ .matrix = &matrix }
	});

	char buf[GIT_READ_BUFFER_LENGTH];
	FILE *git = popen(GIT_LOG_CMD, "r");
	
	if (git == NULL) {
		log_error("Failed to popen");
		exit(1);
	}

	while (fgets(buf, GIT_READ_BUFFER_LENGTH, git)) {
		parser_add_chunk(&parser, buf);
	}

	// pclose(git);

	matrix_sort(&matrix);
	
	FILE *output = stdout;
	char *output_string = render_csv(&matrix);

	if (fputs(output_string, output) == EOF) {
		log_error("Failed to fputs: ", ferror(output));
	}
}