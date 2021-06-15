#include <iostream>
#include "1/Error.hpp"
#include "1/Result.hpp"
#include "3/Vector4D.hpp"
#include "2/ElectionResultsDatabase.hpp"

using namespace std;

void testVector() {
    int a = 10;
    int b = 15;
    int c = 25;
    int d = 30;
    Vector4D v = Vector4D(a, b, c, d);
    cout << (v[0] == a) << endl;
    cout << (v[1] == b) << endl;
    cout << (v[2] == c) << endl;
    cout << (v[3] == d) << endl;

    // Мутирането също трябва да е възможно:
    double x = 10;
    v[0] = x; // вече v е наредената четворка (x, b, c, d)

    cout << v[0] << endl;

    bool result = -Vector4D(1, 2, 3, 4) == Vector4D(-1, -2, -3, -4);
    cout <<  "-v operator: " << result;
}

void testErrorHandling() {
    bool a = Result<int>(3) == int(); // -> true
    bool b = Result<int>(5) == Error(); // -> false
    bool c = Result<int>("Error Message") == Error(); // -> true

    cout << a << " " << b << " " << c << endl;
}

void testElection() {
    char filename[] = "election.txt";
    ElectionResultsDatabase database;
    database.addResultsFromFile(filename);
    cout << database.votesForParty(PARTY1) << endl;
    cout << database.votesForParty(PARTY2) << endl;
    cout << database.votesForParty(PARTY3) << endl;
    cout << database.numberOfSections() << endl;
    cout << database.winningParty() << endl;
}

int main() {
    testErrorHandling();
    testElection();
    testVector();
}
