typedef struct s_block *t_block;

struct s_block {
    size_t size;
    t_block next;
    int free;
};


t_block find_block(t_block *last, size_t size) {
    t_block b = base;
    while (b && !(b->free && b->size >= size)) {
        *last = b;
        b = b->next;
    }
    return (b);
}
