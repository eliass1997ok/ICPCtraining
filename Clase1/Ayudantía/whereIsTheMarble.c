#include <stdio.h>

int binarySearch(int* array, int l, int r, int x){
	if(r>=l){
		int mid;
		mid = l + (r-l) / 2;
		if(array[mid] == x) return mid;
		else if (array[mid] > x) return binarySearch(array, l, mid-1, x);
		else return binarySearch(array, mid+1, r, x);
	}
	else return -1;
}

void swap(int *a, int *b)
{
   int t;
 
   t  = *b;
   *b = *a;
   *a = t;
}

int partition (int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);
 	int j;

    for (j = low; j <= high- 1; j++){
        if (arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
void quickSort(int arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int bruteForce(int arr[], int number, int size){
	int i;
	for(i=0; i<size; i++) if (arr[i] == number) return i;
	return -1;
}

int main(){
	int flag, j;
	flag = 1;
	j=1;

	while(flag){
		int marbles, queries;
		scanf("%d %d", &marbles, &queries);

		if(marbles == 0 && queries == 0) flag = 0;
		else{
			int marblesList[marbles], queriesList[queries];
			int i;

			for(i=0; i<marbles; i++) scanf("%d", &marblesList[i]);
			for(i=0; i<queries; i++) scanf("%d", &queriesList[i]);

			printf("CASE# %d:\n", j);
			quickSort(marblesList, 0, marbles-1);

			for(i=0; i<queries; i++){
				int position;

				position = bruteForce(marblesList, queriesList[i], marbles);
				if(position == -1) printf("%d not found\n", queriesList[i]);
				else printf("%d found at %d\n", queriesList[i], position+1);
			}
			j++;

		}
	}


	return 0;
}