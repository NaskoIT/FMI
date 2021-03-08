/**
*  
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Atanas Vasilev
* @idnumber 62577
* @task 2
* @compiler GCC
*
*/

#include <iostream>
#include <vector>
using namespace std;

vector<double> readSequence(int length);
double calulcateMaxProfit(vector<double> collection);
void runUnitTests();

const int SEQUENCE_MIN_LENGTH = 3;
const int SEQUENCE_MAX_LENGTH = 365;
const int ZERO_DOUBLE = 0.0;
const double STOCK_MIN_PRICE = 0.1;
const double STOCK_MAX_PRICE = 100;

int main()
{
    int length;
    do
    {
        cin >> length;
    } while (length < SEQUENCE_MIN_LENGTH || length > SEQUENCE_MAX_LENGTH);

    vector<double> sequence = readSequence(length);
    cout << calulcateMaxProfit(sequence);
}

vector<double> readSequence(int length)
{
    vector<double> array(length);
    for (int i = 0; i < length; i++)
    {
        double price;
        cin >> price;
        if (price < STOCK_MIN_PRICE || price > STOCK_MAX_PRICE)
        {
            i--;
        }
        else
        {
            array[i] = price;
        }
    }

    return array;
}

double calulcateMaxProfit(vector<double> collection)
{
    int size = collection.size();
    double profit = ZERO_DOUBLE;
    double stockPrice = ZERO_DOUBLE;
    for (int i = 0; i < size; i++)
    {
        double nextStock = i == size - 1 ? ZERO_DOUBLE : collection[i + 1];
        double currentStock = collection[i];
        if (stockPrice > 0 && currentStock > nextStock)
        {
            // sell stock
            profit += currentStock - stockPrice;
            stockPrice = ZERO_DOUBLE;
        }
        else if (stockPrice == ZERO_DOUBLE && currentStock < nextStock)
        {
            // buy new stock
            stockPrice = currentStock;
        }
    }

    return profit;
}

void runUnitTests()
{
    vector<vector<double>> inputs = {
        {1, 2, 3, 4, 3, 2, 1, 5},
        {15, 14.5, 10, 7.45, 5},
        {100, 1, 5, 3, 103, 104, 100},
        {1, 15, 20, 58, 59, 60},
        {15, 15, 15, 15, 15},
        {10.1, 10.0, 5.0, 0.1, 100.1, 55, 54, 55.5, 20, 10.1, 0.1},
        {2, 1, 3, 4, 7, 5, 2, 8}};

    vector<double> expectedOutputs = {7, 0, 105, 59, 0, 101.5, 12};

    for (int i = 0; i < inputs.size(); i++)
    {
        // Arrange
        vector<double> input = inputs[i];
        int expectedOutput = expectedOutputs[i];

        // Act
        int actualOutput = calulcateMaxProfit(input);

        // Assert
        if (actualOutput == expectedOutput)
        {
            cout << "Test #" << i + 1 << " passed" << endl;
        }
        else
        {
            cout << "Test #" << i + 1 << " failed" << endl;
            cout << "\t Expected output: " << expectedOutput << endl;
            cout << "\t Actual output: " << actualOutput << endl;
        }
    }
}