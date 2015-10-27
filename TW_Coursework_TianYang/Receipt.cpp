#include "Receipt.h"

void Receipt::loadGoodsFromFile(string filename){

  // Items Loading from text file.
  
  if(counts != 0){
    printf("Goods already loaded.\n");
    return;
  }
  
  ifstream file;
  file.open(filename);

  if(file.fail()){
    cout << "File is not existed.\n";
    exit(1);
  }
  
  // Loading Dictionary to memory.
  
  loadDic();

  //Call GoodsFactory to build the object from given line.
  
  char *line = new char[MAXLENGTH+1];

  while(file.getline(line,MAXLENGTH)){
    items.push_back(goodsFactory(line));
  }
  delete line;
  
  //Initialize the item count.
  counts = items.size();

  file.close();

};

Goods* Receipt::goodsFactory(char *line){

  //Tokenizing given line.
  
  char *pch;
  pch = strtok(line," ");
  vector<string> arr;
  
  while(pch){
    string part(pch);
    arr.push_back(part);
    pch = strtok(NULL," ");
  }

  // Get item count.
  
  int pieces = stoi(arr[0],nullptr,10);   
  double price = stod(arr[arr.size()-1]);
  
  // Collect the full name and 'imported' in one pass.

  bool imp = false;
  string name = "";
  for(int  i = 1; i < arr.size()-2;i++){
    name += (arr[i]+" ");
    if(!imp && arr[i].compare("imported") == 0){
      imp = true;
      continue;
    }    
  }

  // Backward scan for the true name. In total it gives O(N) performance.
  
  string truename = "";
  for(int i = arr.size()-3; i > 0; i--){
    if(arr[i].compare("imported") == 0 || arr[i].compare("of") == 0){
      break;
    }
    if(i == arr.size()-3){
      truename = arr[i] + truename;
      continue;
    }
    truename = arr[i] + " " + truename;
  }

  // Check if Exempted.
  bool exem = isExem(truename);

  double rate  = 0;
  
  if(!exem) rate += 0.1;
  if(imp) rate += 0.05;
  
  Goods* newgood = new Goods(name,pieces,price,rate);
  
  return newgood;
  
};

bool Receipt::isExem(string truename){
  
  int dicSize = dicExem.size();
  
  for(int i = 0; i < dicSize ; i++){
    if(truename.compare(dicExem[i]) == 0) return true;
  }
  
  return false;
  
};

void Receipt::printTotal(){

  double taxTotal = 0;
  double total = 0;

  cout.setf(ios::fixed);
  cout.precision(2);

  for(int i = 0; i < counts; i++){
    unsigned int pieces = items[i]->getPieces();
    string name = items[i]->getName();
    double price = items[i] -> getTotal();
  
    cout << pieces << " " << name << ": "<< price << endl;
    
    total += price;
    taxTotal += items[i] -> getTax();
  }
  
  cout << "Sales Taxes : " << taxTotal << endl;
  cout << "Total : " << total << endl;  
};

void Receipt::loadDic(){

  //  cout << "Loading Dic......\n";
  
  ifstream in[3];
  in[0].open("dictionary/foods.txt");
  in[1].open("dictionary/books.txt");
  in[2].open("dictionary/medical.txt");

  for(int i = 0; i < 3; i++){
    if(in[i].fail()){
      cout << "Dictionary Loading Error.\n";
      exit(1);
    }
  }
  
  char *line = new char[WORD];
  
  for(int i = 0; i < 3; i++){

    while(in[i].getline(line,WORD)){
      string it(line);
      dicExem.push_back(it);
    }
    //    cout << "Complete Loading ["<<i<<"]\n"; 
    in[i].close();

  }
  delete line;
}

//Overridding the deconstructor.

Receipt::~Receipt(){

  for(int i = 0; i < counts; i++){
    delete items[i];
  }
  
};
