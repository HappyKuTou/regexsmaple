#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

int main()
{
    ifstream is("junshi.html");
    if(is)
    {
        is.seekg(0, is.end);
        int size = is.tellg();
        is.seekg(0, is.beg);

        string buf1(size, 0);
        is.read((char *)buf1.data(), size);

        if(is)
        {
            smatch sm1;
            regex reg1("today_news[\\w\\W]*?div");
            regex_search(buf1, sm1, reg1);
            //cout<<"string literal with "<<sm1.size()<<" matches\n";
            if(sm1.size() > 0)
            {
                
                smatch sm2;
                regex reg2("<a href=[\\w\\W]*?>");
                string buf2;
                buf2 = sm1.str();
                
                while(regex_search(buf2, sm2, reg2))
                {
                    //cout<<"string object with "<<sm2.size()<<" matches\n";
                
                    //cout<<sm2[0]<<endl;
                    
                    smatch sm3;
                    string buf3 = sm2.str();
                    regex reg3("[\\w\\W]*?\"[\\w\\W]*?\"[\\w\\W]*?\"([\\w\\W]*)?\"");
                    if(regex_search(buf3, sm3, reg3))
                    {
                        //cout<<"string object with "<<sm2.size()<<" matches\n";
                        cout<<sm3[1]<<endl;
                    }
                    
                    buf2 = sm2.suffix().str();
                }
            }
        }
        else
            cout<<"error: only"<<is.gcount()<<"could be read"<<endl;

        is.close();
    }

    return 0;
}
