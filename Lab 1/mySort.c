/* Using Selection Sort*/

void mySort(int d[], unsigned int n) {
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++){
			if (d[j] < d[min]){
				min = j;
			}
		}
		if (i != min){
			int temp = d[i];
			d[i] = d[min];
			d[min] = temp;
		}
	}
}
