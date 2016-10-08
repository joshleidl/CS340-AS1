#include <iostream>
#include <string>

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
        inputNode(int i) {next = NULL; value = i; op = ' '; flag = true;}
        inputNode(char c) {next = NULL; value = 0; op = c; flag = false;}
        void setNext(inputNode* n) {next = n;}
        inputNode* getNext() {return next;}
        bool hasInt() {return flag;}
        char getChar() {return op;}
        void setChar(char c) {op = c; flag = false;}
        int getInt() {return value;}
        void setInt(int i) {value = i; flag = true;}
};

class nodeList
{
    private:
        inputNode *head;
        
    public:
        nodeList() {head = NULL;}
        nodeList(inputNode* h) {head = h;}
        inputNode* getHead() {return head;}
        void setHead(inputNode* h) {head = h;}
};

inputNode* tokenizeString(string s)
{
    
}

int main()
{
    string input;
    
    cout << "Please enter an inline mathematical expression: " << endl;
}
