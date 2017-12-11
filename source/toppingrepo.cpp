#include "toppingrepo.h"
ToppingRepo::ToppingRepo(){
    toppinglist = new FileHandler<Topping>(toppingfile);
}
ToppingRepo::~ToppingRepo(){

}
void ToppingRepo::AddTopping(Topping topping);
void ToppingRepo::GetToppings(std::ostream &os);
void ToppingRepo::RemoveTopping(int index);
