#
# From: "Chains that bind us" by Phillip G. Bradford
#  https://github.com/wonder-phil/ChainsThatBindUs
#     
The functions here are standard and can be found in many places
# 

# GeometricSeriesSum
## This shows 4 interest payments (coupons) of 5 units
## the last interest payment is given at the same time as the principal is returned.
##

>> gss = GeometricSeriesSum(100)
>> arrayPayments = [5,5,5,5]
>> gss.one_rate_compute_factors(0.05, arrayPayments, 4)
>> print(gss)
GeometricSeriesSum
Starting principal: 100
Discount rates: [0.9523809523809523, 0.9070294784580498, 0.863837598531476, 0.8227024747918819]
Non-principal Payments: [5, 5, 5, 5]

>> gss.net_present_value_given_factors()
99.99999999999999
# compare:
5*0.9523809523809523 + 5*0.9070294784580498 + 5*0.863837598531476 + 105*0.8227024747918819
99.99999999999999
