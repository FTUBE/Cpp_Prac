#include "Receipt.h"

using namespace std;

int main(int argc, char *argv[]){
  
  if(argc != 2){
    cout << "Usage : ./main [InputFilename]" << endl;
    exit(1);
  }

  Receipt r;
  
  r.loadGoodsFromFile(argv[1]);
  r.printTotal();
  
  return 0;
}


