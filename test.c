int min(int u, int v)
{
	if (u < v) return u;
	else return v;
}

int main(void)
{
	int x;
	int y;
	x = 1;
	y = 1 + 2;
	if (x < 3) {
		while (y > 0) {
			y = y - 1;
		}
	}
	x = min(x, y);
	return;
}