#include <iomanip>
#include <iostream>

using namespace std;

class MeterCM {
private:
	int m_meter;
	int m_cm;
	void simplify();
	void convert();
public:
    MeterCM(int meter = 0, int cm = 0) : m_meter(meter), m_cm(cm) {
	    simplify();
    }
    int getMeter() const;
	int getCM() const;
	void setData(int meter, int cm);
    
    MeterCM operator + (const MeterCM &rMCM) const;
    MeterCM operator - (MeterCM &rMCM);
    MeterCM operator * (MeterCM &rMCM);
    int operator / (MeterCM &rMCM);
    MeterCM operator % (MeterCM &rMCM);
    void operator += (const MeterCM &rMCM);
	void operator -= (MeterCM &rMCM);
	void operator *= (MeterCM &rMCM);
	void operator /= (MeterCM &rMCM);
	void operator %= (MeterCM &rMCM);
	MeterCM operator ++ ();
	MeterCM operator ++ (int);
	MeterCM operator -- ();
	MeterCM operator -- (int);
	bool operator < (const MeterCM &rMCM) const;
	bool operator <= (const MeterCM &rMCM) const;
	bool operator > (const MeterCM &rMCM) const;
	bool operator >= (const MeterCM &rMCM) const;
	bool operator == (MeterCM &rMCM);
	bool operator != (MeterCM &rMCM);
	friend ostream& operator << (ostream &strm, MeterCM &dis);
	friend istream& operator >> (istream &strm, MeterCM &dis);
};
 
int main(void)
{
    int dividend;
	MeterCM mcm1, mcm2, mcm3;
	MeterCM d1;
	MeterCM d2(1, 95);

	mcm1.setData(4, 125);
	mcm2.setData(1, 104);

	cout << "mcm1: " << mcm1;
	cout << "mcm2: " << mcm2;
	cout << "mcm3: " << mcm3;

	mcm3 = mcm1 + mcm2;
	cout << "mcm3 = mcm1 + mcm2: " << mcm3;

	mcm3 = mcm1 - mcm2;
	cout << "mcm3 = mcm1 - mcm2: " << mcm3;

	mcm3 = mcm1 * mcm2;
	cout << "mcm3 = mcm1 * mcm2: " << mcm3;

	dividend = mcm1 / mcm2;
	cout << "mcm1 / mcm2 = " << dividend << endl;

	mcm3 = mcm1 % mcm2;
	cout << "mcm3 = mcm1 % mcm2: " << mcm3;
	
	mcm3 += mcm1;
	cout << "mcm3 += mcm1: " << mcm3;
	
    mcm3 -= mcm1;
	cout << "mcm3 -= mcm1: " << mcm3;
	
	mcm3 *= mcm1;
	cout << "mcm3 *= mcm1: " << mcm3;
	
	mcm3 /= mcm1;
	cout << "mcm3 /= mcm1: " << mcm3;
	
	mcm3 %= mcm1;
	cout << "mcm3 %= mcm1: " << mcm3;

	/*for (int i = 0; i < 10; i++) {
		d1 = ++d2;
		d1 = d2++;
		cout << "d1: " << d1;
		cout << "d2: " << d2;
	}*/

	for (int i = 0; i < 10; i++) {
		d1 = d2++;
		cout << "d1: " << d1;
		cout << "d2: " << d2;
	}

	if (d1 < d2) {
		cout << "d1 < d2" << endl;
	}
	else {
		cout << "d1 > d2" << endl;
	}
	if (d1 <= d2) {
		cout << "d1 <= d2" << endl;
	}
	else if (d1 >= d2) {
		cout << "d1 >= d2" << endl;
	}
	if (d1 == d2) {
		cout << "d1 == d2" << endl;
	}
	else {
		cout << "d1 != d2" << endl;
	}

	//system("pause");
	return 0;
}

// simplifies measurements
void MeterCM::simplify() {
	m_cm = m_cm + m_meter * 100;
	m_meter = m_cm / 100;		
	//m_meter = m_meter + (m_cm / 100);
	m_cm = m_cm % 100;
}
// converts to cm only, for purposes of division
void MeterCM::convert() {
    m_cm = m_cm + m_meter * 100;
    m_meter = 0;
}

// returns meters
int MeterCM::getMeter() const { return m_meter; }

// returns cm
int MeterCM::getCM() const { return m_cm; }

// sets data
void MeterCM::setData(int meter, int cm) {
	m_meter = meter;
	m_cm = cm;
	simplify();
}

// overload addition (+)
MeterCM MeterCM::operator + (const MeterCM &rMCM) const {
	MeterCM temp;
	temp.m_cm = m_cm + rMCM.m_cm;
	temp.m_meter = m_meter + rMCM.m_meter;
	temp.simplify();
	return temp;
}

