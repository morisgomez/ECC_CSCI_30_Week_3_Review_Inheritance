#include <iostream>
using namespace std;
/*
Inheritance: a way to form new classes using classes that
 have already been defined.

The 3 Uses of Inheritance:
 1) Reuse->
 - We create a parent/base class with its corresponding member
 functions and member variables. Instead of creating another base
 class, we derive child classes from the parent class with the
 necessary changes. This reduces the need to rewrite same code or
 duplication.
 - For example: we have a human base class. We do not need to create
 a separate student class. We can reuse our base code and derive the
 student class bc a student is a type of human.
 
 2) Extension->
 - We derive a class from a base class but add new behaviors (member
 functions). These new behaviors are not present in the base class.

 3) Specialization->
 - Specialization is when we change an existing behavior (member functions) from the base class with a new behavior from the derived class. Derived upwards??
*/

//SUPER/BASE CLASS ANIMAL:
class Animal
{
private:
//- private member variables = cannot be accessed directly from
//derived classes or rest of program.
//- protected member variables = direct access from derived classes
//only & not rest of program.
//- public member variables = direct acces from derived classes &
//rest of program.
    int weight;
    int age;
    int moves;
    
public:
//- private member functions = cannot be accessed directly from
//derived classes or rest of program.
//- protected member functions = direct access from derived classes
//only & not rest of program.
//- public member functions = direct acces from derived classes &
//rest of program.
    //default constructor
    Animal()
    {
        weight = 0;
        age = 0;
        moves = 0;
    }
    //constructor:
    Animal(int w, int a)
    {
        weight = w;
        age = a;
        moves = 0;
    }
    //getKG function: returns weight in kilograms:
    int getKG()
    {
        return weight * 0.45359237;
    }
    //getAge function: returns age:
    int getAge()
    {
        return age;
    }
    //moveAnimal function: adds 1 movement to steps.
    void moveAnimal()
    {
        moves = moves + 1;
    }
    //getMoves function: gets total amount of movements.
    int getMoves()
    {
        return moves;
    }
    //makeNoise function:
    virtual void makeNoise()
    {
        cout << "arf arf arf" << endl;
    }
}; //close Animal base/parent class.

//DERIVED CLASS FELINE:
class Feline: public Animal
{
//variables & functions extended to Feline.
protected:
    int whiskers;
    int tail;
public:
    //default constructor:
    //no parameter constructor in derived class,
    //default constructor is fine.
    Feline()
    {
        whiskers = 0; //data extension.
        tail = 0; //data extension.
    }
    
    //constructor:
    //when derived class has constructor w/ parameters,
    //have to use the following syntax.
    Feline(int we, int ag, int w, int t):Animal(we, ag)
    //Feline(weight, age, whiskers, tail):Animal(weight, age)
    //Feline(base  , base, derived, derived):Animal(base, base)
    {
        whiskers = w;
        tail = t;
    }
    
    int getWhiskers() //method extension.
    {
        return whiskers;
    }
    int getTail() //method extension.
    {
        return tail;
    }
    //note on extensions:
    //only the derived class knows about them.
    //base class does not know about these extensions.
    //so you cannot call getWhiskers on a Animal object.
    //Specialization.overriding is a solution to this^^.
    
    //makeNoise function:
    virtual void makeNoise()
    {
        cout << "meow meow meow" << endl;
    }
}; //close Feline dervided/child class.

int main()
{
    //Extensions:
    Animal four(6, 20);
    //(weight lb, age);
    //-Animal does not have access to the extensions in Feline
    //such as whiskers() and tails().
    //four.makeNoise(); //"arf arf arf"
    
    Feline kitty(6, 20, 5, 1);
    //(weight lb, age, whiskers, tails);
    //-Feline = access to all of Animal's members + own extensions.
    
    //kitty.makeNoise(); //"arf arf arf"
    //bc kitty(from derived class) has access to all base functions.
    
    //Specialization/Overriding:
    //-We can override or specialize existing functions from base
    //class in our derived class.
    //-For example: I can replace the makeNoise() function in my
    //base class w/ a new version in my Feline derived class.
    //-How? "virtual" keyword before function declaration in
    //derived and base class.
    
    //-after overriding of makeNoise() function from base via
    //derived class:
    four.makeNoise(); //"arf arf arf"
    kitty.makeNoise(); //"meow meow meow"
    //hides the base version of the function.
    //the derived class will use the most derived version of that
    //specialized function.
    
    //-although the makeNoise() method has been redifined for the
    //Feline subclass to print "meow meow meow," we can still call
    //the base class version of the makeNoise() function on a
    //Feline object:
    kitty.Animal::makeNoise(); //"arf arf arf"
    
    
    cout << endl << "constructor(s): ------------" << endl;
    
    
    //Animal object via default constructor:
    Animal animalOne;
    cout << "animalOne via default:" << endl;
    cout << animalOne.getAge() << endl;
    cout << animalOne.getKG() << endl;
    animalOne.makeNoise();
    cout << "---------" << endl;
    
    //Animal object via parameter constructor:
    Animal animalTwo(6, 30);
    cout << "animalTwo via parameter:" << endl;
    cout << animalTwo.getAge() << endl;
    cout << animalTwo.getKG() << endl;
    animalTwo.makeNoise();
    cout << "---------" << endl;
    
    //Feline object via default constructor:
    Feline felineOne;
    cout << "felineOne via default:" << endl;
    cout << felineOne.getAge() << endl;
    cout << felineOne.getKG() << endl;
    felineOne.makeNoise();
    cout << "---------" << endl;
    
    //Feline object via parameter constructor:
    Feline felineTwo(3, 12, 6, 1);
    cout << "felineTwo via parameter:" << endl;
    cout << felineTwo.getAge() << endl;
    cout << felineTwo.getKG() << endl;
    felineTwo.makeNoise();
    return 0;
}
