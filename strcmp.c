int strcmp_SELFMADE (char *first, char *second){
//    while (*first || *second){
//        return ((*first < *second)? -1 : ((*first == *second)? 0 : 1));
//    }
    for( ; *first == *second; first++, second++)
        if(*first == '\0')
            return 0;
    return *first - *second;
}