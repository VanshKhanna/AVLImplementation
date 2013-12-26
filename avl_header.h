
#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>

using namespace std;
typedef unsigned long long int uint64_t;
/*struct data_list//Struct to use linked list in every node
{
char name[100];
data_list *next;
};*/

class avlnode  //one node in the avl tree
	{
		public:
		//int key;Don't need this anymore
		//char type[70]; //Holds the corresponding name
		
		//char number[100];// holds the number in HEX from the header and is used to in comparison when tree is formed; 
		
	//	data_list *T,*I,*P;//TIP are the three types of numbers possible. When a number is inserted into the tree, this links to the name of the field the number belongs. The name comes under the corresponding header type which I intend to store in the buffer when I read the file.
		
		/*
		union keygen//Union to use different types as one. Other option is using inheritance but not able to figure it out as there are problems liek copying stuff from one class to the other in various functions.
		
			{
				short int two;
				int 		 four;
				long int  six;
			} key;
		*/		
		
		uint64_t key;
		
		avlnode *left;
		avlnode *right;
		avlnode *parent;
		
		char balanceFactor;
		//int visit=0;Might not need this
		
		int flag; //32 bits. This must be enough.
		avlnode();
	};

/*struct 2_by::private avlnode
{
	short int number;
};

struct 4_by::private avlnode
{
	int number;
};

struct 6_by::private avlnode
{
	long int number;
};
*/

class network
{
   private:
	avlnode   *root;

   public:
      network();            // Constructor
      ~network();           // Destructor
      void Insert(avlnode *newNode, int type, int name);
      void restoreAVL(avlnode *ancestor, avlnode *newNode);
      void adjustBalanceFactors(avlnode *end, avlnode *start);
      void rotateLeft(avlnode *n);
      void rotateRight(avlnode *n);
      void adjustLeftRight(avlnode *end, avlnode *start);
      void adjustRightLeft(avlnode *end, avlnode *start);
//    void Delete(int key);  // Not implemented yet
      void PrintTree();
   	//void linked_list(data_list *active, char named[]);
   	void search(uint64_t number, int type, int name);
   private:
      void ClearTree(avlnode *n);
      void Print(avlnode *n);
};


