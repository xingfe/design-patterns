#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Node {
public:
  virtual void print(const string& pre) = 0;

};

class Directory : public Node{
  string name;
  vector<Node*> elements;
public:
  Directory(string s) : name(s) {}

  void add(Node* element) { elements.push_back(element); }
  void remove(Node* element) { 
      elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
    }
  Node* getChild(int index) { return elements[index]; }
  
  void print(const string& pre=" "){
      
    cout <<pre<<name << endl;
      vector<Node*>::iterator it;
      for (it = elements.begin(); it != elements.end(); ++it)
	(*it)->print(pre+" ");
  }
  
};
  

class File : public Node {
public:
  File(string s) : name(s) {}
  void print(const string & pre){
    cout<<pre<<name<<endl;
  }
private:
  string name;
};

int main(){
  Directory root("/");
  Directory usr("usr");
  Directory home("home");
  Directory dev("dev");
  File null("null");
  
  root.add(&usr);
  root.add(&dev);
  root.add(&home);
  dev.add(&null);
  
  root.print();
  
  return 0;
}
