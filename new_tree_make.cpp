//It is assumed that there is a space after 2 characters(1 by).

//Reading the packet
#include"avl_header.h"
//#include<iostream>
#include<fstream>

using namespace std;

#define TCP 0x06;
#define IP 0x0800;
#define VLAN 0x0810;

int main()
{
network *theTree;//Initiating a tree
ifstream reader;
reader.open("file.hex",ios::binary|ios::in);


//cout<<"run";

theTree=new network();
int temp=0;
uint64_t temper[8];
reader.seekg(0,ios::beg);
uint64_t des_mac=0;
for(int i=0;i<6;i++)
{
	reader>>hex>>temper[i];
	
}
des_mac=(temper[0]<<40)|(temper[1]<<32)|(temper[2]<<24)|(temper[3]<<16)|(temper[4]<<8)|temper[5];
cout<<"destination mac "<<hex<<des_mac<<"\n";



	avlnode *node_a;
	node_a=new avlnode();
	node_a->key = des_mac;
	theTree->Insert(node_a, 2, 3);


uint64_t source_mac_add=0;

for(int i=0;i<6;i++)
{
	reader>>hex>>temper[i];//function to look inside the linked list
	
}
source_mac_add=(temper[0]<<40)|(temper[1]<<32)|(temper[2]<<24)|(temper[3]<<16)|(temper[4]<<8)|temper[5];

	avlnode *node_b;
	node_b=new avlnode();
	node_b->key = source_mac_add;
	theTree->Insert(node_b, 2, 4);


uint64_t type=0;
for(int i=0;i<1;i++)
{
	reader>>hex>>temper[i];
	
}
type=(temper[0]<<8)|temper[1];
cout<<"\nThe type is "<<type;
avlnode *node_c;
	node_c=new avlnode();
	node_c->key = type;
	theTree->Insert(node_c, 2, 5);



uint64_t flag;
uint64_t source_port;
uint64_t destination_port;
uint64_t source_ip;
uint64_t destination_ip;
uint64_t protocol;


if(type==0x0800)
{
	reader.seekg(32,ios::cur);
	reader>>hex>>protocol;
	cout<<"\nprotocol is "<<hex<<protocol;
	avlnode *node_d;
	node_d=new avlnode;
	node_d->key = protocol;
	theTree->Insert(node_d,1,6);
	
	
	reader.seekg(6,ios::cur);
	
	for(int i=0;i<4;i++)
	{
	 	reader>>hex>>temper[i];
	
	}//function to look inside the linked list
	source_ip=(temper[0]<<24)|(temper[1]<<16)|(temper[2]<<8)|temper[3];
	
	avlnode *node_e;
	node_e=new avlnode;
	node_e->key=source_ip;
	theTree->Insert(node_e,1,7);
		
	for(int i=0;i<4;i++)
	{
	 	reader>>hex>>temper[i];
	
	}
	destination_ip=(temper[0]<<24)|(temper[1]<<16)|(temper[2]<<8)|temper[3];
	
	avlnode *node_f;
	node_f=new avlnode;
	node_f->key=destination_ip;
	theTree->Insert(node_f,1,8);
		
	if(protocol==0x06)
		{
		//Reading source port
			for(int i=0;i<2;i++)
	{
	 	reader>>hex>>temper[i];
	
	}
	source_port=(temper[0]<<8)|(temper[1]);
	
	avlnode *node_g;
	node_g=new avlnode;
	node_g->key=source_port;
	theTree->Insert(node_g,0,9);
		
		//Reading Destination Port
		for(int i=0;i<2;i++)
	{
	 	reader>>hex>>temper[i];
	
	}
	destination_port=(temper[0]<<8)|(temper[1]);
	
	avlnode *node_h;
	node_h=new avlnode;
	node_h->key=destination_port;
	theTree->Insert(node_h,0,10);
	theTree->PrintTree();
	
		//reader.seekg(18, ios::cur);
	
//		reader>>hex>>flag;
	//	int bitmask=pow(2,4);
		//if((flag & bitmask)==bitmask)
		 //{
		 	//cout<<"ACK";
		 //}
		//}
		}

}
else
{cout<<"\nNot IP";}

reader.close();
	//Searching for e0f7263fe9-the destination mac address, type=2, name=3
	theTree->search(0xe0f7263fe9,2,3);
	//Searching for e0f7263fe9-the source mac address, type=2, name=4. This should return not found.
	theTree->search(0xe0f7263fe9,2,4);
	delete theTree;
	return 0;

}
	
	
	
	
	

