#pragma once
class SalaryCalc
{
private:
	int hours;
	int payPerHour;
public:
	void setHour(int h) {
		hours = h;
	}
	void setpayPerHour(int pph) {
		payPerHour = pph;
	}
	int getHour() {
		return hours;
	}
	int getpayPerHour() {
		return payPerHour;
	}
	int getCalcSal() {
		return hours * payPerHour;
	}
};

