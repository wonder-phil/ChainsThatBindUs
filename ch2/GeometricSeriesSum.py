#
#
# From: "Chains that bind us" by Phillip G. Bradford
#  https://github.com/wonder-phil/ChainsThatBindUs
#   
#
class GeometricSeriesSum:

    #  arrayDiscountRates is out of 1:
    #     so an array element 7% rate is 0.07
    #
    def __init__(self, principal, arrayPayments = [], arrayDiscountRates = []):
        self.principal = principal
        self.arrayPayments = arrayPayments
        self.arrayDiscountRates = arrayDiscountRates
    
    #
    # rate is out of 1.  So a rate of 7% is 0.07
    #
    def discount_factor(self,rate,time):
        return (1.0 + rate)**(-time)

    #
    def one_rate_compute_factors(self, rate, arrayPayments, total_payments):
        self.arrayPayments = arrayPayments
        for t in range(1,total_payments+1):
            discount = (1.0 + rate)**(-t)
            self.arrayDiscountRates.append(discount)

    def net_present_value_given_factors(self):
        sum_of_parts = 0.0
        last_rate = 0.0
        for payment, rate in zip(self.arrayPayments,self.arrayDiscountRates):
            sum_of_parts = sum_of_parts + payment*rate
            last_rate = rate
        return sum_of_parts + self.principal *last_rate
        
    def __str__(self):
        s = 'GeometricSeriesSum' + '\n'
        s = s + "Starting principal: "      + str(self.principal) + '\n'
        s = s + "Discount rates: "          +  str(self.arrayDiscountRates) + '\n'
        s = s + "Non-principal Payments: "  +  str(self.arrayPayments) + '\n'
        
        return s
