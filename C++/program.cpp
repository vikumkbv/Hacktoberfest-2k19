//Implementation of linear search using structure
#include <iostream>
#include <string.h>
using namespace std;

struct employee {
	int eno;
	char name[50];
	float salary;
};

void search(employee x[], char query[], int n) {
	for(int a=0; a<n; a++) {
		if(!strcmp(x[a].name, query)) {
			cout<<"Employee number: "<<x[a].eno<<"\n";
			cout<<"Employee name: "<<x[a].name<<"\n";
			cout<<"Employee salary: "<<x[a].salary<<"\n";
		}
	}
}

int main() {
	int n;
	employee x[80];
	cout<<"Enter number of employees ";
	cin>>n;
	for(int a=0; a<n; a++) {
		cout<<"Enter employee number ";
		cin>>x[a].eno;
		cout<<"Enter employee name ";
		cin>>x[a].name;
		cout<<"Enter employee salary ";
		cin>>x[a].salary;
	}
	cout<<"Enter the employee's name to search ";
	char query[80];
	cin>>query;
	search(x, query, n);
	return 0;
}
