#include <stdio.h>

#define MAX 100

static char undo[MAX];
static int top_undo = -1;

static char redo[MAX];
static int top_redo = -1;

static void push_undo(const char x) {
    if (top_undo == MAX - 1) {
        printf("Undo stack overflow\n");
        return;
    }
    undo[++top_undo] = x;
}

static char pop_undo() {
    if (top_undo == -1) {
        printf("Undo: stack is empty\n");
        return '\0';
    }
    return undo[top_undo--];
}

static int empty_undo() {
    return top_undo == -1;
}

static void push_redo(char x) {
    if (top_redo == MAX - 1) {
        printf("Redo stack overflow\n");
        return;
    }
    redo[++top_redo] = x;
}

static char pop_redo() {
    if (top_redo == -1) {
        printf("Redo: stack is empty\n");
        return '\0';
    }
    return redo[top_redo--];
}

static int empty_redo() {
    return top_redo == -1;
}

static void clear_redo() {
    top_redo = -1;
}

int main(void) {
    char text[MAX + 1];
    int len = 0;
    text[0] = '\0';

    char line[256];
    printf("Text editor (array, capacity %d)\n", MAX);
    printf("Commands: '+ <char>' add, 'u' Undo, 'r' Redo, 'p' print\n");

    while (fgets(line, 256, stdin) != NULL) {
        if (line[0] == '+') {
            char c = line[2];
            if (c == '\0' || c == '\n' || c == '\r') {
                continue;
            }
            if (top_undo == MAX - 1) {
                printf("Undo stack overflow - character not added\n");
            } else {
                push_undo(c);
                text[len++] = c;
                text[len] = '\0';
                clear_redo();
                printf("Added '%c'. String: \"%s\"\n", c, text);
            }
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
    return 0;
}
