/**
* Dylan Strnad
* string
* CS 23001
*/
// 
// Tests:  + snd += operators, uses ==
//
//  
#include <iostream> 
#include <cassert>
#include "string.hpp"

//===========================================================================
int main(){
///////////////////////////////
// operator +
    {
    String lhs = "Hello";
    std::cout << lhs << std::endl;
    String rhs = " world!";
    
    String result = lhs + rhs;

    assert(lhs == "Hello");
    assert(rhs == " world!");
    assert(result == "Hello world!");

   
    }

    {
    String lhs = "He ran out of money,";
    String rhs = " so he had to stop playing poker.";
    String result;

    result = lhs + rhs;

    assert(lhs == "He ran out of money,");
    assert(rhs == " so he had to stop playing poker.");
    assert(result == "He ran out of money, so he had to stop playing poker.");

   
    }

    {
    String lhs = "";
    String rhs = "So he had to stop playing poker.";
    String result;

    result = lhs + rhs;

    assert(lhs == "");
    assert(rhs == "So he had to stop playing poker.");
    assert(result == "So he had to stop playing poker.");

   
    }



    ///////////////////////////////////
    //operator +=

    {
    String lhs = "Hello";
    String rhs = " world!";

    assert(lhs == "Hello");
    assert(rhs == " world!");

    lhs += rhs;
    
    assert(lhs == "Hello world!");

   

    }

    {
    String lhs = "The family's excitement over going to Disneyland was crazier than she anticipated. My uncle's favorite pastime was building cars out of noodles.";
    String rhs = " She alway's speaks to him in a loud voice.";

    assert(lhs == "The family's excitement over going to Disneyland was crazier than she anticipated. My uncle's favorite pastime was building cars out of noodles.");
    assert(rhs == " She alway's speaks to him in a loud voice.");

    lhs += rhs;
    
    assert(lhs == "The family's excitement over going to Disneyland was crazier than she anticipated. My uncle's favorite pastime was building cars out of noodles. She alway's speaks to him in a loud voice.");

    

    }

    {
    String lhs = "";
    String rhs = "";

    assert(lhs == "");
    assert(rhs == "");

    lhs += rhs;
    assert(lhs == "");
    }

    {
    String lhs = "abcdefghi";
    String rhs = "jklmno";

    assert(lhs == "abcdefghi");
    assert(rhs == "jklmno");

    lhs += rhs;
    
    assert(lhs == "abcdefghijklmno");
    

    }


}



