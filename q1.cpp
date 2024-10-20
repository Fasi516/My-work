#include <iostream>
#include <cmath>

using namespace std;

// Class representing a single term in the polynomial
class Term {
public:
    int coeff;  // Coefficient of the term
    int expo;   // Exponent of the term
    Term* next; // Pointer to the next term

    Term(int c, int e) : coeff(c), expo(e), next(NULL) {}
};

// Class representing a polynomial using a linked list of terms
class Polynomial {
private:
    Term* head; // Pointer to the first term

public:
    Polynomial() : head(NULL) {}

    // Insert a term in the polynomial in descending order of exponents
    void addTerm(int coeff, int expo) {
        Term* newTerm = new Term(coeff, expo);
        if (!head || head->expo < expo) {
            newTerm->next = head;
            head = newTerm;
        } else {
            Term* current = head;
            while (current->next && current->next->expo >= expo) {
                current = current->next;
            }
            if (current->expo == expo) {
                current->coeff += coeff;
            } else {
                newTerm->next = current->next;
                current->next = newTerm;
            }
        }
    }

    // Add two polynomials and return the resulting polynomial
    Polynomial addPoly(const Polynomial& other) {
        Polynomial result;
        Term* t1 = head;
        Term* t2 = other.head;

        while (t1 || t2) {
            if (t1 && (!t2 || t1->expo > t2->expo)) {
                result.addTerm(t1->coeff, t1->expo);
                t1 = t1->next;
            } else if (t2 && (!t1 || t2->expo > t1->expo)) {
                result.addTerm(t2->coeff, t2->expo);
                t2 = t2->next;
            } else {
                result.addTerm(t1->coeff + t2->coeff, t1->expo);
                t1 = t1->next;
                t2 = t2->next;
            }
        }

        return result;
    }

    // Evaluate the polynomial at a specific value of x
    int evaluate(int x) {
        int result = 0;
        Term* current = head;
        while (current) {
            result += current->coeff * pow(x, current->expo);
            current = current->next;
        }
        return result;
    }

    // Display the polynomial in a readable format
    void print() {
        Term* current = head;
        while (current) {
            if (current->coeff > 0 && current != head) cout << "+";
            cout << current->coeff << "x^" << current->expo << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Polynomial poly1, poly2, polySum;

    // Adding terms to the first polynomial
    poly1.addTerm(3, 2);
    poly1.addTerm(5, 4);
    poly1.addTerm(-2, 0);
    cout << "First Polynomial: ";
    poly1.print();

    // Adding terms to the second polynomial
    poly2.addTerm(4, 4);
    poly2.addTerm(6, 0);
    cout << "Second Polynomial: ";
    poly2.print();

    // Adding the two polynomials
    polySum = poly1.addPoly(poly2);
    cout << "Sum of Polynomials: ";
    polySum.print();

    // Evaluating the resulting polynomial at x = 2
    int x = 2;
    cout << "Evaluation of the Sum at x = " << x << ": " << polySum.evaluate(x) << endl;

    return 0;
}

