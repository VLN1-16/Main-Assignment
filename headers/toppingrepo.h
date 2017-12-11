#ifndef TOPPINGREPO_H
#define TOPPINGREPO_H

#define toppingfile "data/toppings.dat"

class ToppingRepo{
    public:
        ToppingRepo();
        ~ToppingRepo();
        void AddTopping(Topping topping);
        void GetToppings(std::ostream &os);
        void RemoveTopping(int index);
    private:
        FileHandler<Topping>* toppinglist;

};

#endif
