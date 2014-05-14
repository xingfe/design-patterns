 class Singleton
 {
  private:
        Singleton() {}
        Singleton(const singleton &);
        Singleton& operator=(const Singleton&);
        ~Singleton() {}
  public:
        std::string method() { return "singleton pattern"; }
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