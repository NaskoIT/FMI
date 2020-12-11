#include <iostream>
#include <vector>
using namespace std;

int sumTriangle(vector<int>& sequence);

int main() {
    vector<int> array =  {1, 2, 3, 4, 5};

    cout << sumTriangle(array);
}

int sumTriangle(vector<int>& sequence) {
    if(sequence.size() == 1) {
        return  sequence[0];
    }

    vector<int> upperSequence(sequence.size() - 1);

    for (int i = 0; i < sequence.size() - 1; ++i) {
        upperSequence[i] = sequence[i] + sequence[i + 1];
    }

    return sumTriangle(upperSequence);
}
