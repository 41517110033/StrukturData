#include <stdio.h>

struct Node{
    int isi;
    Node *left_child;
    Node *right_child;
    Node *parent;
};

struct List{
    int indeks;
    int isi;
    List *next;
};

Node *root = NULL;
Node *bantu = NULL;
List *awal = NULL;
List *akhir = NULL;
int banyakNode, counter;
bool isAdjacent;

void tampil(void);
void tambahLeftChild(void);
void tambahRightChild(void);
void kunjungiParent(void);
void kunjungiLeftChild(void);
void kunjungiRightChild(void);
void kunjungiRoot(void);
void traverseInorder(struct Node* node);
void convertToGraph(void);
void checkAdjacency(int i, int j, struct Node* node);

int main()
{
    int nilai, pilihan = -1;

    do {
        tampil();

        if (root == NULL) {
            printf("Masukkan nilai root : ");
            scanf("%d", &nilai);
            root = new Node;
            root->isi = nilai;
            root->left_child = NULL;
            root->right_child = NULL;
            root->parent = NULL;
            bantu = root;

            awal = new List;
            awal->indeks = 0;
            awal->isi = root->isi;
            awal->next = NULL;
            akhir = awal;
        } else {
            printf("1. Tambah Left Child\n");
            printf("2. Tambah Right Child\n");
            printf("3. Kunjungi Parent\n");
            printf("4. Kunjungi Left Child\n");
            printf("5. Kunjungi Right Child\n");
            printf("6. Kunjungi Root\n");
            printf("7. Ubah ke Graph (Matriks Adjacency)\n");
            printf("0. Keluar dari program\n");
            printf("Pilihan Anda : ");
            scanf("%d", &pilihan);

            switch(pilihan){
                case 1: tambahLeftChild(); break;
                case 2: tambahRightChild(); break;
                case 3: kunjungiParent(); break;
                case 4: kunjungiLeftChild(); break;
                case 5: kunjungiRightChild(); break;
                case 6: kunjungiRoot(); break;
                case 7: convertToGraph(); break;
                case 0:
                default: break;
            }
        }
    } while(pilihan != 0);
}

void tampil(void)
{
    List *b;
    if(root == NULL)
    {
        printf("Belum ada node\n");
    } else {
        printf("Inorder Traversal : ");
        banyakNode = 0;
        traverseInorder(root);
        printf("\nPosisi : %d/%d\n", bantu->isi,banyakNode);
        printf("Isi List : ");
        b = awal;
        do{
            printf("%d ", b->isi);
            b = b->next;
        }while(b != NULL);
        printf("\n");
    }
}

void tambahLeftChild(void)
{
    int nilai;
    Node *baru;
    List *anyar;
    if(bantu->left_child != NULL){
        printf("Node ini sudah mempunyai Left Child!\n");
    } else {
        baru = new Node;
        printf("Masukkan nilai untuk left child : ");
        scanf("%d", &nilai);
        baru->isi = nilai;
        baru->parent = bantu;
        baru->left_child = NULL;
        baru->right_child = NULL;
        bantu->left_child = baru;

        anyar = new List;
        anyar->indeks = akhir->indeks + 1;
        anyar->isi = baru->isi;
        anyar->next = NULL;
        akhir->next = anyar;
        akhir = anyar;
    }
}

void tambahRightChild(void)
{
    int nilai;
    Node *baru;
    List *anyar;
    if(bantu->right_child != NULL){
        printf("Node ini sudah mempunyai Left Child!\n");
    } else {
        baru = new Node;
        printf("Masukkan nilai untuk right child : ");
        scanf("%d", &nilai);
        baru->isi = nilai;
        baru->parent = bantu;
        baru->left_child = NULL;
        baru->right_child = NULL;
        bantu->right_child = baru;

        anyar = new List;
        anyar->indeks = akhir->indeks + 1;
        anyar->isi = baru->isi;
        anyar->next = NULL;
        akhir->next = anyar;
        akhir = anyar;
    }
}

void kunjungiParent(void)
{
    if(bantu->parent == NULL){
        printf("Anda sudah berada di Root (%d)!\n", bantu->isi);
    } else {
        bantu = bantu->parent;
        printf("Posisi : %d", bantu->isi);
    }
}

