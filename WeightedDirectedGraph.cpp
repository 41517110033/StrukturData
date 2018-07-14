/**
 * Author:      Asif Ahmed
 * Site:        http://quickgrid.blogspot.com
 * Description: Inputting and Representing an Weighted Directed graph
 *              in adjacency list vector of vector using C++ STL.
 */


#include<bits/stdc++.h>
using namespace std;


// pair<int, int> vertex adalah pasangan angka nomor verteks dan bobot dari edge yang menuju
// ke dirinya.
typedef pair<int, int> vertex;



// AdjacencyListType merupakan daftar semua verteks yang adjacent pada graph
typedef vector<vector <vertex>> AdjacencyListType;



// Bagian Input
// AdjacencyListType &adjList is pass by reference of the adjacency list of type vector<vector <vertex>>
// The const keyword is added wherever I know the value does not need to be modified.
void inputAdjacencyList(AdjacencyListType &adjList, int const& edges){
    int source, dest, weight;
    for(int i = 0; i < edges; ++i){ // Looping sebanyak jumlah edge yang diminta user
        cin >> source >> dest >> weight; // Menunggu inputan user dengan format:
                                         // verteks sumber <spasi> verteks tujuan <spasi> bobot

        vertex vet1(dest, weight); // Masukkan verteks tujuan, dan bobot kedalam variabel vertex
        adjList[source].push_back(vet1); // tambahkan vertex tersebut ke Adjacency list sebagai
                                         // tetangga dari verteks source (sumber)
    }
}

//Mencetak daftar semua verteks yang bertetangga (adjacent
void printCompleteAdjacencyList( AdjacencyListType const& adjList, int &v ){

    for(int i = 0; i < v; ++i){ // Looping sebanyak jumlah verteks pada graph

        int adjNodes = adjList[i].size(); // Ambil nomor verteks
        printf("Adjacent of: %d", i); // tampilkan nomor verteks sebagai sumber

        if(adjNodes > 0){ // Jika nomor verteks > 0
            for(int j = 0; j < adjNodes; ++j){  //Looping sebanyak tetangganya

                // tampilkan nomor verteks tetangganya dan juga bobot dari edge
                // yang menuju ke tetangganya tersebut
                printf(" -> %d (w:%d)", adjList[i][j].first, adjList[i][j].second);
            }
        }else{ // jika nomor node <= 0
            printf(" -> NONE"); // cetak "NONE"
        }

        printf("\n"); // Cetak baris baru
    }

}

// Mencetak verteks yang saling bertetangga (adjacent)
void listAdjacentNodes( AdjacencyListType const& adjList, int const& m){

    printf("%d", m); // cetak tetangganya
    for(int j = 0; j < adjList[m].size(); ++j){ // Looping sebanyak tetangganya

        // Cetak nomor verteks tetangganya  dan juga bobotnya
        printf(" -> %d (w:%d)", adjList[m][j].first, adjList[m][j].second);
    }

}


int main(){

    // Input the vertex or, node count of the graph
    printf("Enter number of nodes:\n");
    int v;
    cin >> v;


    // Create the adjacency list structure with size of v.
    AdjacencyListType adjList(v);


    // Input the edge count of the graph
    printf("Enter Edge count:\n");
    int edges;
    cin >> edges;


    // Input the adjacency list
    printf("\nEnter source, destination and weight:\n");
    inputAdjacencyList(adjList, edges);


    // Show the complete adjacency list structure
    printf("\nWhole Adjacency List:\n");
    printCompleteAdjacencyList(adjList, v);


    // Enter a node number to see its adjacent or connected nodes
    printf("\nEnter node number to see adjacent nodes:\n");
    int m;
    scanf("%d", &m);


    // If the given node number is greater than the vertexes or, node count do nothing
    if(m < v){
        listAdjacentNodes(adjList, m);
    }

    return 0;
}