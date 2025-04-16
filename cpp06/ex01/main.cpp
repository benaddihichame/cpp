#include "Serializer.hpp"

int main()
{
    Data originalData;
    originalData.name = "hichame";
    originalData.age = 24;
    
    Data *originalPtr = &originalData;
    std::cout << "Pointeur original: " << originalPtr << " (0x" << std::hex << reinterpret_cast<uintptr_t>(originalPtr) << std::dec << ")" << std::endl;
    
    uintptr_t serializedValue = Serializer::serialize(originalPtr);
    std::cout << "Valeur sérialisée: " << serializedValue << std::endl;
    
    Data *reconstructedPtr = Serializer::deserialize(serializedValue);
    std::cout << "Pointeur reconstruit: " << reconstructedPtr << std::endl;
    
    if (originalPtr == reconstructedPtr)
    {
        std::cout << "Sérialisation réussie!" << std::endl;
        std::cout << "Données: " << reconstructedPtr->name << ", " << reconstructedPtr->age << std::endl;
    }
    else
        std::cout << "Sérialisation échouée!" << std::endl;
    
    return 0;
}