#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class GreedyChange {
private:
    vector<int> denominations;
    vector<int> coinAmounts;
    int givenTotal;
public:
    GreedyChange(vector<int> denominations, int givenTotal) {
        sort(denominations.begin(), denominations.end(), greater<int>());
        this->denominations = denominations;
        this->coinAmounts = vector<int>(denominations.size(), 0);
        this->givenTotal = givenTotal;
    }
    void compute_change() {
        int total = givenTotal;
        int indexLargestRemaining = 0;
        while (total > 0) {
            coinAmounts[indexLargestRemaining] = total / denominations[indexLargestRemaining];
            total = givenTotal % denominations[indexLargestRemaining];
            indexLargestRemaining++;
        }
    }
    string toString() {
        string s = "Given total: " + to_string(givenTotal) + "\n";
        s += "Denominations: ";
        for (int i = 0; i < denominations.size(); i++) {
            s += to_string(denominations[i]) + " ";
        }
        s += "\n";
        s += "Numbers of coins using greedy\n";
        s += "-----------------------------\n";
        for (int i = 0; i < coinAmounts.size(); i++) {
            s += to_string(coinAmounts[i]) + " of " + to_string(denominations[i]) + "\n";
        }
        s += "\n";
        return s;
    }
};

int main() {
    vector<int> denominations = {1, 5, 10, 25};
    int givenTotal = 67;
    GreedyChange gc(denominations, givenTotal);
    gc.compute_change();
    cout << gc.toString();
    return 0;
}

