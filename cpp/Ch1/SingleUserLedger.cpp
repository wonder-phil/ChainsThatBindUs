#include <iostream>
#include <string>
#include <map>

using namespace std;

class SingleUserLedger {
private:
    int total_rows;
    string header[6];
    map<int, map<string, string>> rows;

public:
    SingleUserLedger() {
        total_rows = 0;
        header[0] = "NUMBER";
        header[1] = "DATE";
        header[2] = "ACCOUNT";
        header[3] = "INCOME";
        header[4] = "EXPENSE";
        header[5] = "DESCRIPTION";
    }

    void add_row(map<string, string> row_dict) {
        if (row_dict.empty()) {
            throw invalid_argument("row_dict must be a non-empty dictionary");
        }
        rows[total_rows] = row_dict;
        total_rows++;
    }

    map<string, string> return_new_row(string number, string date, string account, string income, string expense, string description) {
        map<string, string> my_row;
        my_row["NUMBER"] = number;
        my_row["DATE"] = date;
        my_row["ACCOUNT"] = account;
        my_row["INCOME"] = income;
        my_row["EXPENSE"] = expense;
        my_row["DESCRIPTION"] = description;
        return my_row;
    }

    string to_string() {
        string s = "Simple Single User Ledger\n";
        for (const string& h : header) {
            s += h + "            ";
        }
        s += "\n" + string(105, '-') + "\n";
        for (const auto& row : rows) {
            for (const auto& val : row.second) {
                string local_val = val.second;
                s += local_val + "            ";
            }
            s += "\n";
        }
        s += "\n";
        return s;
    }
};

int main() {
    SingleUserLedger ledger;
    map<string, string> row1 = ledger.return_new_row("1", "2021-01-01", "Account1", "100", "0", "Description1");
    map<string, string> row2 = ledger.return_new_row("2", "2021-01-02", "Account2", "0", "50", "Description2");
    ledger.add_row(row1);
    ledger.add_row(row2);
    cout << ledger.to_string();
    return 0;
}

