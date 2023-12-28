#
#
# From: "Chains that bind us" by Phillip G. Bradford
#  https://github.com/wonder-phil/ChainsThatBindUs
#     

class SingleUserLedger:

    def __init__(self):
        self.total_rows = 0
        self.header = ["#", "DATE", "ACCOUNT", "INCOME", "EXPENSE", "DESCRIPTION"]
        self.rows = {}

    def add_row(self, row_dict):
        if type(row_dict) != dict:
             raise Exception("row_dict must be a dictionary")
        self.rows[self.total_rows] = row_dict
        self.total_rows = self.total_rows + 1

    def return_new_row(self,number,date,account,income,expense,description):
        my_row = {}
        my_row["#"] = number
        my_row["DATE"] = date
        my_row["ACCOUNT"] = account
        my_row["INCOME"] = income
        my_row["EXPENSE"] = expense
        my_row["DESCRIPTION"] = description

        return my_row

    def __str__(self):
        s = 'Simple Single User Ledger' + '\n'
        for h in self.header:
            s = s + '{:12s}'.format(h)
        s = s + "\n" + 72*"-" + '\n'
        for row in self.rows.values():
            for val in row.values():
                local_val = str(val)
                s = s + '{:12s}'.format(local_val)
            s = s + '\n'
        s = s + '\n'
        
        return s
