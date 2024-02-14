#include <iostream>
#include <fstream>
#include <sstream>
#include <string>



struct Date {
    double year;
    std::string TypeOFPeriod_str;
    std::string Period_str;
    double avg_rainfall;
    double avg_temp;
    Date* next;
};

void merge(Date arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Date L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i].avg_rainfall > R[j].avg_rainfall) {
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
}

void mergeSort(Date arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void swap(Date& a, Date& b) {
    Date temp = a;
    a = b;
    b = temp;
}

int partition(Date arr[], int low, int high) {
    double pivot = arr[high].avg_temp;
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].avg_temp < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Date arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::ifstream file("avg_rainfalltemp in UK.csv");

    if (!file.is_open()) {
        std::cerr << "Could not open file!\n";
        return 1;
    }

    std::string line;
    std::getline(file, line); // skip header line

    Date* head = nullptr;
    Date* tail = nullptr;

    while (std::getline(file, line)) {
        double year;
        std::stringstream ss(line);
        std::string TypeOFPeriod_str;
        std::string Period_str;
        double avg_rainfall;
        double avg_temp;

        ss >> year;
        ss.ignore();
        std::getline(ss, TypeOFPeriod_str, ',');
        std::getline(ss, Period_str, ',');
        ss >> avg_rainfall;
        ss.ignore();
        ss >> avg_temp;

        Date* new_node = new Date{year, TypeOFPeriod_str, Period_str, avg_rainfall, avg_temp, nullptr};

        if (tail == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    file.close();

    // Convert the linked list into an array
    int size = 0;
    for (Date* curr = head; curr != nullptr; curr = curr->next) {
        size++;
    }

    Date* arr = new Date[size];
    int i = 0;
    for (Date* curr = head; curr != nullptr; curr = curr->next) {
        arr[i++] = *curr;
    }

    // Sort the array using quicksort
    quickSort(arr, 0, size - 1);


    // Convert the sorted array back into a linked list
    head = nullptr;
    tail = nullptr;
    for (int i = 0; i < size; i++) {
        Date* new_node = new Date{arr[i].year, arr[i].TypeOFPeriod_str, arr[i].Period_str, arr[i].avg_rainfall, arr[i].avg_temp, nullptr};

        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    Date* curr = head;
    while (curr != nullptr) {
        std::cout << curr->year << ", " << curr->TypeOFPeriod_str << ", " << curr->Period_str << ", " << curr->avg_rainfall << ", " << curr->avg_temp << std::endl;
        curr = curr->next;
    }
}