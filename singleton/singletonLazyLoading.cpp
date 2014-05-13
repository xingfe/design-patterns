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
 
 //Example
 std::cout << Singleton::getInstance().method();