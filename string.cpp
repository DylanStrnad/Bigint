
#include "string.hpp"
#include <iostream>
#include <cassert>
#include <vector>

String::String(){
    stringSize = 1;
    str = new char[stringSize];
    str[0] = '\0';
}

String::String(char ch){
    stringSize = 1;
    if(ch == '\0'){
        str = new char[stringSize];
        str[0] = '\0';
    }  else {
        ++stringSize;
        str = new char[stringSize];
        str[0] = ch;
        str[1] = '\0';
        }

}

String::String(const char ch[]){

    stringSize = 1;
    int index = 0;
    while(ch[index] != '\0'){
        ++index;
        ++stringSize;
    }

    str = new char[stringSize]; //////
    index = 0;
    while(ch[index] != '\0'){
        str[index] = ch[index];
        ++index;
    }

    str[index] = '\0';
}

String::String(const String& rhs){
    stringSize = rhs.stringSize;
    str = new char[stringSize + 1];
    int i = 0;
    while(i < stringSize){
        str[i] = rhs.str[i];
        ++i;
    }
    str[i] = '\0';
}

int String::length() const{
    int len = 0;
    while(str[len] != '\0'){
        ++len;
    }

    return len;
}

int String::capacity() const{
    int cap = 0;
    while(str[cap] != '\0'){
        ++cap;
    }

    return cap;
}

char& String::operator[](int n){
    return str[n];
}

char String::operator[](int n) const{ //
    assert(n >= 0 && n < length());
    return str[n];

}

String::~String(){
    delete[] str;
}

void String::swap(String& rhs){
    int tempSize = stringSize;
    stringSize = rhs.stringSize;
    rhs.stringSize = tempSize;

    char* tempStr = str;
    str = rhs.str;
    rhs.str = tempStr;
}


String& String::operator=(String rhs){
    swap(rhs);
    return *this;
}

String& String::operator+= (const String& rhs){
    int len = length();
    int rhsLen = rhs.length();
    int totalLen = len + rhsLen;

    char* result = new char[totalLen + 1];
    for(int i = 0; i < len ; ++i){
        result[i] = str[i];
    }

    for (int j = 0; j < rhsLen; ++j) {
        result[len + j] = rhs.str[j];
    }

    result[totalLen] = '\0';
    delete[] str;
    str = result; // result is stored
    stringSize = totalLen + 1; //updates the stringSize  //COULD BE AN ERROR
    return *this;
}

String operator+(String lhs, const String& rhs){ 
    lhs += rhs;
    return lhs;
}

bool String::operator==(const String& rhs) const{ 
    for(int i = 0; i < length() || i < rhs.length(); ++i){
        if(str[i] != rhs.str[i]){
            return false;
        }
    }
    return true;
}

bool operator==(const char lhs[], const String& rhs){
    return String(lhs) == rhs;
}

bool operator== (char lhs, const String& rhs) {
    return String(lhs) == rhs;
}

bool String::operator<(const String& rhs) const{
    int i = 0;
    while(str[i] == rhs.str[i] && str[i] != '\0' && rhs.str[i] != '\0'){++i;}
        return str[i] < rhs.str[i];
}

bool operator<(const char lhs[],  const String& rhs){
    return String(lhs) < rhs;

}
bool operator<(char lhs, const String& rhs){
    return String(lhs) < rhs;
}
bool operator<= (const String& lhs, const String& rhs){
    return lhs == rhs || lhs < rhs;
}
bool operator!=(const String& lhs, const String& rhs){
    return !(lhs == rhs);
} 
bool operator>= (const String& lhs, const String& rhs){
    return !(lhs < rhs);
}
bool operator> (const String& lhs, const String& rhs){
    return lhs != rhs && !(lhs < rhs);
}


String  String::substr(int start, int end)const{
    if(start < 0) start = 0;
    if(end < 0) return ""; // invalid substr
    if (end >= length()) end = length() - 1;// if end is behind string, it sets to last index of String
    if (start > end) return ""; //invalid substr
    if (start == end) return str[start];

    char* result = new char[end - start + 2];  // add 1 for null terminator

    for (int i = start; i <= end; ++i){
        result[i - start] = str[i];  // stores original string from start to end in result;
    }

    result[end-start+1] = '\0';
    String substr(result);
    delete[] result;
    return substr;
}  

int String::findch(int start, char ch) const{
    if (start < 0) start = 0;
    if (start>= length()){
        return -1;
    }
    int i = start;
    while(str[i] != '\0'){
        if(str[i] == ch) {
            return i;
        }
        ++i;
    }
    return -1; //nothing found
}

int String::findstr (int start, const String& word) const{
    if (start < 0) start = 0;
    if (start>= length()){
        return -1;
    }
    int len = word.length();
    int i = start;
    while(str[i] != '\0'){
        if(str[i] == word.str[0]){
            for(int j = 0; j < len; ++j){
                if(str[i + j] != word[j])
                    break;
                if(j == len - 1)
                    return i;
            }
        }
        ++i;
    }
    return -1;
}

std::ostream& operator<<(std::ostream& out, const String& string){
    out << string.str;
    return out;
}

std::istream& operator>>(std::istream& in, String& rhs){
    char temp[1024];
    in >> temp;
    rhs = String(temp);
    return in;
}

std::vector<String> String::split(char ch) const{ 
    std::vector<String> stringVector;
    int start = 0;
    int end = 0;

    while (start <= length()) { // changed from < to <=
        end = findch(start, ch);

        if (end == -1) { //if ch not found, head to end of string
            end = length();
        }

        String result = substr(start, end - 1); //store result
        stringVector.push_back(result); //push result in vector

         // Move start to character after end
            start = end + 1;
    }

    return stringVector;
}




