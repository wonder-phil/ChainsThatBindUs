#include <iostream>
#include <vector>
#include <cmath>  

class GeometricSeriesSum {
private:
    double principal;
    std::vector<double> arrayPayments;
    std::vector<double> arrayDiscountRates;

public:
    GeometricSeriesSum(double principal, const std::vector<double>& arrayPayments = {}, const std::vector<double>& arrayDiscountRates = {})
        : principal(principal), arrayPayments(arrayPayments), arrayDiscountRates(arrayDiscountRates) {}

    double discount_factor(double rate, int time) {
        return std::pow(1.0 + rate, -time);
    }

    void one_rate_compute_factors(double rate, const std::vector<double>& arrayPayments, int total_payments = 0) {
        this->arrayPayments = arrayPayments;
        if (total_payments == 0) {
            total_payments = arrayPayments.size();
        }
        this->arrayDiscountRates.clear();
        for (int t = 1; t <= total_payments; ++t) {
            this->arrayDiscountRates.push_back(discount_factor(rate, t));
        }
    }

    double net_present_value_given_factors() {
        double sum_of_parts = 0.0;
        for (size_t i = 0; i < arrayPayments.size(); ++i) {
            sum_of_parts += arrayPayments[i] * arrayDiscountRates[i];
        }
        double last_rate = !arrayDiscountRates.empty() ? arrayDiscountRates.back() : 1.0;
        return sum_of_parts + principal * last_rate;
    }

    friend std::ostream& operator<<(std::ostream& os, const GeometricSeriesSum& series) {
        os << "GeometricSeriesSum\nStarting principal: " << series.principal << '\n';
        os << "Discount rates: [";
        for (size_t i = 0; i < series.arrayDiscountRates.size(); ++i) {
            os << series.arrayDiscountRates[i];
            if (i < series.arrayDiscountRates.size() - 1) os << ", ";
        }
        os << "]\nNon-principal Payments: [";
        for (size_t i = 0; i < series.arrayPayments.size(); ++i) {
            os << series.arrayPayments[i];
            if (i < series.arrayPayments.size() - 1) os << ", ";
        }
        os << "]";
        return os;
    }
};

int main() {
    double principal = 1000;
    std::vector<double> payments = {200, 200, 200};
    double rate = 0.07;

    GeometricSeriesSum series(principal);
    series.one_rate_compute_factors(rate, payments);
    double npv = series.net_present_value_given_factors();

    std::cout << series << std::endl;
    std::cout << "Net Present Value: " << npv << std::endl;

    return 0;
}
