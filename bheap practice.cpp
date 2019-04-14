#include<iostream>
using namespace std;

class BH{
    public:

     //pointer to the elements of the array
    int*harr;
    //maximum size of the array
    int msize;
    //current numnber of the elements
    int csize;
    //constructor
    //input is the maximum capacity of the array??
    //and what do we mean by new int[];
    BH(int msize){
        harr = new int[msize];
        this->msize = msize;
        csize = 0;
    }

    int parent(int i){return (i-1)/2 ;}
    int left(int i){return 2*i + 1;}
    int right(int i){return 2*(i+1)+1;}

    void Insert(int x){
        if(csize >= msize){
            cout<<" You've exceeded the array size" <<endl;
        }
        else{
            harr[csize] = x;
            int l = csize;
            csize++;
            while(harr[parent(l)] > harr[l]){
                int temp = harr[parent(l)];
                harr[parent(l)] = harr[l];
                harr[l] = temp;
                l = parent(l);
            }
        }
    }

    //finding the minimum element
    int getmin(){ return harr[0]; }
    int extractmin(){
        int g = getmin();
        for(int i=0;i<csize;i++) harr[i-1] = harr[i];
        csize--;
        return g;
    }
    void display(){
        for(int i=0;i<csize;i++)cout<< harr[i] <<",";
        cout<<endl;
    };

    void deckey(int l, int x){
        int n = l;
        harr[n] = x;
        while(harr[parent(n)] > harr[n]){
                int temp = harr[parent(n)];
                harr[parent(n)] = harr[n];
                harr[n] = temp;
                n = parent(n);
        }
    }
    void Deleteat(int a){
        for(int i=a;i<csize;i++) harr[i-1] = harr[i];
        csize--;
    }

};

int main(){
    int m;
    cout<< "Please enter the sizeof the array " <<endl;
    cin>> m;
    BH pullu(m);

    pullu.Insert(45);
    pullu.Insert(50);
    pullu.Insert(40);
    pullu.Insert(36);
    pullu.Insert(42);
    pullu.Insert(53);
    pullu.display();

    cout<<"The minimum data is "<< pullu.getmin() <<endl;

    pullu.Deleteat(3);
    pullu.display();

    pullu.Insert(45);
    pullu.display();

    pullu.deckey(3,38);
    pullu.display();

    return 0;
}
