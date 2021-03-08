#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(vector<int> collection, int target);

int main() {
    vector<int> collection = {1, 3, 5, 48, 89, 99, 100};

    cout << binarySearch(collection, 5) << endl;
    cout << binarySearch(collection, 1) << endl;
    cout << binarySearch(collection, 100) << endl;
    cout << binarySearch(collection, 48) << endl;
    cout << binarySearch(collection, 55) << endl;
}

bool binarySearch(vector<int> collection, int target, int lowerIndex, int upperIndex) {
    if (upperIndex < lowerIndex) {
        return false;
    }

    int middleIndex = (upperIndex + lowerIndex) / 2;

    if (collection[middleIndex] == target) {
        return true;
    } else if (collection[middleIndex] < target) {
        return binarySearch(collection, target, middleIndex + 1, upperIndex);
    } else {
        return binarySearch(collection, target, lowerIndex, middleIndex - 1);
    }
}

bool binarySearch(vector<int> collection, int target) {
    return binarySearch(collection, target, 0, collection.size() - 1);
}
