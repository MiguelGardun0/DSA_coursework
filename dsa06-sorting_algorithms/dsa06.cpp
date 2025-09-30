
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

void printArray(const vector<int>& arr, const string& message = "") {
    if (!message.empty()) {
        cout << message << ": ";
    }
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// BUCKET SORT 
void bucketSort(vector<int> arr) {
    cout << "\n=== BUCKET SORT ===" << endl;
    printArray(arr, "Original array");
    
    if (arr.empty()) return;
    
    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());
    int n = arr.size();
    int numBuckets = max(1, n / 10);
    
    cout << "\nNumber of buckets: " << numBuckets << endl;
    cout << "Range: [" << minVal << ", " << maxVal << "]" << endl;
    
    vector<vector<int>> buckets(numBuckets);
    double range = (double)(maxVal - minVal + 1) / numBuckets;
    
    cout << "\nDistributing elements into buckets:" << endl;
    for (int num : arr) {
        int bucketIndex = min((int)((num - minVal) / range), numBuckets - 1);
        buckets[bucketIndex].push_back(num);
        cout << "  Element " << num << " -> Bucket " << bucketIndex << endl;
    }
    
    cout << "\nBuckets before sorting:" << endl;
    for (int i = 0; i < numBuckets; i++) {
        cout << "  Bucket " << i << ": ";
        printArray(buckets[i]);
    }
    
    cout << "\nSorting individual buckets:" << endl;
    for (int i = 0; i < numBuckets; i++) {
        if (!buckets[i].empty()) {
            cout << "  Sorting Bucket " << i << ":" << endl;
            sort(buckets[i].begin(), buckets[i].end());
            cout << "    Result: ";
            printArray(buckets[i]);
        }
    }
    
    cout << "\nConcatenating buckets:" << endl;
    arr.clear();
    for (int i = 0; i < numBuckets; i++) {
        for (int num : buckets[i]) {
            arr.push_back(num);
        }
    }
    
    printArray(arr, "\nFinal sorted array");
}

// INSERTION SORT 
void insertionSort(vector<int> arr) {
    cout << "\n=== INSERTION SORT ===" << endl;
    printArray(arr, "Original array");
    
    int n = arr.size();
    cout << "\nSorting process:" << endl;
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        cout << "\nPass " << i << ":" << endl;
        cout << "  Key = " << key << " (at position " << i << ")" << endl;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            cout << "    Moving " << arr[j] << " from position " << j 
                 << " to position " << (j + 1) << endl;
            j--;
        }
        arr[j + 1] = key;
        cout << "  Inserting " << key << " at position " << (j + 1) << endl;
        cout << "  Array: ";
        printArray(arr);
    }
    
    printArray(arr, "\nFinal sorted array");
}

// SELECTION SORT 
void selectionSort(vector<int> arr) {
    cout << "\n=== SELECTION SORT ===" << endl;
    printArray(arr, "Original array");
    
    int n = arr.size();
    cout << "\nSorting process:" << endl;
    
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        
        cout << "\nPass " << (i + 1) << ":" << endl;
        cout << "  Looking for minimum in range [" << i << ", " << (n-1) << "]" << endl;
        
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        
        cout << "  Minimum found: " << arr[minIdx] << " at position " << minIdx << endl;
        
        if (minIdx != i) {
            cout << "  Swapping " << arr[i] << " (pos " << i 
                 << ") with " << arr[minIdx] << " (pos " << minIdx << ")" << endl;
            swap(arr[i], arr[minIdx]);
        }
        
        cout << "  Array: ";
        printArray(arr);
    }
    
    printArray(arr, "\nFinal sorted array");
}

// MERGE SORT
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    cout << "  Merging: Left = ";
    printArray(L);
    cout << "           Right = ";
    printArray(R);
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    cout << "  Result: [";
    for (int idx = left; idx <= right; idx++) {
        cout << arr[idx];
        if (idx < right) cout << ", ";
    }
    cout << "]" << endl;
}

