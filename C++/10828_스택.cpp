#include <stdio.h>
using namespace std;

int main() {

	int st[10001] = { 0, };
	int index = -1;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		char cmd[6];
		scanf("%s", cmd);

		if (cmd[0] == 'p' && cmd[1] == 'u') scanf("%d", &st[++index]);
		else if (cmd[0] == 't') printf("%d\n", index < 0 ? -1 : st[index]);
		else if (cmd[0] == 'p') printf("%d\n", index < 0 ? -1 : st[index--]);
		else if (cmd[0] == 's') printf("%d\n", index + 1);
		else printf("%d\n", index < 0 ? 1 : 0);
	}
	return 0;
}
