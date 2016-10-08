#include <iostream>
#include <string>
#include <sstream>

#define ISINT true
#define NOTINT false

using namespace std;

class inputNode
{
    private:
        inputNode *next;
        int value;
        char op;
        bool flag;
        
    public:
        inputNode() {next = NULL; value = 0; op = ' '; flag = false;}
        inputNode(int i, char c, bool isInt);
        ~inputNode(); //TODO write this
        void setNext(inputNode* n) {next = n;}
        inputNode* getNext() {return next;}
        bool hasInt() {return flag;}
        char getChar() {return op;}
        void setChar(char c) {op = c; flag = false;}
        int getInt() {return value;}
        void setInt(int i) {value = i; flag = true;}
};

inputNode::inputNode(int i, char c, bool isInt)
{
    if(isInt)
    {
        value = i;
        op = ' ';
    }
    else
    {
        op = c;
        value = 0;
    }
    
    flag = isInt;
}

class nodeList
{
    private:
        inputNode* head,* tail;
        
    public:
        nodeList() {head = NULL; tail = NULL;}
        nodeList(inputNode* h) {head = h; tail = h;}
        ~nodeList(); //TODO write this
        inputNode* getHead() {return head;}
        void setHead(inputNode* h) {head = h;}
        inputNode* getTail() {return tail;}
        void setTail(inputNode* t) {tail = t;}
        void addNode(inputNode* i);
        
};

void nodeList::addNode(inputNode* i)
{
    if (head == NULL)
    {
        head = i;
        tail = i;
    }
    else
    {
        tail->setNext(i);
        tail = tail->getNext();
    }
}

nodeList* tokenizeString(string s)
{
    int counter = 0;
    int value;
    int maxIndex = s.length();
    string section;
    nodeList* toReturn;
    inputNode* toAdd;
    
    while(s.length() > 0)
    {
        while(counter + 1 < s.length() && s[counter] != ' ')
        {
            counter++;
        }
        
        section = s.substr(0, counter - 1);
        
        switch(section[0])
        {
            case '+':
            case '*':
            case '/':
                //TODO maybe throw error?
                //check for faulty input
                toAdd = new inputNode(0, section[0], NOTINT);
                break;
            
            case '-':
                if(section.length() > 2)
                {
                    //Case of faulty input or negative number
                    istringstream buffer(section);
                    buffer >> value;
                    toAdd = new inputNode(value , ' ', ISINT);
                }
                else
                {
                    toAdd = new inputNode(0, section[0], NOTINT);
                }
                break;
                
            default:
                //Throw exception
                break;
        }
                
    }
}

int main()
{
    string input;
    
    cout << "Please enter an inline mathematical expression: " << endl;
}
