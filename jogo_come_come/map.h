struct map {
    char** matriz;

    int lines;
    int columns;
};

typedef struct map MAP;

struct userPosition{
    int x;
    int y;
};

typedef struct userPosition position;


void readMap(MAP* m);
void alocatteMap(MAP* m);
void freeMap(MAP* m);
void printMap(MAP* m);
void findMap(MAP* m, position* p, char c);
