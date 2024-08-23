#include"header.h"

class my_string
{
    char *p;
    public:
    my_string();
    my_string(const char *);
    my_string(my_string &);
    ~my_string();
    my_string operator =(const my_string &);
   // my_string operator =(const char *);
    void get_data();
    my_string operator +(const my_string &);
   // my_string operator +(const char *);
/*   void modi()
   {
	   cout<<"modi"<<endl;
	   p[3]='z';
   }
   */
   char& operator [](const int );
   friend istream& operator >>(istream &,my_string &);
   friend ostream& operator <<(ostream &,my_string &);
   bool operator <(const my_string&);
   bool operator >(const my_string&);
   bool operator <=(const my_string&);
   bool operator >=(const my_string&);
   bool operator !=(const my_string&);
   bool operator ==(const my_string&);
   friend void strcpy(my_string &,my_string &);
   friend void strncpy(my_string &,my_string &,int);
   friend int strcmp(my_string &,my_string &);
   friend int strncmp(my_string &,my_string &,int);
   friend void strcat(my_string &,my_string &);
   friend void strncat(my_string &,my_string &,int);
   friend void strrev(my_string &);
   friend void struppor(my_string &);
   friend void strlower(my_string &);

   //friend my_string strchr(const my_string &,const char);
   friend char *strchr(const my_string &,const char);
   //friend my_string strrchr(const my_string &,const char);
   //friend my_string strstr(const my_string &,const my_string &);
   friend char* strrchr(const my_string &,const char);
   friend char* strstr(const my_string &,const my_string &);
   friend int strlen(const my_string &);
};

int main()
{
/*    my_string s1("harmish"),s2(s1),s3,s4;
    s1.get_data();
    s2.get_data();
    s2="mangukiya";
    s3=s1+" "+s2+" ashvinbhai";
    s1=s2;
    s2[3]='z';
    cout<<s1[3]<<endl;
    //s2.modi();
    s1.get_data();
    s2.get_data();
    s3.get_data();
    cout<<"---------------------"<<endl;
    cin>>s4;
    cout<<s4;
    cout<<"---------------------"<<endl;
    my_string s5("harmish"),s6("harmish");
    cout<<boolalpha;
    cout<<(s5==s6)<<endl;
    cout<<(s5!=s6)<<endl;
    cout<<(s5>s6)<<endl;
    cout<<(s5<s6)<<endl;
    cout<<(s5>=s6)<<endl;
    cout<<(s5<=s6)<<endl;
    */
    /*cout<<"---------------------"<<endl;
    my_string s7("harmish"),s8(" mangukiya");
    strncat(s7,s8,4);
    cout<<s7<<endl;
    strncpy(s7,s8,3);
    cout<<s7<<endl;
    */
    cout<<"-----------------------"<<endl;
/*    my_string s9("harmisa"),s10("harmis");
    cout<<strcmp(s9,s10)<<endl;
    cout<<strncmp(s9,s10,3)<<endl;
    struppor(s9);
    cout<<s9<<endl;
    strlower(s9);
    cout<<s9<<endl;
    s10=strchr(s9,'r');
    cout<<"------"<<endl;
    cout<<s10<<endl;
    cout<<strchr(s9,'m')<<endl;
    */
    my_string s11("harmiash"),s12("rm"),s13;
    cout<<strchr(s11,'a')<<endl;
    cout<<strrchr(s11,'a')<<endl;
    s13=strstr(s11,s12);
    cout<<s13<<endl;



}
//////////////////////////////////////////
my_string::my_string()
{
	p=new char(0);
}
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
my_string::~my_string()
{
    try
    {
    	delete []p;
    }
    catch(exception &e)
    {
	    cout<<"erorr"<<endl;
    }
}

my_string my_string::operator =(const my_string &t)
{
    p=(char *)realloc (p,strlen(t.p)+1);
    strcpy(p,t.p);
    return *this;
}
/*
my_string my_string::operator =(const char *s)
{
    p=(char *)realloc (p,strlen(s)+1);
    strcpy(p,s);
    return *this;
}*/

void my_string::get_data()
{
    cout<<p<<endl;
}

my_string my_string::operator +(const my_string &t)
{
	my_string rev;
	rev.p=new char[strlen(t.p)+strlen(p)+1];
	strcpy(rev.p,p);
	strcpy(rev.p+(strlen(p)),t.p);
	return rev;
}
/*my_string my_string::operator +(const char *s)
{
	my_string rev;
	rev.p=new char[strlen(s)+strlen(p)+1];
	strcpy(rev.p,p);
	strcpy(rev.p+(strlen(p)),s);
	return rev;
}*/
   
char& my_string::operator [](const int i)
{
	return p[i];
}
   
istream& operator >>(istream &in,my_string &s)
{
	s.p=(char *)realloc(s.p,2);
	int i=1;
	while(1)
	{
		in.get(s.p[i-1]);
		if(s.p[i-1]==10)
		{
			break;
		}
		i++;
		s.p=(char *)realloc(s.p,i+1);
	}
	s.p[i]='\0';
	return in;
}

ostream& operator <<(ostream &out,my_string &s)
{
	out<<s.p;
	return out;
}

