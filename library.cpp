#include "library.h"
#include "DSW.h"


void* Init() {
    DSW *DS;
    try {
        DS = new DSW();
    }
    catch (std::bad_alloc &) {
        return nullptr;
    }
    return (void *) DS;
}

StatusType AddCarType(void *DS, int typeID, int numOfModels){
    if(DS == NULL) return INVALID_INPUT;
    return (StatusType) ((DSW*)DS)->AddCarType(typeID, numOfModels);
}

StatusType RemoveCarType(void *DS, int typeID){
    if(DS == NULL) return INVALID_INPUT;
    return (StatusType) ((DSW*) DS)->RemoveCarType(typeID);
}

StatusType SellCar(void *DS, int typeID, int modelID){
    if(DS == NULL) return INVALID_INPUT;
    return (StatusType) ((DSW*) DS)->SellCar(typeID, modelID);
}

StatusType MakeComplaint(void* DS, int typeID, int modelID, int t){
    if(DS == NULL) return INVALID_INPUT;
    return (StatusType) ((DSW*) DS)->MakeComplaint(typeID, modelID, t);
}

StatusType GetBestSellerModelByType(void *DS, int typeID, int * modelID){
    if(DS == NULL) return INVALID_INPUT;
    return (StatusType) ((DSW*) DS)->GetBestSellerModelByType(typeID, modelID);
}

StatusType GetWorstModels(void *DS, int numOfModels, int *types, int *models){
    if(DS == NULL) return INVALID_INPUT;
    return (StatusType) ((DSW*) DS)->GetWorstModels(numOfModels, types, models);
}

void Quit(void** DS){
    if(*DS != NULL){
        delete ((DSW*) *DS);
    }
    *DS = NULL;
}






