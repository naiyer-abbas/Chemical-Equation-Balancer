#include <bits/stdc++.h>
using namespace std;

int iscapital(char);
int issmall(char);
int isnum(char);
int c2i(char s);
//int is_balanced(vector <int>, vector <string> , vector<int>, vector<string>);
int is_balanced(vector<int> reactant_value, vector <int> product_value);

vector <string> reactant_elements;
vector <int> reactant_value;

vector <string> product_elements;
vector <int> product_value;

vector <pair < string, int > > reactant_table;
vector <pair < string, int > > product_table;


class Equation
{
private:
    vector <string> reactants;
    vector <string> products;
    int r,p;
public:
    void no_of_reactants();
    void no_of_products();

    void get_reactants();
    void get_products();
    void unbalanced();
};

void Equation :: no_of_reactants()
    {
        cin>>r;
    }
void Equation :: no_of_products()
    {
        cin>>p;
    }

void Equation :: get_reactants()
    {


        for(int i = 1; i <= r; i++)
        {
            string temp;
            cout<<"Enter reactant no. "<<i<<":  ";
            cin>>temp;
            reactants.push_back(temp);

            for(int j = 0; j < temp.size(); j++)
            {
                if(iscapital(temp[j]) && issmall(temp[j+1]) &&  j != temp.size() - 1)
                {
                    reactant_elements.push_back(string(1, temp[j]) + string(1, temp[j + 1]));
                    j++;
                }

                else if(iscapital(temp[j]) && iscapital(temp[j + 1]) && j != temp.size() - 1)
                {
                    reactant_elements.push_back(string(1, temp[j]));
                }

                else if(iscapital(temp[j]))
                {
                    reactant_elements.push_back(string(1, temp[j]));
                }

            }
            reactant_elements.push_back("-1");

            for(int j = 0; j < temp.size(); j++)
            {
                if(iscapital(temp[j]) && iscapital(temp[j + 1]) && j != temp.size() - 1)
                {
                    reactant_value.push_back(1);
                }

                else if(iscapital(temp[j]) && issmall(temp[j+1]) && iscapital(temp[j + 2]) && j != temp.size() - 2)
                {
                    reactant_value.push_back(1);
                    j++;
                }

                else if(iscapital(temp[j]) && isnum(temp[j + 1]) && j != temp.size() - 1)
                {
                    reactant_value.push_back(c2i(temp[j + 1]));
                    j ++;
                }

                else if(iscapital(temp[j]) && issmall(temp[j+1]) && isnum(temp[j + 2]) && j != temp.size() - 2)
                {
                    reactant_value.push_back(c2i(temp[j + 2]));
                    j += 2;
                }

                else if(iscapital(temp[j]) && j == temp.size() - 1)
                {
                    reactant_value.push_back(1);
                }

                else if(iscapital(temp[j]) && issmall(temp[j + 1]) && j == temp.size() - 2)
                {
                    reactant_value.push_back(1);
                    j++;
                }

            }

            reactant_value.push_back(-1);

        } /*
        cout<<"The reactant elements are ";
        for(const auto& e: reactant_elements)
        {
            cout<<e<<" ";
        }
        cout<<endl;

        cout<<"The reactant values are ";
        for(const auto& e: reactant_value)
        {
            cout<<e<<" ";
        }
        cout<<endl; */

    }

void Equation :: get_products()
    {

        for(int i = 1; i <= p; i++)
        {
            string temp;
            cout<<"Enter product no. "<<i<<":  ";
            cin>>temp;
            products.push_back(temp);

            for(int j = 0; j < temp.size(); j++)
            {
                if(iscapital(temp[j]) && issmall(temp[j+1]) &&  j != temp.size() - 1)
                {
                    product_elements.push_back(string(1, temp[j]) + string(1, temp[j + 1]));
                    j++;
                }

                else if(iscapital(temp[j]) && iscapital(temp[j + 1]) && j != temp.size() - 1)
                {
                    product_elements.push_back(string(1, temp[j]));

                }

                else if(iscapital(temp[j]))
                {
                    product_elements.push_back(string(1, temp[j]));
                }

            }
            product_elements.push_back("-1");

             for(int j = 0; j < temp.size(); j++)
            {
                if(iscapital(temp[j]) && iscapital(temp[j + 1]) && j != temp.size() - 1)
                {
                    product_value.push_back(1);
                }

                else if(iscapital(temp[j]) && issmall(temp[j+1]) && iscapital(temp[j + 2]) && j != temp.size() - 2)
                {
                    product_value.push_back(1);
                    j++;
                }

                else if(iscapital(temp[j]) && isnum(temp[j + 1]) && j != temp.size() - 1)
                {
                    product_value.push_back(c2i(temp[j + 1]));
                    j ++;
                }

                else if(iscapital(temp[j]) && issmall(temp[j+1]) && isnum(temp[j + 2]) && j != temp.size() - 2)
                {
                    product_value.push_back(c2i(temp[j + 2]));
                    j += 2;
                }

                else if(iscapital(temp[j]) && j == temp.size() - 1)
                {
                    product_value.push_back(1);
                }

                else if(iscapital(temp[j]) && issmall(temp[j + 1]) && j == temp.size() - 2)
                {
                    product_value.push_back(1);
                    j++;
                }

            }

            product_value.push_back(-1);

          }
       /*   cout<<"The product elements are ";
        for(const auto& e: product_elements)
        {
            cout<<e<<" ";
        }
        cout<<endl;

        cout<<"The product values are ";
        for(const auto& e: product_value)
        {
            cout<<e<<" ";
        }
        cout<<endl;
       */ }




