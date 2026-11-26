#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *next;
};

static struct node *undo_top = NULL;
static struct node *redo_top = NULL;

static void push_undo(const char x) {
    struct node *n = malloc(sizeof(struct node));
    if (n == NULL) {
        printf("Out of memory\n");
        return;
    }
    n->data = x;
    n->next = undo_top;
    undo_top = n;
}

static char pop_undo() {
    if (undo_top == NULL) {
        printf("Undo: stack is empty\n");
        return '\0';
    }
    struct node *t = undo_top;
    const char x = t->data;
    undo_top = undo_top->next;
    free(t);
    return x;
}

static int empty_undo() {
    return undo_top == NULL;
}

static void clear_undo() {
    while (undo_top != NULL) {
        struct node *t = undo_top;
        undo_top = undo_top->next;
        free(t);
    }
}

static void push_redo(const char x) {
    struct node *n = malloc(sizeof(struct node));
    if (n == NULL) {
        printf("Out of memory\n");
        return;
    }
    n->data = x;
    n->next = redo_top;
    redo_top = n;
}

static char pop_redo() {
    if (redo_top == NULL) {
        printf("Redo: stack is empty\n");
        return '\0';
    }
    struct node *t = redo_top;
    const char x = t->data;
    redo_top = redo_top->next;
    free(t);
    return x;
}

static int empty_redo() {
    return redo_top == NULL;
}

static void clear_redo() {
    while (redo_top != NULL) {
        struct node *t = redo_top;
        redo_top = redo_top->next;
        free(t);
    }
}

int main(void) {
    char text[1000];
    int len = 0;
    text[0] = '\0';

    char line[256];
    printf("Text editor (linked list)\n");
    printf("Commands: '+ <char>' add, 'u' Undo, 'r' Redo, 'p' print\n");

    while (fgets(line, 256, stdin) != NULL) {
        if (line[0] == '+') {
            char c = line[2];
            if (c == '\0' || c == '\n' || c == '\r') {
                continue;
            }
            push_undo(c);
            text[len++] = c;
            text[len] = '\0';
            clear_redo();
            printf("Added '%c'. String: \"%s\"\n", c, text);
        } else if (line[0] == 'u' || line[0] == 'U') {
            if (empty_undo()) {
                printf("Undo: stack is empty - nothing to undo\n");
            } else {
                const char c = pop_undo();
                text[--len] = '\0';
                push_redo(c);
                printf("Undo: removed '%c'. String: \"%s\"\n", c, text);
            }
        } else if (line[0] == 'r' || line[0] == 'R') {
            if (empty_redo()) {
                printf("Redo: stack is empty - nothing to redo\n");
            } else {
                const char c = pop_redo();
                push_undo(c);
                text[len++] = c;
                text[len] = '\0';
                printf("Redo: restored '%c'. String: \"%s\"\n", c, text);
            }
        } else if (line[0] == 'p' || line[0] == 'P') {
            printf("String: \"%s\"\n", text);
        }
    }

    printf("Final string: \"%s\"\n", text);

    clear_undo();
    clear_redo();
    return 0;
}
