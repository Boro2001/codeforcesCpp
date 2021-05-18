#include <iostream>

using namespace std;
class Node
{
private:
	int wysoksc;
public:
	double wartosc;
	static int ilosc;
	Node * left, * right, * parent;
	Node(/* args */);
	~Node();
};
int Node::ilosc = 0;

Node::Node(/* args */)
{
	cout<<"new node added \n";
}

Node::~Node()
{
}
void wstaw(double w, Node ** root){
	Node * nowy = new Node;
	Node * porzednik, * ws;
	nowy->ilosc+=1;
	nowy->wartosc= w;
	nowy->left=nullptr; nowy->right=nullptr;
	ws = *root;
	while (ws)
	{
		porzednik = ws;
		if(w>=ws->wartosc) ws = ws->right;
		else ws = ws->left;
	}
	nowy->parent = porzednik;
}
void wypisz(Node * root)
{
	if(root==nullptr)return;
	wypisz (root->left);
	cout<<root->wartosc;
	wypisz(root->right);
};


int main(){
	Node  * root = nullptr;
	wstaw(5, &root);wstaw(2, &root);wstaw(6, &root);wstaw(7, &root);wstaw(8, &root);wstaw(3, &root);wstaw(9, &root);
	wypisz(root);
	cout<<root->ilosc;
 	return 0;
}
