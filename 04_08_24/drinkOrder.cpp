#include "drinkOrder.h"

order::order()
{
    numDrinks = 0;
    drinks = new drink *[numDrinks + 1];
    drinks[0] = nullptr;
}

void order::addDrink(drink &d)
{
    drinks[numDrinks] = new drink(d);
    drink **dcpy;
    dcpy = drinks;
    drinks = new drink *[++numDrinks + 1];
    for (int i = 0; i < numDrinks; i++)
    {
        drinks[i] = dcpy[i];
    }
    delete[] dcpy;
}

void order::addDrinks(drink **d, int numD)
{
    int oldNum = numDrinks;
    numDrinks += numD;
    drink **dcpy;
    dcpy = drinks;
    drinks = new drink *[numDrinks + 1];
    for (int i = 0; i < oldNum; i++)
    {
        drinks[i] = dcpy[i];
    }
    int j = 0;
    for (int i = oldNum; i < numDrinks; i++)
    {
        drinks[i] = new drink(*d[j++]);
    }
}

order::order(const order &otherOrder)
{
    this->numDrinks = otherOrder.numDrinks;
    this->drinks = new drink *[this->numDrinks + 1];
    for (int i = 0; i < numDrinks; i++)
    {
        this->drinks[i] = new drink(*(otherOrder.drinks[i]));
    }
}

order::~order()
{
    for (int i = 0; i < numDrinks; i++)
    {
        delete drinks[i];
    }
    delete[] drinks;
}

std::string order::tostring() const
{
    std::ostringstream out;
    out << "This order has " << numDrinks << " drinks:" << std::endl;
    for (int i = 0; i < numDrinks; i++)
    {
        out << drinks[i]->tostring() << std::endl;
        out << std::setw(25) << std::setfill('-') << "-" << std::endl;
    }
    return out.str();
}
