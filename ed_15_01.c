#include <stdio.h>
#include <stdlib.h>

typedef enum {
    ATOM,
    LIST
} NodeType;

typedef struct node {
    NodeType type;
    union {
        int atom;
        struct node *list;
    } head;
    struct node *tail;
} node;

/* ======== CONSTRUÇÃO ======== */
node *new_atom(int v) {
    node *n = malloc(sizeof(node));
    n->type = ATOM;
    n->head.atom = v;
    n->tail = NULL;
    return n;
}

node *new_list(node *first) {
    node *n = malloc(sizeof(node));
    n->type = LIST;
    n->head.list = first;
    n->tail = NULL;
    return n;
}

node *append(node *head, node *elem) {
    if (!head) return elem;
    node *cur = head;
    while (cur->tail) cur = cur->tail;
    cur->tail = elem;
    return head;
}

/* ======== PARSER ======== */
void skip(char **s) {
    while (**s == ' ' || **s == '\n' || **s == '\t' || **s == '\r')
        (*s)++;
}

int parse_int(char **s) {
    skip(s);
    int sign = 1, v = 0;
    if (**s == '-') { sign = -1; (*s)++; }
    while (**s >= '0' && **s <= '9') {
        v = v * 10 + (**s - '0');
        (*s)++;
    }
    return sign * v;
}

node *parse_element(char **s);
node *parse_list(char **s);

node *parse_element(char **s) {
    skip(s);
    if (**s == '(') return parse_list(s);
    return new_atom(parse_int(s));
}

node *parse_list(char **s) {
    skip(s);
    (*s)++; // consome '('
    skip(s);

    if (**s == ')') { (*s)++; return new_list(NULL); }

    node *head = parse_element(s);
    skip(s);

    while (**s == ',') {
        (*s)++;
        head = append(head, parse_element(s));
        skip(s);
    }

    if (**s == ')') (*s)++;
    return new_list(head);
}

/* ======== BUSCA ======== */
int find_level(node *n, int x, int level) {
    while (n) {
        if (n->type == ATOM && n->head.atom == x)
            return level;
        if (n->type == LIST) {
            int sub = find_level(n->head.list, x, level + 1);
            if (sub != -1) return sub;
        }
        n = n->tail;
    }
    return -1;
}

/* ======== LIBERA MEMORIA ======== */
void free_node(node *n) {
    if (!n) return;
    if (n->type == LIST) {
        node *cur = n->head.list;
        while (cur) {
            node *next = cur->tail;
            free_node(cur);
            cur = next;
        }
    }
    free(n);
}

/* ======== MAIN ======== */
int main() {
    //variaveis
    int x;
    char lista[1000];

    //entrada
    scanf("%d", &x);
    scanf(" %[^\n]", lista);

    char *p = lista;
    node *root = parse_list(&p);

    //busca nos elementos da lista principal
    int nivel = find_level(root->head.list, x, 0);

    //imprime o nivel
    printf("%d\n", nivel);

    //libera a memoria
    free_node(root);
    return 0;
}
