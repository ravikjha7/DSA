template<typename T>
class vector{
    // Data Members
    T *arr;
    int cs,ms;

    public : 
    // Constructor
    vector(int cap=1){
        cs = 0;
        ms = cap;
        arr = new T[ms];
    }

    // Destructor
    ~vector(){
    }

    // Methods
    void push_back(const T n)
    {
        if(cs==ms){
            ms *= 2;
            T *oldarr = arr;
            // Creating a new array of twice the capacity
            arr = new T[ms];
            for(int i=0;i<cs;i++) arr[i] = oldarr[i];
            delete [] oldarr;
        }
        arr[cs] = n;
        cs++;
    }

    // Just shift the size pointer one backwards
    void pop_back()
    {
        if(cs!=0) cs--;
    }

    // Just check if size == 0
    bool isEmpty () const{
        return cs==0;
    }

    // Print the first element of Array
    T front () const{
        if(cs!=0) return arr[0];
    }

    // Print The Last Element Of The Array
    T back() const{
        if(cs!=0) return arr[cs-1];
    }

    // Print The Element at ith position
    T At(const int i) const{
        if(i<cs) return arr[i];
    }

    // Prints Size Of The Vector
    int size() const{
        return cs;
    }

    // Prints Capacity Of The Vector
    int capacity() const{
        return ms;
    }

    //Operator Overloading
    T operator[](const int i) const{
        return arr[i];
    }
};