#pragma once

class IntArray
{
public:
    IntArray() = default;
    IntArray(int length);
    IntArray(const IntArray& a);

    ~IntArray() { delete[] m_data; }
 
    void fill();
    void erase();
    void print();

    void find(int value);
    void resize(int newLength);    
    int getLength() const { return m_length; }   

    int& operator[](int index);
    IntArray& operator=(const IntArray& a);     
    
    void insertAtBeginning(int value) { insert(value, 1); }
    void insertAtEnd(int value);      
    void insert(int value, int index);
    void deleteAtBegin();
    void deleteAtEnd();
    void remove(int index);

    private:
    int m_length{};
    int* m_data{};

    void copyArray(int *data, const int *other_data, int other_lenght);
    void testLenght(const int lenght);
    void testPtr(const int *ptr);
};