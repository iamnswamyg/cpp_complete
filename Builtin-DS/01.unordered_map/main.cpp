#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    // Hashtable/unordered_map = A data structure that stores unique keys to values ex.<Integer, String>
    	//			   Each key/value pair is known as an Entry
    	//			   FAST insertion, look up, deletion of key/value pairs
    	// 			   Not ideal for small data sets, great with large data sets
    	
    	// hashing = Takes a key and computes an integer (formula will vary based on key & data type)
    	//		       In a Hashtable, we use the hash % capacity to calculate an index number 
    	
    	//			key.hashCode() % capacity = index  
    	
    	// bucket = an indexed storage location for one or more Entries
    	//	            can store multiple Entries in case of a collision (linked similarly a LinkedList)
    	
    	// collision = hash function generates the same index for more than one key
    	//			less collisions = more efficiency
    	
    	// Runtime complexity: Best Case O(1)
    	//                                     Worst Case O(n)
        std::unordered_map<int, string> table;
    	
    	
    	table[100]="Spongebob";
    	table[123]="Patrick";
    	table[321]="Sandy";
    	table[555]="Squidward";
    	table[777]="Gary";
    	  	
    	for(auto pair : table) {
    		cout<< pair.first << "\t" << pair.second<<endl;
    	}
        
    
}