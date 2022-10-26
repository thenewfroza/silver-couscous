#include <iostream>

using namespace std;


struct fridge {
    int milk;
    int meat;
    int peace_of_cheese;
    int peace_of_cheesecake;
};

void show(fridge object){
    cout << " milk: " << object.milk << "\n";
    cout << " meat: " << object.meat << "\n";
    cout << " peace of cheese: " << object.peace_of_cheese << "\n";
    cout << " peace of cheesecake: " << object.peace_of_cheesecake << "\n";

}

int main() {
    fridge fridge1 = {1,2,4,12};
    fridge fridge2 = {0,1,2,6};


    fridge1.peace_of_cheesecake--;
    cout << "fridge1\n";
    cout << " milk: " << fridge1.milk << "\n";
    cout << " meat: " << fridge1.meat << "\n";
    cout << " peace of cheese: " << fridge1.peace_of_cheese << "\n";
    cout << " peace of cheesecake: " << fridge1.peace_of_cheesecake << "\n";


    fridge2.milk=+2;
    cout << "fridge2\n";
    cout << " milk: " << fridge2.milk << "\n";
    cout << " meat: " << fridge2.meat << "\n";
    cout << " peace of cheese: " << fridge2.peace_of_cheese << "\n";
    cout << " peace of cheesecake: " << fridge2.peace_of_cheesecake << "\n";


    struct fridge *fridge3;
    fridge3 = &fridge1;
    /////cout << &fridge1;
    fridge3->meat=fridge3->meat-1;
    fridge3->peace_of_cheesecake=fridge3->peace_of_cheesecake-10;
    cout << "fridge3\n";
    cout << " milk: " << fridge3 -> milk << "\n";
    cout << " meat: " << fridge3 -> meat << "\n";
    cout << " peace of cheese: " << fridge3 -> peace_of_cheese << "\n";
    cout << " peace of cheesecake: " << fridge3 -> peace_of_cheesecake << "\n";

    fridge fridge4 = fridge2;

    cout << "fridge4\n";
    show(fridge4);


    return 0;
}
