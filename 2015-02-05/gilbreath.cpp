/**************************************************************************************
*     This code is a mathematical test for question asked at
*     http://math.stackexchange.com/questions/1010169/
**************************************************************************************/

#include <iostream>
#include <vector>

typedef std::vector<int> num_vec;

// Generating a huge list of prime numbers 
void fill_prime(num_vec &primes, int N)
{	// N is to be a huge number
	primes.reserve(N);
	primes.push_back(2); // the only even number
	int found_counter=1;
	int prime_target=3;
	
	while(found_counter<N)
	{	// find more primes
		bool rejected=false;
		for(int k=0;k<found_counter && primes[k]*primes[k]<=prime_target && !rejected;k++)
		{
			if(prime_target%primes[k]==0) // dividable by previous prime numbers
				rejected=true;
		}
		if(!rejected) // is prime
		{
			primes.push_back(prime_target);  // add to the list of primes
			found_counter++;
		}
		prime_target+=2; // next odd number
	}
}

num_vec Gilbreath(const num_vec &numbers,const int k)
{
	num_vec results;
	const int gilbsize=numbers.size()-k;
	if(gilbsize<=0)
		return results;
	results.reserve(gilbsize);
	for(int n=0;n<gilbsize;n++)
		results.push_back(abs(numbers[n]-numbers[n+k]));
	return results;
}

void check_Gilbreath(const num_vec &numbers)
{
	num_vec g(numbers);
	int n=0;
	while(g.size()>1)
	{
		g=Gilbreath(g,1);
		n++;
		if(g[0]!=1)
		{
			std::cout<<"Gilbreath rejected at n="<<n<<std::endl;
			return ;
		}
	}
	std::cout<<"Gilbreath passed "<<numbers.size()<<" tests successfully"<<std::endl;
}

int main()
{
	const int N_prime=50000;
	const int k=2;
	num_vec primes;
	fill_prime(primes,N_prime);
	for(int k=1;k<100;k++)
	{
		std::cout<<"k="<<k<<std::endl;
		num_vec gilbk=Gilbreath(primes,k);
		check_Gilbreath(gilbk);	
	}
	return 0;
}

