/*programa em C com lista generalizada*/

#include <stdio.h>
#include <stdlib.h>

/*
   ==============================
   REPRESENTAÇÃO DA LISTA GERAL
   ==============================
*/

typedef enum {
    ATOM = 0, 
    LIST = 1  
} NodeType;

typedef struct node {
    NodeType type;  
    union {
        int atom;         
        struct node *list; 
    } head;
    struct node *tail;
} node;

/*
   =========================
   FUNÇÕES DE CONSTRUÇÃO
   =========================
*/
node *new_atom(int v) {
    node *n = (node*)malloc(sizeof(node));
    n->type = ATOM;
    n->head.atom = v;
    n->tail = NULL;
    return n;
}

node *new_list(node *first_elem) {
    node *n = (node*)malloc(sizeof(node));
    n->type = LIST;
    n->head.list = first_elem;
    n->tail = NULL;
    return n;
}

node *append(node *head, node *elem) {
    if (head == NULL) {
        return elem;
    } else {
        node *cur = head;
        while (cur->tail != NULL) {
            cur = cur->tail;
        }
        cur->tail = elem;
        return head;
    }
}

/*
   =========================
   PARSER
   =========================
*/
int parse_int(char **s) {
    int sign = 1;
    int val = 0;
    if (**s == '-') {
        sign = -1;
        (*s)++;
    }
    while (**s >= '0' && **s <= '9') {
        val = val * 10 + (**s - '0');
        (*s)++;
    }
    return sign * val;
}

node *parse_element(char **s);
node *parse_list(char **s);

node *parse_element(char **s) {
    if (**s == '(') {
        return parse_list(s);
    } else {
        int v = parse_int(s);
        return new_atom(v);
    }
}

node *parse_list(char **s) {
    (*s)++; // consome '('
    node *level_head = NULL;

    if (**s == ')') { // lista vazia
        (*s)++;
        return new_list(NULL);
    }

    node *elem = parse_element(s);
    level_head = append(level_head, elem);

    while (**s == ',') {
        (*s)++;
        node *next_elem = parse_element(s);
        level_head = append(level_head, next_elem);
    }

    if (**s == ')') {
        (*s)++;
    }

    return new_list(level_head);
}

/*
   =========================
   IMPRESSÃO
   =========================
*/
void print_node(node *n);

void print_list_elems(node *n) {
    node *cur = n;
    while (cur != NULL) {
        print_node(cur);
        if (cur->tail != NULL) {
            printf(",");
        }
        cur = cur->tail;
    }
}

void print_node(node *n) {
    if (n == NULL) {
        printf("()");
        return;
    }
    if (n->type == ATOM) {
        printf("%d", n->head.atom);
    } else {
        printf("(");
        print_list_elems(n->head.list);
        printf(")");
    }
}

/*
   =========================
   LIBERAR MEMÓRIA
   =========================
*/
void free_node(node *n) {
    if (n == NULL) {
        return;
    }

    if (n->type == LIST) {
        node *sub = n->head.list;
        while (sub != NULL) {
            node *next = sub->tail;
            free_node(sub);
            sub = next;
        }
    }
    free(n);
}

/*
   =========================
   FUNÇÃO RECURSIVA: max_depth
   =========================
*/
int max_depth(node *n, int nivel_atual) {
    if (n == NULL) {
        return nivel_atual;
    }

    int max = nivel_atual;

    while (n != NULL) {
        if (n->type == LIST) {
            int sub = max_depth(n->head.list, nivel_atual + 1);
            if (sub > max) {
                max = sub;
            }
        }
        n = n->tail;
    }

    return max;
}

/*
   =========================
   MAIN
   =========================
*/
int main() {
    //variaveis
    char buffer[1024];

    //leitura da entrada
    if (!fgets(buffer, sizeof(buffer), stdin)) {
        return 1;
    }

    char *ptr = buffer;
    node *root = parse_list(&ptr);

    //calcula e imprime o número de níveis
    int niveis = max_depth(root, -1); 
    printf("%d", niveis);

    free_node(root);
    return 0;
}
