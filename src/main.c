#include <stdio.h>

char *GIT_LOG_CMD = "git --no-pager log";

int main() {
	char buf[1024];
	FILE *git = popen(GIT_LOG_CMD, "r");
	while (fgets(buf, 1024, git)) {
		printf(buf);
	}
	printf("done!\n");
}
