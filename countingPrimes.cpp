#include<iostream>
#include<vector>

using namespace std;
int main(){
	int userInput;
	bool isPrime = true;
	int nextVal = 11;
	vector<int> primes{2,3,5,7};
	
	cout<<"Please enter how many primes you would like to find: "
	cin >> userInput;
	
	while(userInput > primes.size()){
		for(int i=0; i<primes.size(); i++){
			if(nextVal%primes[i]==0){
				isPrime = false;
				break;
			}
			else if(primes[i] > nextVal / 2){
				break;
			}
		}
		if(isPrime){
			primes.push_back(nextVal);
			cout<<(float(primes.size())/float(userInput)*100.0) << "% Complete" << endl;
		}
		else{
			isPrime = true;
		}
		nextVal++;
	}
	
	for(int i=0; i<primes.size(); i++){
		cout << primes[i]<<" ";
	}
	cout << endl << "Primes Found:  " << userInput<<endl;
	return 0;
}
