using namespace std;

template<typename T>
class node
{
public:

    T data;
    node * next;

    node(int d){
        next=NULL;
        data=d;
    }
};