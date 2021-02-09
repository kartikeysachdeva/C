//Binary Search
#define size 8
main()
{
	int key,pos,i;
	int arr[size];
	printf("Enter %d values ",size);
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
	printf("Enter value to search ");
	scanf("%d",&key);
	pos = binarysearch(arr,key);
	if (pos == -1)
		printf("Not Found");
	else
		printf("Element found at index %d",pos);
}
int binarysearch(int arr[],int key)
{
	int mid;
	int low=0,high=size-1;
	while (low <= high)
	{
		mid = (low + high)/2;
		if (arr[mid] == key)
			return mid;
		if (arr[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