void kunjungiLeftChild(void)
{
    if(bantu->left_child == NULL){
        printf("Node ini tidak memiliki left child!\n");
    } else {
        bantu = bantu->left_child;
//        printf("Posisi : %d", bantu->isi);
    }
}

void kunjungiRightChild(void)
{
    if(bantu->right_child == NULL){
        printf("Node ini tidak memiliki right child!\n");
    } else {
        bantu = bantu->right_child;
//        printf("Posisi : %d", bantu->isi);
    }
}

void kunjungiRoot(void)
{
    bantu = root;
//    printf("Posisi : %d", bantu->isi);
}

void traverseInorder(struct Node* node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    traverseInorder(node->left_child);

    /* then print the data of node */
    printf("%d ", node->isi);
    banyakNode++;

    /* now recur on right child */
    traverseInorder(node->right_child);
}

void convertToGraph(void)
{
    List *b;
    int N = akhir->indeks + 1, n = 0, sementara;
    int barisan[N];
    b = awal;
    do{
        barisan[n] = b->isi;
        b = b->next;
        n++;
    }while(b != NULL);

    printf("Sebelum sorting : ");
    for(int i=0; i<N; i++){
        printf("%d ", barisan[i]);
    }
    printf("\n");

    //Bubble Sorting
    for(int i=1; i<N; i++){
        for(int j=0; j<(N-i); j++){
            if(barisan[j] > barisan[j+1]){
                sementara = barisan[j];
                barisan[j] = barisan[j+1];
                barisan[j+1] = sementara;
            }
        }
    }

    printf("Hasil sorting : ");
    for(int i=0; i<N; i++){
        printf("%d ", barisan[i]);
    }
    printf("\n");


    int adjacency_matrix[N][N]; // Generate Matriks N x N sebagai representasi Graph
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            adjacency_matrix[i][j] = 0; // Set setiap elemen matriks bernilai 0
        }
    }

    // Note: variabel array "barisan" berisi nilai dari node-node yang ada di binary tree
    for(int i=0; i<N; i++){ // Looping sebanyak jumlah elemen "barisan"
        for(int j=0; j<N; j++){ // Looping lagi sebanyak jumlah elemen "barisan"
            //Note: dua looping dibutuhkan karena akan memeriksa adjacency elemen ke-i dan ke-j
            isAdjacent = false; // Awalnya set adjacency = false
            checkAdjacency(barisan[i], barisan[j], root); // fungsi ini akan mengeset
                                                          // variabel isAdjacent menjadi
                                                          // bernilai true jika barisan[i] memiliki
                                                          // child yang bernilai barisan [j]
            if(isAdjacent) { // Jika elemen ke-i dan elemen ke-j adjacent maka beri nilai 1 pada
                             // matriks elemen ke-i,j
                adjacency_matrix[i][j] = 1;
                adjacency_matrix[j][i] = 1; // Dan beri pula nilai 1 untuk elemen matriks ke-j,i
                                            // Hal ini dikarenakan graph yang dihasilkan adalah
                                            // undirected graph (graph tak berarah) dimana
                                            // [i,j] = [j,i]
            }
        }
    }

    printf("Matriks adjacency yang merepresentasikan graph adalah sebagai berikut:\n    ");
    for(int i=0; i<N; i++)
        printf("%d ",barisan[i]);

    printf("\n   ");
    for(int i=0; i<N; i++)
        printf("__",barisan[i]);

    for(int i=0; i<N; i++){
        printf("\n%d | ", barisan[i]);
        for(int j=0; j<N; j++){
            printf("%d ", adjacency_matrix[i][j]);
        }
    }
    printf("\n");
}

void checkAdjacency(int A, int B, struct Node* node)
{
    Node *left, *right;

    if (node == NULL || isAdjacent)
        return;

    /* then print the data of node */
    left = node->left_child;
    right = node->right_child;

    if(left != NULL){
        if(node->isi == A && left->isi == B)
            isAdjacent = true;
    }

    if(right != NULL){
        if(node->isi == A && right->isi == B)
            isAdjacent = true;
    }

    /* first recur on left child */
    checkAdjacency(A, B, left);

    /* now recur on right child */
    checkAdjacency(A, B, right);
}