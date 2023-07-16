#include "IntArray.h"
#include "IntArray_def.h"
#include "MyException.h"
#include <iostream>

IntArray::IntArray(int length) : m_length{length}
{
    try
    {   
        testLenght (length);        
        m_data = new int[length]{};
    }    
    catch (const std::bad_alloc &ex)
    {
        m_data = nullptr;
        std::cout << "Allocation failed: " << ex.what() << '\n';
    } 
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << '\n';
    }
}

IntArray::IntArray(const IntArray &other_array)
{
    try
    {      
        //this code was changed    
        //reallocate(a.getLength());       
        //for (int index{0}; index < m_length; ++index)
            //m_data[index] = a.m_data[index];

        testPtr (other_array.m_data);         
        m_data = new int[other_array.m_length];
        m_length = other_array.m_length;    
        copyArray(m_data, other_array.m_data, other_array.m_length);
    }
    catch (const std::bad_alloc &ex)
    {
        m_data = nullptr;
        std::cout << "Allocation failed: " << ex.what() << '\n';
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << '\n';
    }
}

//new function fill array
void IntArray::fill() 
{
    try
    {
        testPtr (m_data);
        for (int i = 0; i < this->getLength(); ++i)
        {
            m_data[i] = i + 1;
        }
    }
    catch (const std::exception &ex)
    {
        std::cout << ex.what() << '\n';
    }
}

//new function find
void IntArray::find(int value)
{
    try
    {
        testPtr (m_data);
        for (int i{0}; i < this->getLength(); ++i)
        {
            if (m_data[i] == value)
            {
                std::cout << "Found " << value << " at index " << i << '\n';
                return;
            }            
        }
        std::cout << "Did not find " << value << '\n';
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << '\n';
    }
}

//new function copyArray
void IntArray::copyArray(int *data, const int *other_data, int other_lenght)
{    
    try
    {
        testPtr (data);
        testPtr (other_data);
        testLenght (other_lenght);
        for (int index{0}; index < other_lenght; ++index)
            data[index] = other_data[index];
    }    
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << '\n';
    }
}

//new function print array
void IntArray::print()
{
    try
    {
        testPtr (m_data);        
        for (int i{0}; i < getLength(); ++i)
            std::cout << m_data[i] << ' ';
        std::cout << '\n';            
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << '\n';
    }
}

void IntArray::erase()
{
    try
    {
        testPtr (m_data);      
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << '\n';
    }
}

int &IntArray::operator[](int index)
{
    try
    {
        testPtr (m_data);

        if (index < 0 || index >= m_length)
        {
            throw std::out_of_range("IntArray index out of range");
        } 
        return m_data[index];      
    }
    catch (const std::out_of_range &ex)
    {
        std::cout << "Out of range: " << ex.what() << '\n';
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << '\n';
    }
}

void IntArray::resize(int newLength)
{
    if (newLength == m_length)
        return;    
    try
    {
        testPtr (m_data);
        testLenght (newLength);
        
        if (newLength == 0)
        {
            erase();
            return;
        }
        int* data{ new int[newLength] }; 
        //if (m_length > 0)
        //{
            int elementsToCopy{ (newLength < m_length) ? newLength : m_length };                     
            //for (int index{ 0 }; index < elementsToCopy; ++index)
                //data[index] = m_data[index];
        //}
        copyArray(data, this->m_data, elementsToCopy);
        delete[] m_data;
        m_data = data;
        m_length = newLength;
    }
    catch (const std::bad_alloc &ex)
    {
        std::cout << "Allocation failed: " << ex.what() << '\n';
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << '\n';
    }
}

IntArray &IntArray::operator=(const IntArray &other_array)
{
    if (&other_array == this)
        return *this;
    try
    {
        //This code was changed
        /*
        reallocate(a.getLength());
        for (int index{0}; index < m_length; ++index)
            m_data[index] = a.m_data[index];
        */
        testPtr (this->m_data);
        testPtr (other_array.m_data);
        
        delete[] m_data;
        m_data = new int[other_array.m_length]; 
        m_length = other_array.m_length;
        copyArray(m_data, other_array.m_data, m_length);
        return *this;
    }
    catch (const std::bad_alloc &ex)
    {
        std::cout << "Allocation failed: " << ex.what() << '\n';
    } 
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << '\n';
    }
}

void IntArray::insert(int value, int index)
{
    try
    {
        testPtr (this->m_data);
        
        if (index < 0 || index > m_length)
        {
            throw std::out_of_range("IntArray index out of range");
        }
        int *data{new int[m_length + 1]};

        //for (int before{0}; before < index; ++before)
            //data[before] = m_data[before];

        copyArray (data, m_data, index-1);

        data[index-1] = value;
        for (int after{index}; after < m_length+1; ++after)
            data[after] = m_data[after-1];

        delete[] m_data;
        m_data = data;
        ++m_length;
    }
    catch (const std::bad_alloc &ex)
    {
        std::cout << "Allocation failed: " << ex.what() << '\n';
    }
    catch (const std::out_of_range &ex)
    {
        std::cout << "Out of range: " << ex.what() << '\n';
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << '\n';
    }
}

//new fncthion
void IntArray::insertAtEnd(int value)
{
	try
	{
		testPtr(this->m_data);

		int* data{ new int[m_length + 1] };

		copyArray(data, m_data, this->m_length);
		data[this->m_length] = value;
		
		delete[] m_data;
		m_data = data;
		++m_length;
	}
	catch (const std::bad_alloc& ex)
	{
		std::cout << "Allocation failed: " << ex.what() << '\n';
	}
	catch (const std::out_of_range& ex)
	{
		std::cout << "Out of range: " << ex.what() << '\n';
	}
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << '\n';
    }
}

void IntArray::remove(int index)
{
    if (m_length == 1)
    {
        erase();
        return;
    }
    try
    {
        testPtr (this->m_data);
        
        if (index < 0 || index >= m_length)
        {
            throw std::out_of_range("IntArray index out of range");
        }        
        //for (int before{0}; before < index; ++before)
            //data[before] = m_data[before];

        int *data{new int[m_length - 1]};
        copyArray(data, m_data, index);
        for (int after{index + 1}; after < m_length; ++after)
            data[after - 1] = m_data[after];

        delete[] m_data;
        m_data = data;
        --m_length;
    }
    catch (const std::out_of_range &ex)
    {
        std::cout << "Out of range: " << ex.what() << '\n';
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << '\n';
    }
}

void IntArray::deleteAtBegin()
{
    if (m_length == 1)
    {
        erase();
        return;
    }
    try
    {
        testPtr(this->m_data);

        int* data{ new int[m_length - 1] };
        for (int index{0}; index < m_length -1; ++index)
            data[index] = m_data[index+1];

        delete[] m_data;
        m_data = data;
        --m_length;
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << '\n';
    }
}

void IntArray::deleteAtEnd()
{
    if (m_length == 1)
    {
        erase();
        return;
    }
    try
    {
        testPtr(this->m_data);
        int* data{ new int[m_length - 1] };        
        copyArray(data, m_data, m_length - 1);

        delete[] m_data;
        m_data = data;
        --m_length;
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << '\n';
    }
}

void IntArray::testLenght(const int lenght)
{
    if (lenght < 0)
        {
            throw MyException("IntArray length must be positive", ERROR_LENGTH_TOO_SMALL);            
        }
}

void IntArray::testPtr(const int *ptr)
{
    if (ptr == nullptr)
    {
        throw MyException("IntArray called on nullptr", ERROR_NULLPTR);
    }
}