// overload subtraction (-)
MeterCM MeterCM::operator - (MeterCM &rMCM) {
	MeterCM temp;
	convert();
	rMCM.convert();
	temp.m_cm = m_cm - rMCM.m_cm;
	simplify();
	rMCM.simplify();
	temp.simplify();
	return temp;
}

// overload multiplication (*)
MeterCM MeterCM::operator * (MeterCM &rMCM) {
	MeterCM temp;
	convert();
	rMCM.convert();
	temp.m_cm = m_cm * rMCM.m_cm;
	simplify();
	rMCM.simplify();
	temp.simplify();
	return temp;
}

// overload division (/) returns integer
int MeterCM::operator / (MeterCM &rMCM) {
	int dividend;
	convert();              
	rMCM.convert();
	if (rMCM.m_cm == 0) {
	    cout << "Error, division by zero, returning 0." << endl;
	    return 0;
	}
	dividend = m_cm / rMCM.m_cm;
	simplify();
	rMCM.simplify();
	return dividend;
}

// overload modulus (%) 
MeterCM MeterCM::operator % (MeterCM &rMCM) {
	MeterCM temp;
	convert();
	rMCM.convert();
	temp.m_cm = m_cm % rMCM.m_cm;
	temp.simplify();
	rMCM.simplify();
	return temp;
}

// overload pre-increment (++)
MeterCM MeterCM::operator ++ () {
	++m_cm;
	simplify();
	return *this;
}

// overload post-increment (++)
MeterCM MeterCM::operator ++ (int) {
	MeterCM temp(m_meter, m_cm);
	m_cm++;
	simplify();
	return temp;
}

// overload pre-decrement (--)
MeterCM MeterCM::operator -- () {
	--m_cm;
	simplify();
	return *this;
}

// overload post-decrement (--)
MeterCM MeterCM::operator -- (int) {
	MeterCM temp(m_meter, m_cm);
	m_cm--;
	simplify();
	return temp;
}

// overload plus equals (+=)
void MeterCM::operator += (const MeterCM &rMCM) {
    m_meter = m_meter + rMCM.m_meter;
    m_cm = m_cm + rMCM.m_cm;
    simplify(); 
}

// overload plus equals (-=)
void MeterCM::operator -= (MeterCM &rMCM) {
    convert();
    rMCM.convert();
    m_cm = m_cm - rMCM.m_cm;
    simplify();
    rMCM.simplify(); 
}
// overload plus equals (*=)
void MeterCM::operator *= (MeterCM &rMCM) {
    convert();
    rMCM.convert();
    m_cm = m_cm * rMCM.m_cm;
    simplify();
    rMCM.simplify(); 
}

// overload plus equals (/=)
void MeterCM::operator /= (MeterCM &rMCM) {
    convert();
    rMCM.convert();
    m_cm = m_cm / rMCM.m_cm;
    simplify();
    rMCM.simplify();
}

// overload plus equals (%=)
void MeterCM::operator %= (MeterCM &rMCM) {
    convert();
    rMCM.convert();
    m_cm = m_cm % rMCM.m_cm;
    simplify();
    rMCM.simplify(); 
}

// overload less than (<)
bool MeterCM::operator < (const MeterCM &rMCM) const {
	if (m_meter < rMCM.m_meter) {
		return true;
	}
	else if ((m_meter == rMCM.m_meter) && (m_cm < rMCM.m_cm)) {
		return true;
	}
	else {
		return false;
	}
}

// overload less than or equal to (<=)
bool MeterCM::operator <= (const MeterCM &rMCM) const {
    if (m_meter < rMCM.m_meter) {
		return true;
	}
	else if ((m_meter == rMCM.m_meter) && (m_cm <= rMCM.m_cm)) {
		return true;
	}
	else {
		return false;
	}
}
	
// overload greater than (>)
bool MeterCM::operator > (const MeterCM &rMCM) const {
	return (rMCM < *this);
}

// overload greater than or equal to (>=)
bool MeterCM::operator >= (const MeterCM &rMCM) const {
	return (rMCM <= *this);
}

// overload equality (==)
bool MeterCM::operator == ( MeterCM &rMCM) {
    simplify();
    rMCM.simplify();
	return ((m_meter == rMCM.m_meter) && (m_cm == rMCM.m_cm));
}

// overload inequality (!=)
bool MeterCM::operator != ( MeterCM &rMCM) {
    simplify();
    rMCM.simplify();
	return ((m_meter != rMCM.m_meter) || (m_cm != rMCM.m_cm));
}

// overload stream insertion (<<) 
ostream& operator << (ostream &strm, MeterCM &dis) {
	strm << "Measurements: " << setw(6) << dis.m_meter << " M " 
	     << setw(6) << dis.m_cm << " Cm" << endl;
	return strm;
}

// overload stream extraction (>>) 
istream& operator >> (istream &strm, MeterCM &dis) {
	strm >> dis.m_meter >> dis.m_cm;
	return strm;
}
