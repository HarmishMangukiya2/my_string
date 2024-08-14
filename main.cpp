#include"header.h"

class my_string
{
    char *p;
    public:
    my_string(){}
    my_string(const char *);
    my_string(my_string &);
    ~my_string();
    my_string operator =(my_string);
    my_string operator =(const char *);
    void get_data();

};

int main()
{
    my_string s1("harmish"),s2(s1);
    s1.get_data();
    s2.get_data();
    s2="mangukiya";
    s1=s2;
    s1.get_data();
    s2.get_data();
}
//////////////////////////////////////////
my_string::my_string(const char *s)
{
    p=new char [strlen(s)+1];
    strcpy(p,s);
}
my_string::my_string(my_string &s)
{
    p=new char [strlen(s.p)+1];
    strcpy(p,s.p);
}

my_string my_string::operator =(my_string t)
{
    p=(char *)realloc (p,strlen(t.p)+1);
    strcpy(p,t.p);
    return *this;
}
my_string my_string::operator =(const char *s)
{
    p=(char *)realloc (p,strlen(s)+1);
    strcpy(p,s);
    return *this;
}

void my_string::get_data()
{
    cout<<p<<endl;
}