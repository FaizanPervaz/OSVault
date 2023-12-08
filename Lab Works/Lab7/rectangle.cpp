#include<iostream>
#include<unistd.h>
#include<pthread.h>
using namespace std;

class Rectangle
{
    public:
        double length;
        double width;

        Rectangle(double l, double w)
        {
            length = l;
            width = w;
        }
        double getLength()
        {
            return length;
        }
        double getWidth()
        {
            return width;
        }
};

void* findArea(void* arg) 
{
    Rectangle* r = (Rectangle*)arg;
    double len = r->getLength();
    double wid = r->getWidth();
    cout << "Area of the rectangle: " << len * wid << endl;
    pthread_exit(NULL);

}
void* findperi(void* arg) 
{
    Rectangle* r = (Rectangle*)arg;

    double len = r->getLength();
    double wid = r->getWidth();
    cout << "Perimeter of the rectangle: " << 2*(len + wid) << endl;
    pthread_exit(NULL);

}

int main()
{
    double l,w;
    cout << "Enter length of the rectangle: ";
    cin >> l;
    cout << "Enter length of the rectangle: ";
    cin >> w;

    Rectangle r(l, w);

    pthread_t tid, tid2;

    pthread_create(&tid, NULL, findArea, &r);
    pthread_create(&tid2, NULL, findperi, &r);

    pthread_exit(NULL);
}