bool my_string::operator <(const my_string &t)
{
	int i=0;
	for(i=0;p[i];i++)
	{
		if(t.p[i]!=p[i])
		{
			break;
		}
	}
	if(p[i]<t.p[i])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool my_string::operator >(const my_string &t)
{
	int i=0;
	for(i=0;p[i];i++)
	{
		if(t.p[i]!=p[i])
		{
			break;
		}
	}
	if(p[i]>t.p[i])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool my_string::operator <=(const my_string &t)
{
	int i=0;
	for(i=0;p[i];i++)
	{
		if(t.p[i]!=p[i])
		{
			break;
		}
	}
	if(p[i]<=t.p[i])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool my_string::operator >=(const my_string &t)
{
	int i=0;
	for(i=0;p[i];i++)
	{
		if(t.p[i]!=p[i])
		{
			break;
		}
	}
	if(p[i]>=t.p[i])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool my_string::operator !=(const my_string &t)
{
	int i=0;
	for(i=0;p[i];i++)
	{
		if(t.p[i]!=p[i])
		{
			break;
		}
	}
	if(p[i]!=t.p[i])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool my_string::operator ==(const my_string &t)
{
	int i=0;
	for(i=0;p[i];i++)
	{
		if(t.p[i]!=p[i])
		{
			break;
		}
	}
	if(p[i]==t.p[i])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void strcpy(my_string &t1,my_string &t2)
{
	int a1;
	for(a1=0;t2.p[a1];a1++)
	{
		t1.p[a1]=t2.p[a1];
	}
	t1.p[a1]=t2.p[a1];
}
void strncpy(my_string &t1,my_string &t2,int n)
{
	int a1;
	for(a1=0;a1<n;a1++)
	{
		t1.p[a1]=t2.p[a1];
	}
	t1.p[a1]=0;
}
int strcmp(my_string &t1,my_string &t2)
{
	int a1;
	for(a1=0;t2.p[a1];a1++)
	{
		if(t1.p[a1]!=t2.p[a1])
		{
			break;
		}
	}
	return t1.p[a1]-t2.p[a1];
}
int strncmp(my_string &t1,my_string &t2,int n)
{
	int a1;
	for(a1=0;a1<n;a1++)
	{
		if(t1.p[a1]!=t2.p[a1])
		{
			break;
		}
	}
	return t1.p[a1]-t2.p[a1];
}
void strcat(my_string &t1,my_string &t2)
{
	int a1,a2;
	for(a1=0;t1.p[a1];a1++);
	for(a2=0;t2.p[a2];a2++,a1++)
	{
		t1.p[a1]=t2.p[a2];
	}
	t1.p[a1]=t2.p[a2];
}
void strncat(my_string &t1,my_string &t2,int n)
{
	int a1,a2;
	for(a1=0;t1.p[a1];a1++);
	for(a2=0;a2<n;a2++,a1++)
	{
		t1.p[a1]=t2.p[a2];
	}
	t1.p[a1]=0;
}
void strrev(my_string &t1)
{
	int a1,a2;
	char t;
	for(a1=0;t1.p[a1];a1++);
	for(a2=0,a1=a1-1;a2<a1;a2++,a1--)
	{
		t=t1.p[a1];
		t1.p[a1]=t1.p[a2];
		t1.p[a2]=t;
	}
}
void struppor(my_string &t1)
{
	int a1,a2;
	for(a1=0;t1.p[a1];a1++);
	for(a2=0;a2<a1;a2++)
	{
		if((t1.p[a2]>='a')&&(t1.p[a2]<='z'))
		{
			t1.p[a2]=t1.p[a2]-32;
		}
	}
}
void strlower(my_string &t1)
{
	int a1,a2;
	for(a1=0;t1.p[a1];a1++);
	for(a2=0;a2<a1;a2++)
	{
		if((t1.p[a2]>='A')&&(t1.p[a2]<='Z'))
		{
			t1.p[a2]=t1.p[a2]+32;
		}
	}
}

/*my_string strchr(const my_string &t1,const char ch)
{
	int a1;
	my_string rev;
	for(a1=0;t1.p[a1];a1++)
	{
		if(t1.p[a1]==ch)
		{
			rev.p=t1.p+a1;
			cout<<rev<<endl;
			return rev; 
		}
	}
	rev.p=0;
	return rev;
}*/
char *strchr(const my_string &t1,const char ch)
{
	int a1;
	//my_string rev;
	for(a1=0;t1.p[a1];a1++)
	{
		if(t1.p[a1]==ch)
		{
			//rev.p=t1.p+a1;
			//cout<<rev<<endl;
			return t1.p+a1; 
		}
	}
	//rev.p=0;
	return 0;
}

char* strrchr(const my_string &t,const char ch)
{
	int a2;
	a2=strlen(t);
	for(a2=a2-1;a2;a2--)
	{
		if(t.p[a2]==ch)
		{
			return t.p+a2;
		}
	}
	return 0;
}
char* strstr(const my_string &t1,const my_string &t2)
{
	int a1,a2;
	char *p,*p1;
	a2=strlen(t2);
	while(p=strchr(t1,t2.p[0]))
	{
		p1=p;
		for(a1=1;a1<a2;a1++,p++)
		{
			if(*p!=t2.p[a1])
			{
				break;
			}
		}
		if(a1==(a2-1))
		{
			return p1;
		}
	}
	return 0;
}
int strlen(const my_string &t1)
{
	int a=0;
	while(t1.p[a])
	{
		a++;
	}
	return a;
}