#include <iostream>
#include <numeric>

class Rational {
private:
    int num;
    int denom;

    void Normalize() {
        int div = std::gcd(num, denom);
        num /= div;
        denom /= div;
        if (denom < 0) {
            num *= -1;
            denom *= -1;
        }
    }
public:
    Rational(int num_ = 0, int denom_ = 1) : num(num_), denom(denom_) {
        Normalize();
    }

    int Numerator() const {
        return num;
    }

    int Denominator() const {
        return denom;
    }

    Rational operator + () const {
        return { num, denom };
    }

    Rational operator - () const {
        return Rational(-num, denom);
    }

    Rational& operator += (const Rational& rhs) {
        num = num * rhs.denom + rhs.num * denom;
        denom *= rhs.denom;
        Normalize();
        return *this;
    }

    Rational& operator -= (const Rational& rhs) {
        num = num * rhs.denom - rhs.num * denom;
        denom *= rhs.denom;
        Normalize();
        return *this;
    }

    Rational& operator *= (const Rational& rhs) {
        num *= rhs.num;
        denom *= rhs.denom;
        Normalize();
        return *this;
    }

    Rational& operator /= (const Rational& rhs) {
        num *= rhs.denom;
        denom *= rhs.num;
        Normalize();
        return *this;
    }

    bool operator == (const Rational& rhs) {
        return num == rhs.num && denom == rhs.denom;
    }

    bool operator != (const Rational& rhs) {
        return !(*this == rhs);
    }
};

Rational operator + (const Rational& lhs, const Rational& rhs) {
    Rational result = lhs;
    result += rhs;
    return result;
}

Rational operator - (const Rational& lhs, const Rational& rhs) {
    Rational result = lhs;
    result -= rhs;
    return result;
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
    Rational result = lhs;
    result *= rhs;
    return result;
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
    Rational result = lhs;
    result /= rhs;
    return result;
}

std::ostream& operator << (std::ostream& out, const Rational& n) {
    out << n.Numerator() << "/" << n.Denominator();
    return out;
}

int main() {
    std::cout << 1 + Rational(1, 2);
}