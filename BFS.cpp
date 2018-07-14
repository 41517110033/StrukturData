/*
 * Sumber : https://gist.github.com/douglas-vaz/5072998
 * */
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

class Node{
    char value;
    vector<Node> children;
public:
    Node(char c){
        value = c;
    }

    void addChild(Node n){
        children.push_back(n);
        return;
    }

    void addChild(char n){
        Node foo(n);
        children.push_back(foo);
    }

    char getValue(){
        return value;
    }

    vector<Node> getChildren(){
        return children;
    }

    bool isLeaf(){
        return children.size()==0;
    }

    bool operator==(Node b){
        return b.value==value;
    }
};


void construct(Node *r)
{
    string foo;
    cout<<"Enter children for "<< r->getValue() <<" (-1 for leaf)"<<endl;
    cin>>foo;

    if(foo == "-1")
        return;
    else{
        for(int i = 0; i < foo.length(); i++)
        {
            Node t(foo[i]);
            construct(&t);

            r->addChild(t);
        }
    }
}

string breadthFirstSearch(Node root, Node goal)
{
    std::queue<Node> Q; // Variabel untuk menampung semua node
    std::vector<Node> children; // Variabel untuk menampung yang dikunjungi
    string path = "";   // Mulai dari path kosong (hasil pencarian = {} )

    Q.push(root); // Masukkan node root ke antrian Q

    while(!Q.empty()) // Looping sampai semua node dalam Q diperiksa
    {
        Node t = Q.front();   // inisialisasi variabel t sebagai node pertama
        path += t.getValue(); // tambahkan huruf di node t ke dalam hasil pencarian

        Q.pop(); // hapus satu elemen Q dari depan

        if(t == goal){ // Jika huruf yang dicari ditemukan
            return path; // keluar dari fungsi, dengan variabel path berisi
                         // urutan traversal sampai pada nilai yang dicari
        }
        children = t.getChildren(); // ambil subtree dari node t
        for (int i = 0; i < children.size(); ++i) // Untuk setiap node di subtree tersebut
        {
            Q.push(children[i]); // masukkan node tersebut ke antrian Q untuk diperiksa
        }
    }
    return path; // keluar dari fungsi, dengan variabel path berisi seluruh node yang
                 // dikunjungi
}

string depthFirstSearch(Node root, Node goal)
{
    std::stack<Node> Q;         // Variabel yang akan menampung tumpukan semua node pada tree
    std::vector<Node> children; // Variabel yang akan mencatat traversal pencarian berikutnya
    string path = "";           // Variabel yang menampung hasil pencarian

    Q.push(root);               // Masukkan node yang sedang diperiksa ke variabel (tumpukan) Q

    while(!Q.empty())           // Loop sampai Q kosong (semua node sudah diperiksa)
    {
        Node t = Q.top();       // Ambil node paling akhir (atas) pada tumpukan Q, simpan di variabel (node) t
        path += t.getValue();   // Tambahkan nilai node t ke hasil pencarian

        Q.pop();                // Hapus node paling akhir (atas) dari tumpukan Q

        if(t == goal){          // Kalau nilai node t adalah nilai yang dicari
            return path;        // maka isi variabel path adalah hasil traversal pencarian
        }
        children = t.getChildren(); // Masukkan node-node di subtree t ke variabel children
        std::reverse(children.begin(),children.end()); // Urutan variabel children dibalik,
                                                       // karena stack akan memproses node paling akhir lebih dahulu

        for (int i = 0; i < children.size(); ++i){ // Loop semua node pada subtree yang tersimpan di variabel children
            Q.push(children[i]); // Masukkan nilai masing-masing node ke variabel (tumpukan) Q untuk diperiksa
        }
    }
    return path; // Jika sudah semua node diperiksa namun tidak ketemu yang dicari, maka keluar dari proses pencarian
}

int main(int argc, char** args)
{
    char r;
    cout<<"Enter root node"<<endl;
    cin>>r;

    Node root(r);
    construct(&root);

    cout<<"Enter Node to search for: ";
    cin>>r;

    cout<<endl;

    cout<<"BFS Traversal: "<<breadthFirstSearch(root, Node(' '))<<endl;
    cout<<"BFS Search Path: "<<breadthFirstSearch(root, Node(r))<<endl<<endl;

    cout<<"DFS Traversal: "<<depthFirstSearch(root, Node(' '))<<endl;
    cout<<"DFS Search Path: "<<depthFirstSearch(root, Node(r))<<endl;

    return 0;
}