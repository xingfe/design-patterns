 class Singleton
 {
  private:
        Singleton() {}
        Singleton(const singleton &);
        Singleton& operator=(const Singleton&);
        ~Singleton() {}
  public:
        std::string method() { return "singleton pattern"; }
	
	// Be carefull this method is thread safe only since C++11
	// (full suport). In other cases you should use thread 
	// synchronization objects but in that case if you 
        // want you're implementation eficient you should
	// synchronize only first call of the method.

        static Singleton& getInstance()
        {
          static Singleton instance;
          return instance;
        }
 };
 
int main()
{
	Singleton& s = Singleton::getInstance();
	std::cout << s.method() << endl;
	return 0;
}