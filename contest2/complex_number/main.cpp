#include <iostream>
#include <math.h>

class Complex{
    public:
        explicit Complex(double real, double image)
            : real_(real), image_(image) {
        }

        explicit Complex(int i)
                : real_(i),
                  image_(0) {
        }

        explicit Complex(double d)
                : real_(d),
                  image_(0) {
        }

    Complex(const Complex & rhs) {
            real_ = rhs.real_;
            image_ = rhs.image_;
        }

    Complex& operator=(const Complex& rhs) = default;
    bool operator==(const Complex& rhs) const {
        if (real_ == rhs.real_ && image_ == rhs.image_) {
            return true;
        }
        else {
            return false;
        }
    }

     bool operator!=(Complex& rhs) const {
        if (real_ != rhs.real_ || image_ != rhs.image_) {
            return true;
        } else {
            return false;
        }
    }

    Complex& operator+=(const Complex& rhs) {
        real_ += rhs.real_;
        image_ += rhs.image_;
        return *this;
    }

    Complex& operator-=(const Complex& rhs) {
        real_ -= rhs.real_;
        image_ -= rhs.image_;
        return *this;
    }

    Complex operator+() const{
        return *this;
    }
    Complex operator-() const {
       return Complex(-this->real_, -this->image_);
    }

    Complex& operator+=(const double rhs) {
        real_ += rhs;
        return *this;
    }

    Complex& operator-=(const double rhs) {
        real_ -= rhs;
        return *this;
    }

    double Re() const {
        return real_;
    }

    double Im() const {
        return image_;
    }

    friend Complex operator+(const Complex& lhs, const Complex& rhs);
    friend Complex operator-(const Complex& lhs, const Complex& rhs);
    friend Complex operator+(double lhs, const Complex& rhs);
    friend Complex operator-(double lhs, const Complex& rhs);

    double real_;
    double image_;
};
std::ostream& operator<<(std::ostream& os, const Complex & c)
{
    os << "Re=" << c.real_ << ", Im=" << c.image_;
    return os;
}
Complex operator*(const Complex& lhs, const Complex& rhs) {
    Complex answer = Complex(
            (lhs.real_ * rhs.real_ - lhs.image_ * rhs.image_), (lhs.real_ * rhs.image_ + lhs.image_ * rhs.real_));
    return answer;
}

Complex operator*(const double lhs, const Complex& rhs) {
    Complex answer = Complex(
            (lhs * rhs.real_), (lhs * rhs.image_));
    return answer;
}

Complex operator*(const Complex& lhs, const double rhs) {
    Complex answer = Complex(
            (rhs * lhs.real_), (rhs * lhs.image_));
    return answer;
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
    double abs = (rhs.real_ * rhs.real_ + rhs.image_ * rhs.image_);
    Complex answer = Complex(
            ((lhs.real_ * rhs.real_ + lhs.image_ * rhs.image_) / abs),
            ((-lhs.real_ * rhs.image_ + lhs.image_ * rhs.real_) / abs));
    return answer;
}
Complex operator/(const Complex& lhs, const double rhs) {
    Complex answer = Complex(
            ((lhs.real_)/rhs), ((lhs.image_)/rhs));
    return answer;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
    Complex answer(lhs);
    answer += rhs;
    return answer;
}
Complex operator-(const Complex& lhs, const Complex& rhs) {
    Complex answer(lhs);
    answer -= rhs;
    return answer;
}

Complex operator+(const double lhs, const Complex& rhs) {
    Complex answer(rhs);
    answer += lhs;
    return answer;
}


Complex operator-(const double lhs, const Complex& rhs) {
    Complex answer(rhs);
    answer -= lhs;
    return answer;
}

Complex operator+(const Complex& lhs, const double rhs) {
    Complex answer(lhs);
    answer += rhs;
    return answer;
}
Complex operator-(const Complex& lhs, const double rhs) {
    Complex answer(lhs);
    answer -= rhs;
    return answer;
}
double Abs(const Complex& complex) {
    double image_ = complex.image_;
    double real_ = complex.real_;
    double abs = sqrt(real_ * real_ + image_ * image_);
    return abs;
}

int main() {
    int c = 3;

    Complex c1 = Complex(1.0, 2.0);
    Complex c2 = Complex(1);
    Complex c4 = Complex(0.0);
    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
    Complex c3 = c1 / c2;
    std::cout << c1  << std::endl;
    std::cout << +c4 << std::endl;
    std::cout << 2*c1 + 3* c1 << std::endl;

    return 0;
}
