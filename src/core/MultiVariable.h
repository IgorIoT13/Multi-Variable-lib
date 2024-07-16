#ifndef MULVAR_H
#define MULVAR_H

#include "../Setting.h"

//##################################################################
// Enums, unions Blocks
//##################################################################

/**
 * @brief Accepts all types of data that the menu works with. Required for convenience of work.
 */
typedef union MultiVariableMemory{

    int     intVal;         ///< Standart integer
    unsigned int intValU;   ///< Unsigned iteger 
    float   floatVal;       ///< Float variable
    char    charOneVal;     ///< One Char Symphol
    char*   charArrVal;     ///< Char array (need for C)

    
    CPPCODE(// Cpp fragment
        bool        boolVal;    ///< Bool variable
        String      stringVal;  ///< Standart String for text
    )

    //ptr

    int*     intVal_Ptr;         ///< Standart integer(ptr)
    unsigned int* intValU_Ptr;   ///< Unsigned iteger (ptr)
    float*   floatVal_Ptr;       ///< Float variable (ptr)

    
    CPPCODE(// Cpp fragment
        bool*        boolVal_Ptr;    ///< Bool variable
        String*      stringVal_Ptr;  ///< Standart String for text
    )

}MultiVariableMemory;

/**
 * @brief The type of variable in memory. Need to work correctly and know what type it is now.
 */
typedef enum MultiVariableType{
    INTEGER,    ///< Standart int
    UINTEGER,   ///< Unsigned int
    FLOAT,      ///< Float type
    CHAR,       ///< One Syphol
    CHAR_ARR,   ///< Char array
    BOOL,       ///< Boolean type
    STRING,     ///< String (text c++)
    NULL_TYPE,  ///< Null type or valuer is empty
    INTEGER_PTR,    ///< Standart int (ptr)
    UINTEGER_PTR,   ///< Unsigned int (ptr)
    FLOAT_PTR,      ///< Float type (ptr)
    BOOL_PTR,       ///< Boolean type (ptr)
    STRING_PTR,     ///< String (text c++)(ptr)


}MultiVariableType;

//##################################################################
// Structs Blocks
//##################################################################


/**
 * @brief This struct is manager, some thing such as interface.
 *  Do all manipulation with MultiVariableMemory and MultiVariableType to more easy work with multi variable.
 */
typedef struct MultiVariable{

    //__________________________________________________________________
    //Variable
    //__________________________________________________________________

    MultiVariableMemory valuer; ///< Multi Variable
    MultiVariableType type; ///< Type variable 


    //__________________________________________________________________
    //Setter
    //__________________________________________________________________


    //C
    
    STATUS_t (*setInteger)  (MultiVariable* multiVar, int val);
    STATUS_t (*setUinteger) (MultiVariable* multiVar, unsigned int val);
    STATUS_t (*setFloat)    (MultiVariable* multiVar, float val);
    STATUS_t (*setChar)     (MultiVariable* multiVar, char val);
    STATUS_t (*setCharArr)  (MultiVariable* multiVar, char* val);
    STATUS_t (*setNull)     (MultiVariable* multiVar);

    //Cpp

    CPPCODE(
        STATUS_t (*setBool)     (MultiVariable* multiVar, bool val);
        //Ptr
        STATUS_t (*setBool_ptr)     (MultiVariable* multiVar, bool* val);
        STATUS_t (*setString_ptr)   (MultiVariable* multiVar, String* val);
    )

    STATUS_t (*setInteger_ptr)  (MultiVariable* multiVar, int* val);
    STATUS_t (*setUinteger_ptr) (MultiVariable* multiVar, unsigned int* val);
    STATUS_t (*setFloat_ptr)    (MultiVariable* multiVar, float* val);

    
    //__________________________________________________________________
    //Getter
    //__________________________________________________________________


    //C

    MultiVariableType (*getType)   (MultiVariable* multiVar);

    int             (*getInteger)  (MultiVariable* multiVar);
    unsigned int    (*getUinteger) (MultiVariable* multiVar);
    float           (*getFloat)    (MultiVariable* multiVar);
    char            (*getChar)     (MultiVariable* multiVar);
    char*           (*getCharArr)  (MultiVariable* multiVar);

    //Cpp

    CPPCODE(
        bool    (*getBool)     (MultiVariable* multiVar);
        String  (*getString)   (MultiVariable* multiVar);
    )

    

    //__________________________________________________________________
    //Destructor function
    //__________________________________________________________________


    /**
     * @brief Free memory, destroy object
     * 
     * @param multiVar pointer on struct MultiVariable
     * 
     * @return Status code 
     */
    STATUS_t (*destructor)  (MultiVariable* multiVar); /// < destructor




}MultiVariable;

//------------------------------------------------------------------
// Function Block
//------------------------------------------------------------------

/**
 * @brief Create new object MultiVariable
 * 
 * Need to corectly create object and and assign all methods to it.
 *  
 * @return if all sucsessful pointe on new object
 * 
 * @warning May return NULL if memory allocation was incorrect  
 */
MultiVariable* createNewVariable ();

    //__________________________________________________________________
    //Setter fuctions
    //__________________________________________________________________

    //C
STATUS_t setInteger  (MultiVariable* multiVar, int val);
STATUS_t setUInteger (MultiVariable* multiVar, unsigned int val);
STATUS_t setFloat    (MultiVariable* multiVar, float val);
STATUS_t setChar     (MultiVariable* multiVar, char val);
STATUS_t setCharArr  (MultiVariable* multiVar, char* val);
STATUS_t setNull     (MultiVariable* multiVar);
    //Cpp
CPPCODE(
    STATUS_t setBool     (MultiVariable* multiVar, bool val);
    //Ptr
    STATUS_t setBool_ptr     (MultiVariable* multiVar, bool* val);
    STATUS_t setString_ptr   (MultiVariable* multiVar, String* val);
)
    
    STATUS_t setInteger_ptr  (MultiVariable* multiVar, int* val);
    STATUS_t setUinteger_ptr (MultiVariable* multiVar, unsigned int* val);
    STATUS_t setFloat_ptr    (MultiVariable* multiVar, float* val);


    //__________________________________________________________________
    //Getter functions
    //__________________________________________________________________


    //C
int             getInteger  (MultiVariable* multiVar);
unsigned int    getUInteger (MultiVariable* multiVar);
float           getFloat    (MultiVariable* multiVar);
char            getChar     (MultiVariable* multiVar);
char*           getCharArr  (MultiVariable* multiVar);

MultiVariableType getType     (MultiVariable* multiVar);
    //Cpp
CPPCODE(
    bool    getBool     (MultiVariable* multiVar);
    String  getString   (MultiVariable* multiVar);

)

    //__________________________________________________________________
    //Destructor
    //__________________________________________________________________
/**
 * @brief Delete MultiVariable struct
 * @note Use MultiVariable destructor better that use this fuction
 */
STATUS_t MultiVarDestructor(MultiVariable* multiVar);



#endif