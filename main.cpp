/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

#include <iostream>
#include <string>
struct T
{
    int value;
    std::string name;

    T(int v, const char* charPointer)
    {
        value = v;
        name = charPointer;
    }  //1
    //2
    //3
};


struct MyStruct                                //4
{

    T* compare(T* a, T* b) //5
    {
        if(a != nullptr && b != nullptr)
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
            return nullptr;
        }

        return nullptr;
    }
};

struct U
{
    float floatOne { 0 }, floatTwo { 10 };
    float updateValue(float* newValue)      //12
    {
        if(newValue != nullptr)
        {
            std::cout << "U's floatOne value: " << this->floatOne << std::endl;
            this->floatOne = *newValue;
            std::cout << "U's floatOne updated value: " << this->floatOne << std::endl;
            while( std::abs(this->floatTwo - this->floatOne) > 0.001f )
            {
                /*
                 write something that makes the distance between that->floatTwo and that->floatOne get smaller
                 */
                this->floatTwo -= 1;
            }
            std::cout << "U's floatTwo updated value: " << this->floatTwo << std::endl;
            return this->floatTwo * this->floatOne;
        }

        return 0;    
    }
};

struct MyStructTwo
{
    static float updateStaticValue(U* that, float* newValue )        //10
    {
        if(that != nullptr && newValue != nullptr)
        {
            std::cout << "U's floatOne value: " << that->floatOne << std::endl;
            that->floatOne = *newValue;
            std::cout << "U's floatOne updated value: " << that->floatOne << std::endl;
            while( std::abs(that->floatTwo - that->floatOne) > 0.001f )
            {
                /*
                 write something that makes the distance between that->floatTwo and that->floatOne get smaller
                 */
                that->floatTwo -= 1;
            }
            std::cout << "U's floatTwo updated value: " << that->floatTwo << std::endl;
            return that->floatTwo * that->floatOne;
        }

        return 0;
    }
};
        
int main()
{
    T instanceOne(10, "charOne");                                             //6
    T instanceTwo(5, "charTwo");                                             //6
    
    MyStruct f;                                            //7
    auto* smaller = f.compare(&instanceOne, &instanceTwo);                              //8
    std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    
    U newUVariableOne;
    float updatedValue = 5.f;
    std::cout << "[static func] newUVariableOne's multiplied values: " << MyStructTwo::updateStaticValue(&newUVariableOne, &updatedValue) << std::endl;                  //11
    
    U newUVariableTwo;
    std::cout << "[member func] newUVariableTwo's multiplied values: " << newUVariableTwo.updateValue(&updatedValue) << std::endl;
}

        
        
        
        
        
        
        
