#include <iostream>

using std::cout;
using std::endl;

template<typename tn>
class list {
private:
    tn* array;
    int MaxSize;
public:
    int size;
    void constructor (int n){
        array = new tn[n];
        size = 0;
        MaxSize = n;
    }
    void push(tn value){
        if (size < MaxSize){
            array[size] = value;
            size++;
        } else {
            cout << "Out of range" << endl;
        }
    }
    void print (){
        for (int i = 0; i < size; ++i) {
            cout << array[i] << ' ';
        }
        cout << endl;
    }
    void destructor (){
        delete [] array;
        size = 0;
    }
    void PushByIndex (int n, tn value){
        if (n < size && size < MaxSize) {
            for (int i = size; i > n; i--) {
                array[i] = array[i - 1];
            }
            array[n] = value;
            size++;
        } else {
            cout << "Out of range" << endl;
        }
    }
    tn PopB(){ //извлечение из начала
        tn result = array[0]; //для того, чтобы сделать проверку на то, существует ли элемент в списке, нужно знать исключения
        for (int i = 0; i < size - 1; i++) {
            array[i] = array[i + 1];
        }
        size--;
        return result;
    }
    tn PopE(){ //извлечение из конца
        size--;
        return array[size];
    }
    tn PopByIndex(int n){
        tn result = array[n];
        for (int i = n; i < size-1; i++){
            array[i] = array[i+1];
        }
        size--;
        return result;
    }
    tn get(int n){
        return array[n];
    }
    int find (tn value){ //если элемент не найден, то возращается -1
        int iter = -1;
        for (int i = 0; i < size; ++i){
            if (array[i] == value){
                iter = i;
            }
        }
        return iter;
    }
};
int main() {
    //для работы пользовательского типа данных, для него нужно перегрузить оператор ==
    list<int> MyList;
    MyList.constructor(4);
    MyList.push(4);
    MyList.push(5);
    MyList.PushByIndex(1,8);
    MyList.push(7);
    cout << MyList.find(5) << endl;
    cout << MyList.find(9) << endl;
    MyList.print();
    cout << MyList.get(2) << endl;
    cout << MyList.PopB() << endl;
    MyList.print();
    cout << MyList.PopE() << endl;
    MyList.print();
    cout << MyList.PopByIndex(1) << endl;
    MyList.print();
    MyList.destructor();
    MyList.print();
    return 0;
}