void mergeSortHelper(vector<int>& arr, int left, int right, int& step) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        cout << "\nStep " << (++step) << ": Dividing [" << left << ", " << right << "]" << endl;
        cout << "  Left half: [" << left << ", " << mid << "]" << endl;
        cout << "  Right half: [" << (mid+1) << ", " << right << "]" << endl;
        
        mergeSortHelper(arr, left, mid, step);
        mergeSortHelper(arr, mid + 1, right, step);
        
        cout << "\nStep " << (++step) << ": Merging [" << left << ", " << mid 
             << "] and [" << (mid+1) << ", " << right << "]" << endl;
        merge(arr, left, mid, right);
    }
}

void mergeSort(vector<int> arr) {
    cout << "\n=== MERGE SORT ===" << endl;
    printArray(arr, "Original array");
    
    cout << "\nSorting process (Divide and Conquer):" << endl;
    int step = 0;
    mergeSortHelper(arr, 0, arr.size() - 1, step);
    
    printArray(arr, "\nFinal sorted array");
}

// QUICK SORT 
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    cout << "  Pivot = " << pivot << " (at position " << high << ")" << endl;
    
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            if (i != j) {
                cout << "    Swapping " << arr[i] << " and " << arr[j] << endl;
                swap(arr[i], arr[j]);
            }
        }
    }
    
    swap(arr[i + 1], arr[high]);
    cout << "  Placing pivot " << pivot << " at position " << (i + 1) << endl;
    
    cout << "  Array segment: [";
    for (int idx = low; idx <= high; idx++) {
        cout << arr[idx];
        if (idx < high) cout << ", ";
    }
    cout << "]" << endl;
    
    return i + 1;
}

void quickSortHelper(vector<int>& arr, int low, int high, int& step) {
    if (low < high) {
        cout << "\nStep " << (++step) << ": Partitioning range [" << low << ", " << high << "]" << endl;
        
        int pi = partition(arr, low, high);
        
        cout << "  Pivot index = " << pi << endl;
        
        quickSortHelper(arr, low, pi - 1, step);
        quickSortHelper(arr, pi + 1, high, step);
    }
}

void quickSort(vector<int> arr) {
    cout << "\n=== QUICK SORT ===" << endl;
    printArray(arr, "Original array");
    
    cout << "\nSorting process (Divide and Conquer):" << endl;
    int step = 0;
    quickSortHelper(arr, 0, arr.size() - 1, step);
    
    printArray(arr, "\nFinal sorted array");
}

//  FILE READING 
vector<int> readFile(const string& filename) {
    vector<int> data;
    ifstream file(filename);
    
    if (!file.is_open()) {
        cout << "Error: Could not open file '" << filename << "'" << endl;
        return data;
    }
    
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        
        while (getline(ss, token, ',')) {
            try {
                data.push_back(stoi(token));
            } catch (...) {
                cout << "Warning: Could not parse '" << token << "'" << endl;
            }
        }
    }
    
    file.close();
    cout << "Successfully loaded " << data.size() << " elements from file." << endl;
    return data;
}

int main() {

    string filename;
    cout << "\nEnter the name of the input file: ";
    getline(cin, filename);
    
    vector<int> data = readFile(filename);
    
    if (data.empty()) {
        cout << "No data to sort. Exiting." << endl;
        return 1;
    }
    
    int choice;
    bool running = true;
    
    while (running) {
        cout << "\n========================================" << endl;
        cout << "        SORTING ALGORITHM MENU" << endl;
        cout << "========================================" << endl;
        cout << "1. Bucket Sort" << endl;
        cout << "2. Insertion Sort" << endl;
        cout << "3. Selection Sort" << endl;
        cout << "4. Merge Sort" << endl;
        cout << "5. Quick Sort" << endl;
        cout << "6. Exit" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice (1-6): ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                bucketSort(data);
                break;
            case 2:
                insertionSort(data);
                break;
            case 3:
                selectionSort(data);
                break;
            case 4:
                mergeSort(data);
                break;
            case 5:
                quickSort(data);
                break;
            case 6:
                cout << "\nThank you for using the sorting program!" << endl;
                running = false;
                break;
            default:
                cout << "\nInvalid choice. Please enter a number between 1 and 6." << endl;
        }
        
        if (running && choice >= 1 && choice <= 5) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
    }
    
    return 0;
}