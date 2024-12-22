/**
* Dylan Strnad
* string
* CS 23001
*/
// 
// Tests:  == operators, uses ==
//
//  
#include <iostream> 
#include <cassert>
#include "string.hpp"

//===========================================================================
int main(){
    ///////////////////////////
    // testing ==
{
    String str1("Hello, world!");
    String str2("Hello, world!");

    assert(str1 == str2);
}

{
    String str1("I made myself a peanut butter sandwich as I didn't want to subsist on veggie crackers. A purple pig and a green donkey flew a kite in the middle of the night and ended up sunburnt.");
    String str2("I made myself a peanut butter sandwich as I didn't want to subsist on veggie crackers. A purple pig and a green donkey flew a kite in the middle of the night and ended up sunburnt.");

    assert(str1 == str2);
}

//////////////
// testing !=

{
    String str1("I made myself a peanut butter sandwich as I didn't want to subsist on veggie crackers. A purple pig and a green donkey flew a kite in the middle of the night and ended up sunburnt.");
    String str2("I made myself a peanut butter sandwich as I didn't want to subsist on veggie crackers.");

    assert(str1 != str2);
}

{
    String str1("I made myself a peanut butter sandwich as I didn't want to subsist on veggie crackers. A purple pig and a green donkey flew a kite in the middle of the night and ended up sunburnt.");
    String str2("Hello");

    assert(str1 != str2);
}

{
    String str1(" ");
    String str2("Hello");

    assert(str1 != str2);
}

////////////////////////////
//comparing char array and strings

{

    String str2("I made myself a peanut butter sandwich as I didn't want to subsist on veggie crackers. A purple pig and a green donkey flew a kite in the middle of the night and ended up sunburnt.");
    char c[] = "I made myself a peanut butter sandwich as I didn't want to subsist on veggie crackers. A purple pig and a green donkey flew a kite in the middle of the night and ended up sunburnt.";
    assert(c == str2);
}

{

    String str2("Car safety systems have come a long way, but he was out to prove they could be outsmarted. The fox in the tophat whispered into the ear of the rabbit. The sign said there was road work ahead so he decided to speed up.");
    char c[] = "Car safety systems have come a long way, but he was out to prove they could be outsmarted. The fox in the tophat whispered into the ear of the rabbit. The sign said there was road work ahead so he decided to speed up.";
    assert(c == str2);
}

///////////////////////////
// comparing char and strings
{
    String str("H");
    char c = 'H';

    assert(c == str);
}

{
    String str("b");
    char c = 'b';

    assert(c == str);
}

{
    String str("l");
    char c = 'l';

    assert(c == str);
}

{
    String str("l");
    char c = 'r';

    assert(!(c == str));
}

 ////////////////////////////
    // <= operator
    {
        String lhs = "";
        String rhs = "";

        assert(lhs <= rhs);
    }
    
    {
        String lhs = "";
        String rhs = "Hello world!";

        assert(lhs <= rhs);
    }

    {
        String lhs = "Hello world!";
        String rhs = "";

        assert(!(lhs <= rhs));
    }

    {
        String lhs = "Hello world!";
        String rhs = "Hello world!";

        assert(lhs <= rhs);
    }

    {
        String lhs = "Hello";
        String rhs = "Hello world!";

        assert(lhs <= rhs);
    }

    {
        String lhs = "How was youre day today";
        String rhs = "How was youre day today, mine was great!";

        assert(lhs <= rhs);
    }

    {
        String lhs = "How was youre day today, mine was great!";
        String rhs = "How was youre day today";

        assert(!(lhs <= rhs));
    }

    {
        String lhs = "He excelled at firing people nicely. Everyone pretends to like wheat until you mention barley.";
        String rhs = "He excelled at firing people nicely. Everyone pretends to like wheat until you mention barley. He said he was not there yesterday; however, many people saw him there.";

        assert(lhs <= rhs);
    }

    {
        String lhs = "abcd";
        String rhs = "efgh";

        assert(lhs <= rhs);
    }

    {
        String lhs = "efgh";
        String rhs = "abcd";

        assert(!(lhs <= rhs));
    }

    {
        String lhs = "e";
        String rhs = "a";

        assert(!(lhs <= rhs));
    }
    {
        String lhs = "";
        String rhs = "a";

        assert(lhs <= rhs);
    }

    

    /////////////////////////////
    // >= operator

    {
        String lhs = "Hello world!";
        String rhs = "Hello world!";

        assert(lhs >= rhs);
    }

    {
        String lhs = "Hello world";
        String rhs = "Hello";

        assert(lhs >= rhs);
    }

    {
        String lhs = "How was youre day today, mine was great!";
        String rhs = "How was youre day today";

        assert(lhs >= rhs);
    }

    {
        String lhs = "He excelled at firing people nicely. Everyone pretends to like wheat until you mention barley. He said he was not there yesterday; however, many people saw him there.";
        String rhs = "He excelled at firing people nicely. Everyone pretends to like wheat until you mention barley.";

        assert(lhs >= rhs);
    }

    {
        String lhs = "Hello";
        String rhs = "Hello world";
    
        assert(!(lhs >= rhs));
    }

    {
        String lhs = "Hello world";
        String rhs = "Hello";

        assert(lhs >= rhs);
    }

    {
        String lhs = "efgh";
        String rhs = "abcd";

        assert(lhs >= rhs);
    }

    {
        String lhs = "abcd";
        String rhs = "efgh";

        assert(!(lhs >= rhs));
    }

    {
        String lhs = "e";
        String rhs = "a";

        assert(lhs >= rhs);
    }

    {
        String lhs = "";
        String rhs = "a";

        assert(!(lhs >= rhs));
    }

    {
        String lhs = "";
        String rhs = "";

        assert(lhs >= rhs);
    }
    
    {
        String lhs = "";
        String rhs = "Hello world!";

        assert(rhs >= lhs);
    }

    {
        String lhs = "Hello world!";
        String rhs = "";

        assert(lhs >= rhs);
    }



    std::cout << "done testing equal" << std::endl;




}