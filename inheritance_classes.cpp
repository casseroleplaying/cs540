// exercise: classes and inheritance in C++
// program for managing restaurant inventory of fresh ingredients 

#include <iostream>
#include <string>
using namespace std;

class I_Item {                          // interface class
    public:
        virtual void printInfo() const = 0;
};

class Ingredient : public I_Item {      // abstract class - cannot instantiate
    protected:
        int m_quantity;
        double m_weight;
        string m_expiry;
        static int m_ingredient_count;
        char m_vendorID;
    public:
        Ingredient(int quantity = 0, double weight = 0.0)
            :m_quantity(quantity), m_weight(weight)
        {
            cout << "Created Ingredient item to inventory." << endl;
            m_ingredient_count++;
        }
        ~Ingredient()
        {
            cout << "Ingredient removed from inventory, count updated." << endl;
            m_ingredient_count--;
        }
        virtual int getQuantity() const = 0;
        virtual double getWeight() const = 0;
        string getExpiry() const { return m_expiry; }
        virtual char getVendorID() const final { return m_vendorID; }
        void setQuantity(int quantity) { m_quantity = quantity; }
        void setWeight(double weight) { m_weight = weight; }
        void setExpiry(string expiry) { m_expiry = expiry; }
        virtual void setVendorID(char vendor) final { m_vendorID = vendor; }
        void printInfo() const
        {
            cout << "Ingredient quantity: " << m_quantity << endl;
            cout << "Ingredient weight: " << m_weight << endl;
        }
};

class HACCP_ID {
    private:
        int m_safety_code;
        char m_risk_level;
        static int m_HACCP_count;
    public:
        HACCP_ID(int safety_code = 1, char risk_level = 'A')
            :m_safety_code(safety_code), m_risk_level(risk_level)
        {
            cout << "HACCP critical food item entered to inventory." << endl;
            m_HACCP_count++;
        }
        ~HACCP_ID()
        {
            cout << "HACCP critical food item removed from inventory." << endl;
            m_HACCP_count--;
        }
        
};

class Protein : public Ingredient, public HACCP_ID {
    private:
        double m_date;                  // date item received in format MM.DD
        int m_portion;                  // portion size in grams
        static int m_protein_count;
    public:
        Protein(int quantity = 0, double weight = 0.0, double date = 01.01, 
                int portion = 125)
            :Ingredient(quantity, weight), m_date(date), m_portion(portion)    
        {
            cout << "Created Protein item to inventory." << endl;
            m_protein_count++;
        }
        ~Protein()
        {
            cout << "Protein removed from inventory, count updated." << endl;
            m_protein_count--;
        }
        int getQuantity() const { return m_quantity; }
        double getWeight() const { return m_weight; }
        double getDate() const { return m_date; }
        int getPortion() const { return m_portion; }
        string getExpiry() const = delete;
        void setDate(double date) { m_date = date; }
        void setPortion(int portion) { m_portion = portion; }
        void setExpiry(string expiry) = delete;
        void printInfo() const
        {
            cout << "Protein date: " << m_date << endl;
            cout << "Protein portion: " << m_portion << 'g' << endl; 
        }
};

class Meat : public Protein {
    private:
        char m_animal_type;         // type of animal derived from 
        char m_cut_type;            // type of cut from the body
        static int m_meat_count;
    public:
        Meat(int quantity = 0, double weight = 0.0, double date = 01.01, 
             int portion = 125, char animal_type = 'C', char cut_type = 'P')
            :Protein(quantity, weight, date, portion), 
             m_animal_type(animal_type), m_cut_type(cut_type)
        {
            cout << "Created Meat item to inventory." << endl;
            m_meat_count++;
        }
        ~Meat()
        {
            cout << "Meat removed from inventory, count updated." << endl;
            m_meat_count--;
        }
        char getAnimalType() const { return m_animal_type; }
        char getCutType() const { return m_cut_type; }
        void setAnimalType(char animal_type) { m_animal_type = animal_type; }
        void setCutType(char cut_type) { m_cut_type = cut_type; }
        void printInfo() const
        {
            cout << "Meat animal type: " << m_animal_type << endl;
            cout << "Meat cut type: " << m_cut_type << endl;
        }
};

class Fish : public Protein {
    private:
        string m_species;           // seafood species
        char m_processed;           // state of processing (whole or broken)
        static int m_fish_count;
    public:
        Fish(int quantity = 0, double weight = 0.0, double date = 01.01, 
             int portion = 125, string species = "default", 
             char processed = 'W')
            :Protein(quantity, weight, date, portion), 
             m_species(species), m_processed(processed)
        {
            cout << "Created Fish item to inventory." << endl;
            m_fish_count++;
        }
        ~Fish()
        {
            cout << "Fish removed from inventory, count updated." << endl;
            m_fish_count--;
        }
        string getSpecies() const { return m_species; }
        char getProcessed() const { return m_processed; }
        void setSpecies(string species) { m_species = species; }
        void setProcessed(char processed) { m_processed = processed; }
        void printInfo() const
        { 
            cout << "Fish species: " << m_species << endl;
            cout << "Fish state of processing: " << m_processed << endl;
        }
};

int Ingredient::m_ingredient_count = 0;     // initialilze object counters
int HACCP_ID::m_HACCP_count = 0;
int Protein::m_protein_count = 0;
int Meat::m_meat_count = 0;
int Fish::m_fish_count = 0;

int main(void)
{                        
    Protein p1;                             // create objects of each class
    Meat m1;
    Fish f1;
    
    Protein *pp1 = new Protein;             // create pointers to new objects
    Meat *mp1 = new Meat;
    
    Protein *pp2 = mp1;                     // assign child to parent pointer
    Meat *mp2 = static_cast<Meat *>(pp2);   // assign parent to child pointer
    
    Protein &pRef = p1;                     // create reference object
    pRef.setPortion(90);                    // use ref var to change value
    cout << "p1 portion: " << p1.getPortion() << "g." << endl;
    
    p1.printInfo();                         // call over-riding functions
    m1.printInfo();
    f1.printInfo();
        
    //system("pause");
    return 0;
}      
