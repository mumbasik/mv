#include <iostream>
using namespace std;

class MyString {
    char* st;
    static int amount;
    int size;

public:
    MyString() {
        st = new char[80]();
        amount++;
    }

    MyString(int size) {
        this->size = size;
        st = new char[this->size + 1];
        amount++;
    }

    void String(const char* ad) {

        st = new char[strlen(ad) + 1];
        strcpy_s(st, strlen(ad) + 1, ad);
    }
    MyString(const MyString& obj) {
        st = new char[strlen(obj.st) + 1];
        strcpy_s(st, strlen(obj.st) + 1, obj.st);
    }



    static int GetAmount() {
        return amount;
    }

    void Prin() const {
        cout << "String: " << st << endl;
        cout << "Amount: " << amount << endl;
    }
    MyString(MyString&& obj) {

        st = obj.st;
        obj.st = nullptr;
        size = obj.size;
        obj.size = NULL;
        amount++;
    }
    ~MyString() {
        delete[] st;
        amount--;
    }

    friend MyString operator+(int x, const MyString& obj);
};
MyString operator+(int x, const MyString& obj) {
    MyString result(obj);
    char* temp = new char[x + 1];
    for (int i = 0; i < x; i++) {
        temp[i] = 'x';
    }
    temp[x] = '\0';
    char* last = new char[strlen(obj.st) + x + 1];
    strcpy_s(last, strlen(obj.st) + x + 1, temp);
    strcat_s(last, strlen(obj.st) + x + 1, obj.st);
    delete[] temp;
    result.st = last;
    return result;

}
int MyString::amount = 0;
MyString Func() {
    MyString H;
    H.String("Andrey");
    return H;
}
void main() {

    MyString q;
    MyString q2(100);
    MyString q3 = Func();
    /*q3.String("Andrey");

    q3.GetAmount();

    q3.Prin();
    MyString b = q3;
    b.Prin();
    MyString sum = 4 + q3;
    sum.Prin();*/
    q3.Prin();

}
