#include<stdio.h>
#include<stdlib.h>
 
void printArray(int* A, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int *A, int n){
    int key, j;
    for (int i = 1; i <= n-1; i++){
        printf("Pass %d\n", i);
        key = A[i];
        j = i-1;
        while(j>=0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        printArray(A, n);  
    }
}

void selectionSort(int *A, int n){
    int indexOfMin, temp;
    for (int i = 0; i < n-1; i++){
        printf("Pass %d\n", i+1);
        indexOfMin = i;
        for (int j = i+1; j < n; j++)
        {
            if(A[j] < A[indexOfMin]){
                indexOfMin = j;
            }
        }
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
        printArray(A, n);
    }
}

void bubbleSort(int *A, int n){
    int temp, i, j, flag;
    for (i = 0; i < n; i++){
        printf("Pass %d\n", i+1);
        flag = 0;
        j = n - 1;
        while(j > i){
            if(A[j] < A[j-1]){
                temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
                flag = 1;
            } j--;
        }
        printArray(A, n);
        if(!flag){
            break;
        }
    } 
}

int partition(int *A, int low, int high){
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    do{
        while (A[i] <= pivot){
            i++;
        }
        while (A[j] > pivot){
            j--;
        }
        if (i < j){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int *A, int n, int low, int high){
    int partitionIndex;
    static int i = 1;
    if (low < high){
        partitionIndex = partition(A, low, high);
        printf("Pass %d : ", i++);
        printArray(A,n);
        quickSort(A, n, low, partitionIndex - 1);
        quickSort(A, n, partitionIndex + 1, high);
    }
}

void merge(int *A, int mid, int low, int high){
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high){
        if (A[i] < A[j]){
            B[k] = A[i];
            i++;
            k++;
        }else{
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid){
        B[k] = A[i];
        k++;
        i++;
    }while (j <= high){
        B[k] = A[j];
        k++;
        j++;
    }for (int i = low; i <= high; i++){
        A[i] = B[i];
    }
}


void mergeSort(int *A, int n, int low, int high){
    int mid;
    static int i = 1; 
    if(low<high){
        mid = (low + high) /2;
        mergeSort(A, n, low, mid);
        mergeSort(A, n, mid+1, high);
        merge(A, mid, low, high);
        printf("Pass %d : ", i++);
        printArray(A, n);
    }
}

void heapify(int* A, int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right  = 2 * i + 2;
    if (left < n && A[left] > A[largest]){
        largest = left;
    }if (right < n && A[right] > A[largest]){
        largest = right;
    }
    if (largest != i){
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        heapify(A, n, largest);
    }
}

void heapSort(int* A, int n){
    for (int i = n/2 - 1; i >= 0; i--){
        heapify(A, n, i);
    }

    for (int i = n - 1; i >= 0; i--){
        int temp = A[i];
        A[i] = A[0];
        A[0] = temp;
        heapify(A, i, 0);
    }
    printArray(A, n);
}
 
int main(){
    int n, i, ch = 0;
    printf("How many elements would you like to enter? : ");
    scanf("%d", &n);
    int* A = (int*)malloc(sizeof(int)*n);
    printf("Enter array : ");
    for(i=0;i<n;i++){
        scanf("%d", A+i);
    }
    printf("^^^^^^^^^^^^^^^^\n");
    printf("1.Insertion Sort\n2.Selection Sort\n3.Bubble Sort\n4.Quick Sort\n5.Merge Sort\n6.Heap Sort\n7.Exit\nEnter Choice : ");
    scanf("%d", &ch);
    printf("^^^^^^^^^^^^^^^^\n");
    switch (ch){
    case 1:
        insertionSort(A, n);
        break;
    case 2:
        selectionSort(A, n);
        break;
    case 3:
        bubbleSort(A, n);
        break;
    case 4:
        quickSort(A, n, 0, n-1);
        break;
    case 5:
        mergeSort(A, n, 0, n-1);
        break;
    case 6:
        heapSort(A, n);
        break;
    case 7:
        printf("Exiting program...");
        break;
    default:
        printf("Invalid Choice");
        break;
        }
    return 0;
}
