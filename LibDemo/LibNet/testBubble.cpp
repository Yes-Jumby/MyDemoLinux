#include <iostream>
#include <StaticBubble.h>
 
using namespace std;
 
int main(int argc, char **argv){
    int array[5] = {32,54,38,65,98};
    bubbleSort(array, 5);
    for(int i = 0; i < 5; i++){
        cout << array[i] << '\t';
    }
    cout << endl;
 
}
