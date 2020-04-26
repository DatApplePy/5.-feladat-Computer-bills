#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <cctype>


using namespace std;

struct Bill
{
    vector<string> name;
    vector<string> product;
    vector<int> sum;
};

enum Status {norm, abnorm};

bool read (ifstream &iF, Bill &dt, Status &st)
{
    string dataLine;
    getline(iF, dataLine);

    if(!iF.fail() && dataLine != "")
    {
        st = norm;
        istringstream in(dataLine);
        string str_dataPart;
        int int_dataPart;

        while(!in.eof())
        {
            if (isupper(in.peek()))
            {
                in >> str_dataPart;
                in.ignore();
                dt.name.push_back(str_dataPart);

            }
            else
            {
                while(!in.eof())
                {
                    in >> str_dataPart;
                    dt.product.push_back(str_dataPart);
                    in >> int_dataPart;
                    dt.sum.push_back(int_dataPart);
                }
            }
        }
    }
    else
    {
        st = abnorm;
    }
    return st==norm;
}

int main()
{
    ifstream x ("inp.txt");
    if(x.fail())
    {
        cout << "Wrong filename!";
        return 1;
    }

    Bill dt;
    Status st;
    bool Min20 = false;

    while(read(x, dt,st) && !Min20)
    {
        for(auto it = dt.sum.begin(); it != dt.sum.end(); ++it)
        {
            if (*it < 20000)
            {
                Min20 = false;
                break;
            }
            else
            {
                Min20 = true;
            }
        }

        dt.name.clear();
        dt.product.clear();
        dt.sum.clear();
    }

    if (Min20) cout << "Van!";
    else cout << "Nincs!";

    return 0;
}
