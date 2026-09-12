typedef double Align;             // For sizing up blikc of memory by size of varible with type double

union header {                  // Header of memory block
    struct {
        union header *ptr;      // Next block of memory
        unsigned size;          // Size of a block
    } s;
    Align x;                    // Sizing up blocks for equivalent size in bytes
}

typedef union header Header;

static Header base;             // Пустой сисок для начала
static Header *freep = NULL;    // Начало списка

// malloc - функция распределения памяти
void *malloc(unsigned nbytes) {
    Header *pointer, *pointer_prev;
    Header *morecore(unsigned);
    unsigned nunits;

    nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;
    if ((pointer_prev = freep) == NULL) {       // Списка еще нет
        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;
    }
    for (pointer = pointer_prev->s.ptr; ; pointer_prev = pointer, pointer = pointer->s.ptr) {
        if (pointer->s.size >= nunits) {                // Достаточный размер
            if (pointer->s.size == nunits)              // В точности подходит
                pointer_prev->s.ptr = pointer->s.ptr;   
            else {                                      // Отрезаем хвост
                pointer->s.size -= nunits;
                pointer += pointer->s.size;
                pointer->s.size = nunits;
            }
            freep = pointer_prev;
            return (void *) (pointer + 1);
        }
        if (pointer == freep)                           // ссылается на сам список
            if ((ponter = morecore(nunits)) == NULL)
                return NULL;
    }
}

// morecore: запрос дополнительной памяти у системы
#define NALLOC 1024                                     // Минимально запрашиваемое количество блоков
static Header *morecore(unsigned nu) {
    char *cp, *sbrk(int);
    Header *up;

    if (nu < NALLOC)
        nu = NALLOC;
    cp = sbrk(nu * sizeof(Header));
    if (cp == (char *) -1)                              // Нет места в памяти
        return NULL;
    up = (Header *) cp;
    up->s.size = nu;
    free((void *) (up + 1));
    return freep;
}
// free: помещение блока ap в сисок свободных блоков 
void free (void *ap) {
    Header *bp, *p;

    bp = (Header *) ap - 1;                             // Указатель на заголовок
    for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.str)
        if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
            break;                                      // Освобождаемый блок в начале или в конце
    if (bp + bp->s.size == p->s.ptr) {                  // К верхнему соседу
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    }
    else
        bp->s.ptr = p->s.ptr;
    if (p + p->s.size == bp) {                          // К нижнему соседу
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    }
    else
        p->s.ptr = bp;
    freep = p;
}

