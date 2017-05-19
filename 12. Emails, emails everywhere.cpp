#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

struct email_body{
    string email_name;
    int order;
    int urgent;
};

struct less_imp{
    bool operator()(const email_body& email1, const email_body& email2){
        if(email1.urgent != email2.urgent)
            return email1.urgent < email2.urgent;
        else
            return email1.order > email2.order;
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int order = 0;
    priority_queue<email_body,vector<email_body>,less_imp> emails;
    int ops;
    cin >> ops;
    for(int i = 0; i < ops; i++){
        string temp;
        cin >> temp;
        if(temp == "store"){
            string email;
            int nums;
            cin >> email >> nums;
            email_body temp_email;
            temp_email.email_name = email;
            temp_email.order = order;
            temp_email.urgent = nums;
            emails.push(temp_email);
            order++;
        }
        else{
            if(!emails.empty()){
                cout << emails.top().email_name << endl;
                emails.pop();
            }
            else
                cout << "-1" << endl;
        }
    }
    
    return 0;
}

