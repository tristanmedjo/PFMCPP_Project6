/*
 Project 6: Part 1 / 2
 Video: Chapter 3 Part 2

Create a branch named Part1

 Pointers

 Please look at the screenshot in the files to see what happens if you paste this assignment into an existing cpp file in an xcode project
 
 Task: replace all of the <place holder> with proper names and types that will make this program compile and run.
 
 steps:
 
 0) press the Compile, link and run... button and work your way through all of the error messages.
         you can click on them to be taken to the appropriate line number.
 
 1) finish implementing the constructor for T. the constructor parameters need to initialize 2) and 3)
 
 2) provide a member variable in T of a type of your choosing that works with the compare function below T
         note the name of the variable used in the compare function
 
 3) provide a member variable of type std::string in T that works with the *first* cout statement in main().
         note the name of the variable used in the *first* cout statement in main()
 
 4) finish defining the struct with the compare function
 5) provide proper types for the arguments to compare, and a proper return value
         be sure to make it work with the pointer semantics being used in the if statements.
         see 8) for a hint about what type to use.
 
 6) finish instantiating the two T instances being declared in main(), based on the constructor you finished implementing in T
     Their names (line 105,106) are different than the member variables names (line 77), even tho the placeholders share the same name.
     Don't let this confuse you.
 
 7) Declare 'f' with the proper type so the call to f.compare works
 
 8) call f.compare() with the correct arguments, based on 2) and 5)
 
 9) correct the cout that uses bigger's member variable with some safe pointer usage.
         the possible return values of the compare() function should give you a hint.
 
 10) complete the implementation for the static function in <structName2>
 
 11) call the <structName2> static function correctly in main()
 
 12) replicate the functionality of <structName2>'s static function by implementing a member function in U that does the same thing.
 
 13) remember the rules for using pointers!  What is the one thing we always do before we use a pointer?
 
 After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
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
    };  //1
    //2
    //3
};


struct myStruct                                //4
{

    T* compare(T* a, T* b) //5
    {
        if(a != nullptr && b != nullptr)
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
            return nullptr;
        }
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
            while( std::abs(this->floatTwo - this->floatOne > 0.001f ))
            {
                /*
                 write something that makes the distance between that->floatTwo and that->floatOne get smaller
                 */
                this->floatTwo -= 1;
            }
            std::cout << "U's floatTwo updated value: " << this->floatTwo << std::endl;
            return this->floatTwo * this->floatOne;
        }    
    }
};

struct myStruct2
{
    static float updateStaticValue(U* that, float newValue )        //10
    {
        if(that != nullptr)
        {
            std::cout << "U's floatOne value: " << that->floatOne << std::endl;
            that->floatOne = newValue;
            std::cout << "U's floatOne updated value: " << that->floatOne << std::endl;
            while( std::abs(that->floatTwo - that->floatOne > 0.001f ))
            {
                /*
                 write something that makes the distance between that->floatTwo and that->floatOne get smaller
                 */
                that->floatTwo -= 1;
            }
            std::cout << "U's floatTwo updated value: " << that->floatTwo << std::endl;
            return that->floatTwo * that->floatOne;
        }
    }
};
        
int main()
{
    T instanceOne(10, "charOne");                                             //6
    T instanceTwo(5, "charTwo");                                             //6
    
    myStruct f;                                            //7
    auto* smaller = f.compare(&instanceOne, &instanceTwo);                              //8
    std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    
    U newUVariableOne;
    float updatedValue = 5.f;
    std::cout << "[static func] newUVariableOne's multiplied values: " << myStruct2::updateStaticValue(&newUVariableOne, 100.5f ) << std::endl;                  //11
    
    U newUVariableTwo;
    std::cout << "[member func] newUVariableTwo's multiplied values: " << newUVariableTwo.updateValue(&updatedValue) << std::endl;
}

        
        
        
        
        
        
        
