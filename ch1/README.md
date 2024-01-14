# *Chains that bind us*<br>  

> From: "Chains that bind us" by Phillip G. Bradford <br>  
>>  https://www.amazon.com/Chains-that-bind-Phillip-Bradford/dp/1917007884 <br>  
> Copyright (&copy;) 2023-2024 Phillip G. Bradford <br>

The functions here are standard and can be found in many places <br>

## SingleUserLedger Design

Each instance of the SingleUserLedger class has the following attributes

1. The variable ledger is a Python dictionary. The keys of this dictionary are the integers 1, 2, ...
   The values of this dictionary is the columns dictionary.
   
2. The columns dictionary has keys of the column names 
	DATE, ACCOUNT, INCOME, EXPENSE, DESCRIPTION


3. Building a single user ledger 

>> sul = SingleUserLedger()
>> row = sul.return_new_row("1","2023-05-19","CAFEBABE","20.23","19.95","Coffee")
>> sul.add_row(row)
>> row = sul.return_new_row("2","2023-09-09","C",	"19.84", "19.70",   "Vitamin")
>> sul.add_row(row)
>> row = sul.return_new_row("3","2024-04-17","FED","33.76","105.99",   "Street")
>> sul.add_row(row)
>> row = sul.return_new_row("4","2023-07-01","64","20.08","19.94","Belts")
>> sul.add_row(row)
>> row = sul.return_new_row("5","2023-06-14","03BB","19.75","19.58","Lists of lists")
>> sul.add_row(row)
>> row = sul.return_new_row("6","2023-12-30","C23","21.50","19.84","Multi Vitamin")
>> sul.add_row(row)
>> print(sul)

Simple Single User Ledger
#           DATE        ACCOUNT     INCOME      EXPENSE     DESCRIPTION 
------------------------------------------------------------------------
1           2023-05-19  CAFEBABE    20.23       19.95       Coffee      
2           2023-09-09  C           19.84       19.70       Vitamin     
3           2024-04-17  FED         33.76       105.99      Street      
4           2023-07-01  64          20.08       19.94       Belts       
5           2023-06-14  03BB        19.75       19.58       Lists of lists
6           2023-12-30  C23         21.50       19.84       Multi Vitamin


# GreedyChange

## pip3 install numpy

The example greedy change generator can be run as


>> gc = GreedyChange([1,5,25], 105)
>> gc.compute_change()
>> print(gc)

Given total: 105
Denominations: [25  5  1]
Numbers of coins using greedy
-----------------------------
4 of 25
1 of 5
0 of 1



