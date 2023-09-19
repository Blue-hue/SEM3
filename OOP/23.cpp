#include<string>
#include<iostream>
#include<random>
#include<vector>
using namespace std;

class Savings_Account{ 
    static float interest;
    const int ac_num;
    float bal;
    string name;

    public:
        static int global_ac_num;
        Savings_Account(const string &n, const float &b = 0):ac_num(global_ac_num){
            global_ac_num++;
            name = n;
            bal = b;
        }

        float withdraw(const float &amount){
            if(bal <= amount){
                return 0;
            }
            else if(bal-amount>1000){
                bal -= amount;
                return amount;
            }
            else{
                return 0;
            }
        }

        float deposit(const float &amount){
            bal += amount;
            return bal;
        }

        void show() const{
            cout<<"\nAccount holder : "<<name;
            cout<<"\nAccount number : "<<ac_num;
            cout<<"\nBalance : "<<bal;
        }

        float interest_year() const{
            return bal*interest;
        }

        void info_row() const{
            cout<<ac_num<<"\t"<<name<<"\t"<<bal<<"  +  "<<interest_year()<<endl;
        }

        float get_ac_num() const{
            return ac_num;
        }

        
};

int Savings_Account::global_ac_num = 100001;
float Savings_Account::interest = 0.025;

int main(){
    default_random_engine generator;
    uniform_real_distribution<float> distribution(1000,100000);
    float rand_balance;
    vector<Savings_Account*> accounts;

    cout<<"Enter number of accounts to create : ";
    int n;
    cin>>n;
    string temp_name; 
    for(int i=0;i<n;i++){
        rand_balance = distribution(generator);
        cout<<"Enter name for account number : "<<Savings_Account::global_ac_num<<"\n->";
        fflush(stdin);
        getline(cin,temp_name);
        Savings_Account *dummy = new Savings_Account(temp_name,rand_balance);
        accounts.push_back(dummy);
    }

    cout<<"Ac num\tName\tBalance   Annual interest\n";
    for(int i=0;i<n;i++){
        accounts[i]->info_row();
    }

    double total = 0;
    for(int i=0;i<n;i++){
        total += accounts[i]->get_ac_num();
    }
    cout<<"Total amount to be paid : " << total;
    
    for(int i=0;i<n;i++){
        delete accounts[i];
    }
    
}