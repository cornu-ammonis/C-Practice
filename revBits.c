unsigned int rev (int i, int j, unsigned int A) {
	
	int lo = (A >> i) & 1;
	int hi = (A >> j) & 1;
	
	if (lo ^ hi) 
		A ^= (lo << i) | (hi << j);
	
	return A;
	
	}
unsigned int revBits(unsigned int A) {
	
}

int main() {
	return 1;
}
