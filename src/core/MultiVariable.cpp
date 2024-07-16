#ifdef __cplusplus

    #include "MultiVariable.h" 

//------------------------------------------------------------------
// Setter Block
//------------------------------------------------------------------


MultiVariable* createNewVariable (){
    MultiVariable* obj = (MultiVariable*)malloc(sizeof(MultiVariable));
    if(obj){
        obj->type = MultiVariableType::NULL_TYPE;

        obj->setInteger = setInteger;
        obj->setUinteger = setUInteger;
        obj->setChar = setChar;
        obj->setCharArr = setCharArr;
        obj->setBool = setBool;
        obj->setNull = setNull;

        obj->setInteger_ptr = setInteger_ptr;
        obj->setUinteger_ptr = setUinteger_ptr;
        obj->setFloat_ptr = setFloat_ptr;
        obj->setBool_ptr = setBool_ptr;
        obj->setString_ptr = setString_ptr;


        obj->getInteger = getInteger;
        obj->getUinteger = getUInteger;
        obj->getChar = getChar;
        obj->getCharArr = getCharArr;
        obj->getBool = getBool;
        obj->getString = getString;
        obj->getType = getType;

        obj->destructor = MultiVarDestructor;

        return obj;
        
    }
    return NULL;
}




STATUS_t setInteger  (MultiVariable* multiVar, int val){
    if(multiVar){
        multiVar->type = MultiVariableType::INTEGER;
        multiVar->valuer.intVal = val;

        return STATUS_OK;
    }else{
        return NOT_FOUND;
    }
}

STATUS_t setUInteger  (MultiVariable* multiVar, unsigned int val){
    if(multiVar){
        multiVar->type = MultiVariableType::UINTEGER;
        multiVar->valuer.intValU = val;

        return STATUS_OK;
    }else{
        return NOT_FOUND;
    }
}

STATUS_t setFloat    (MultiVariable* multiVar, float val){
    if(multiVar){
        multiVar->type = MultiVariableType::FLOAT;
        multiVar->valuer.floatVal = val;

        return STATUS_OK;
    }else{
        return NOT_FOUND;
    }
}

STATUS_t setChar     (MultiVariable* multiVar, char val){
    if(multiVar){
        multiVar->type = MultiVariableType::CHAR;
        multiVar->valuer.charOneVal = val;

        return STATUS_OK;
    }else{
        return NOT_FOUND;
    }
}

STATUS_t setCharArr  (MultiVariable* multiVar, char* val){
    if(multiVar){
        multiVar->type = MultiVariableType::CHAR_ARR;
        multiVar->valuer.charArrVal = val;

        return STATUS_OK;
    }else{
        return NOT_FOUND;
    }
}

STATUS_t setBool     (MultiVariable* multiVar, bool val){
    if(multiVar){
        multiVar->type = MultiVariableType::BOOL;
        multiVar->valuer.boolVal = val;

        return STATUS_OK;
    }else{
        return NOT_FOUND;
    }
}


STATUS_t setNull     (MultiVariable* multiVar){
    if(multiVar){
        multiVar->type = MultiVariableType::NULL_TYPE;
        return STATUS_OK;
    }else{
        return NOT_FOUND;
    }
}

STATUS_t setInteger_ptr  (MultiVariable* multiVar, int* val){
    if(multiVar && val){
        multiVar->type = MultiVariableType::INTEGER_PTR;
        multiVar->valuer.intVal_Ptr = val;
        return STATUS_OK;
    }else return NOT_FOUND;
}

STATUS_t setUinteger_ptr (MultiVariable* multiVar, unsigned int* val){
    if(multiVar && val){
        multiVar->type = MultiVariableType::UINTEGER_PTR;
        multiVar->valuer.intValU_Ptr = val;
        return STATUS_OK;
    }else return NOT_FOUND;
}
STATUS_t setFloat_ptr    (MultiVariable* multiVar, float* val){
    if(multiVar && val){
        multiVar->type = MultiVariableType::FLOAT_PTR;
        multiVar->valuer.floatVal_Ptr = val;
        return STATUS_OK;
    }else return NOT_FOUND;
}
STATUS_t setBool_ptr     (MultiVariable* multiVar, bool* val){
    if(multiVar && val){
        multiVar->type = MultiVariableType::BOOL_PTR;
        multiVar->valuer.boolVal_Ptr = val;
        return STATUS_OK;
    }else return NOT_FOUND;
}
STATUS_t setString_ptr   (MultiVariable* multiVar, String* val){
    if(multiVar && val){
        multiVar->type = MultiVariableType::STRING_PTR;
        multiVar->valuer.stringVal_Ptr = val;
        return STATUS_OK;
    }else return NOT_FOUND;
}


//------------------------------------------------------------------
//Getter Block
//------------------------------------------------------------------

MultiVariableType getType(MultiVariable* multiVar){
    if(multiVar){
        return multiVar->type;
    }else return NULL_TYPE;
}

int getInteger(MultiVariable* multiVar){
    if(multiVar && multiVar->type == MultiVariableType::INTEGER){
        return multiVar->valuer.intVal;
    }else if(multiVar && multiVar->type == MultiVariableType::INTEGER_PTR){
        return *(multiVar->valuer.intVal_Ptr);
    }
    return 0;
}
unsigned int getUInteger(MultiVariable* multiVar){
    if(multiVar && multiVar->type == MultiVariableType::UINTEGER){
        return multiVar->valuer.intValU;
    }else if(multiVar && multiVar->type == MultiVariableType::UINTEGER_PTR){
        return *(multiVar->valuer.intValU_Ptr);
    }
    return 0;
}
float getFloat(MultiVariable* multiVar){
    if(multiVar && multiVar->type == MultiVariableType::FLOAT){
        return multiVar->valuer.floatVal;
    }else if(multiVar && multiVar->type == MultiVariableType::FLOAT_PTR){
        return *(multiVar->valuer.floatVal_Ptr);
    }
    return 0;
}
char getChar(MultiVariable* multiVar){
    if(multiVar && multiVar->type == MultiVariableType::CHAR){
        return multiVar->valuer.charOneVal;
    }
    return '\0';
}
char* getCharArr(MultiVariable* multiVar){
    if(multiVar && multiVar->type == MultiVariableType::CHAR_ARR){
        return multiVar->valuer.charArrVal;
    }
    return NULL;
}

bool getBool(MultiVariable* multiVar){
    if(multiVar && multiVar->type == MultiVariableType::BOOL){
        return multiVar->valuer.boolVal;
    }else if(multiVar && multiVar->type == MultiVariableType::BOOL_PTR){
        return *(multiVar->valuer.boolVal_Ptr);
    }
    return false;
}
String getString(MultiVariable* multiVar){
        if(multiVar && multiVar->type == MultiVariableType::STRING){
        return multiVar->valuer.stringVal;
    }else if(multiVar && multiVar->type == MultiVariableType::STRING_PTR){
        return *(multiVar->valuer.stringVal_Ptr);
    }
    return "";
}


STATUS_t MultiVarDestructor(MultiVariable* multiVar){
    if(multiVar){
        free(multiVar);
        return STATUS_OK;
    }
    return NOT_FOUND;
}

#endif