void Equation :: unbalanced()
    {
        int m1=0,n1=0;
        for(const auto &e:reactants)
        {
            cout<<e;
            if(m1<reactants.size()-1)
            {
                cout<<" + ";
                m1++;
            }
        }
        cout<<" ---> ";
        for(const auto &e:products)
        {
            cout<<e;
            if(n1<products.size()-1)
            {
                cout<<" + ";
                n1++;
            }
        }
    }


int main()
{
    Equation E;
    cout<<"Enter the number of reactants : ";
    E.no_of_reactants();
    cout<<"Enter the number of products : ";
    E.no_of_products();
    E.get_reactants();
    E.get_products();
    cout<<"\nUnbalanced Reaction is : \n";
    E.unbalanced();

    if(is_balanced(reactant_value, product_value))
    {
        cout << "\n\nThe reaction is balanced\n";
    }

    else
    {
        cout << "\n\nThe reaction is unbalanced\n";
    }

    return 0;
}

int iscapital(char s)
{
    if(s >= 65 && s < 97)
        return 1;
    else
        return 0;
}

int issmall(char s)
{
    if(s >= 97 && s < 123)
        return 1;
    else
        return 0;
}

int c2i(char s)
{
    if(s >=50 && s <= 57)
        return s - 48;
}

int isnum(char c)
{
    if(c >= 50 && c<= 57)
        return 1;
    else
        return 0;
}

int is_balanced(vector<int> reactant_value, vector <int> product_value)
{
    vector <string> reactant_elements_copy = reactant_elements;
    vector <int> reactant_value_copy = reactant_value;

    vector <string> product_elements_copy = product_elements;
    vector <int> product_value_copy = product_value;

            //******************** FILLING THE REACTANT TABLE ****************************************//

    for(int i = 0; i < reactant_elements_copy.size(); i++)
    {
        if(reactant_elements_copy.at(i) != "-1")
        {
            reactant_table.push_back(make_pair(reactant_elements_copy.at(i) , reactant_value_copy.at(i)));

             for(int j = i + 1; j < reactant_elements_copy.size(); j++)
            {
                if(reactant_elements_copy.at(i) == reactant_elements_copy.at(j))
                {
                    reactant_elements_copy.at(j) = "-1";
                    reactant_table.at(i).second += reactant_value_copy.at(j);
                    reactant_value_copy.at(j) = -2;
                }
            }
        }
    }

        //******************** FILLING THE PRODUCT TABLE ****************************************//

    for(int i = 0; i < product_elements_copy.size(); i++)
    {
        if(product_elements_copy.at(i) != "-1")
        {
            product_table.push_back(make_pair(product_elements_copy.at(i) , product_value_copy.at(i)));

             for(int j = i + 1; j < product_elements_copy.size(); j++)
            {
                if(product_elements_copy.at(i) == product_elements_copy.at(j))
                {
                    product_elements_copy.at(j) = "-1";
                    product_table.at(i).second += product_value_copy.at(j);
                    product_value_copy.at(j) = -2;
                }
            }
        }
    }

    sort(reactant_table.begin(), reactant_table.end());
    sort(product_table.begin(), product_table.end());

    for(int i = 0; i < reactant_table.size(); i++)
    {
        cout<<endl<< reactant_table[i].first << "  "<< reactant_table[i].second;
    }

    cout<<endl;

    for(int i = 0; i < reactant_table.size(); i++)
    {
        cout<<endl<< product_table[i].first << "  "<< product_table[i].second;
    }

    if(reactant_table == product_table)
        return 1;
    else
        return 0;
}


/*int is_balanced(vector <int> reactant_value, vector <string> reactant_elements , vector <int> product_value , vector <string> product_elements)
{

}*/
