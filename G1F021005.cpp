//=======================//
//==DOUBLE LINKED LIST==//
//=====================//
#include <iostream>

using namespace std;

// struktur linked list
struct SmartPhone{
  string merkBarang;
  int TipeBarang, hargaBarang;

  // pointer
  SmartPhone *prev;
  SmartPhone *next;
};

SmartPhone *head, *tail, *cur, *del, *newNode, *afterNode;

// fungsi membuat circular double Linked list
void createSmartPhone( string merkBarang, int TipeBarang, int hargaBarang ){
  head = new SmartPhone();
  head->merkBarang = merkBarang;
  head->TipeBarang = TipeBarang;
  head->hargaBarang = hargaBarang;
  head->prev = head;
  head->next = head;
  tail = head;
}

// add First
void addFirst( string merkBarang, int TipeBarang, int hargaBarang ){
  if( head == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    newNode = new SmartPhone();
    newNode->merkBarang = merkBarang;
    newNode->TipeBarang = TipeBarang;
    newNode->hargaBarang = hargaBarang;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail->next = newNode;
    head = newNode;
  }
}

// add Last
void addLast( string merkBarang, int TipeBarang, int hargaBarang ){
  if( head == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    newNode = new SmartPhone();
    newNode->merkBarang = merkBarang;
    newNode->TipeBarang = TipeBarang;
    newNode->hargaBarang = hargaBarang;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail->next = newNode;
    tail = newNode;
  }
}


// remove First
void removeFirst(){
  if( head == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    del = head;
    head = head->next;
    tail->next = head;
    head->prev = tail;
    delete del;
  }
}

// remove Last
void removeLast(){
  if( head == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    del = tail;
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    delete del;
  }
}


// fungsi print
void printSmartPhone()
{
  if( head == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    cout << "Data Barang : " << endl;
    cur = head;
    while( cur->next != head ){
      // print
      cout << "Merk Barang : " << cur->merkBarang << endl;
      cout << "Tipe Barang : " << cur->TipeBarang << " barang" << endl;
      cout << "Harga Barang : Rp." << cur->hargaBarang << "\n" << endl;

      // step
      cur = cur->next;
    }
    // print last node
      cout << "Merk Barang : " << cur->merkBarang << endl;
      cout << "Tipe Barang : " << cur->TipeBarang << " barang" << endl;
      cout << "Harga Barang : Rp." << cur->hargaBarang << "\n" << endl;
  }
}

int main(){

  createSmartPhone("Android VIVO Y91", 15, 2000000);
  printSmartPhone();

  addFirst("Android OPPO A3S", 13, 3000000);
  printSmartPhone();

  addLast("Iphone XS", 10, 6000000);
  printSmartPhone();

  removeFirst();
  printSmartPhone();
  
  removeLast();
  printSmartPhone();

} 
