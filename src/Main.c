#if defined(__linux__)
#include "/home/codeleaded/System/Static/Container/Hashmap.h"
#elif defined(_WINE)
#include "/home/codeleaded/System/Static/Container/Hashmap.h"
#elif defined(_WIN32)
#include "F:/home/codeleaded/System/Static/Container/Hashmap.h"
#elif defined(__APPLE__)
#error "Apple not supported!"
#else
#error "Platform not supported!"
#endif

Hashmap_Hash CStr_Hash_Simple(int Max,unsigned int KEY_SIZE,void* Hash){
    char* const cstr = *(char**)Hash;
    return CStr_SimpleHash(cstr) % Max;
}
char CStr_Hash_CmpKeys(unsigned int KEY1_SIZE,void* Key1,unsigned int KEY2_SIZE,void* Key2){
    char* const cstr1 = *(char**)Key1;
    char* const cstr2 = *(char**)Key2;
    return CStr_Cmp(cstr1,cstr2);
}

void Pair_PrintCStr(Pair* p){
    if(p && p->Data)
        printf("(%s,%d)",*((char**)Pair_First(p)),*((int*)Pair_Second(p)));
}
void Pair_FreeKey(Pair* p){
    free(*(char**)(Pair_First(p)));
}

int main(){
    Hashmap hmap = Hashmap_Make(
        10,
        CStr_Hash_Simple,
        CStr_Hash_CmpKeys,
        Pair_FreeKey,
        Pair_PrintCStr
    );

    Hashmap_Add(&hmap,8,(char*[]){ CStr_Cpy("First")    },4,(int[]){ 1 });
    Hashmap_Add(&hmap,8,(char*[]){ CStr_Cpy("Second")   },4,(int[]){ 2 });
    Hashmap_Add(&hmap,8,(char*[]){ CStr_Cpy("Third")    },4,(int[]){ 3 });
    Hashmap_Add(&hmap,8,(char*[]){ CStr_Cpy("Fourth")   },4,(int[]){ 4 });
    Hashmap_Add(&hmap,8,(char*[]){ CStr_Cpy("Fivth")    },4,(int[]){ 5 });

    Hashmap_Print(&hmap);
    
    Hashmap_Remove(&hmap,sizeof(char*),(char*[]){ "Fourth" });
    Hashmap_Remove(&hmap,sizeof(char*),(char*[]){ "Fivth" });

    void* Found = Hashmap_Find(&hmap,sizeof(char*),(char*[]){ "Third" });
    if(Found)   printf("Found: %d\n",*(int*)Found);
    else        printf("Not Found!\n");
    
    Hashmap_Add(&hmap,8,(char*[]){ CStr_Cpy("Sixth")    },4,(int[]){ 6 });
    Hashmap_Add(&hmap,8,(char*[]){ CStr_Cpy("Seventh")  },4,(int[]){ 7 });

    Hashmap_Print(&hmap);

    Hashmap_Free(&hmap);

    return 0;
}