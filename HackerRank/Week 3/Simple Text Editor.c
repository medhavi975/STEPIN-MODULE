#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000000

typedef struct {
    int type;        
    char *data;      
} Operation;

int main() {
    int Q;
    scanf("%d", &Q);

    char *S = (char *)malloc(MAX_LEN * sizeof(char));
    S[0] = '\0';  

    Operation *history = (Operation *)malloc(Q * sizeof(Operation));
    int hist_top = 0;

    for (int i = 0; i < Q; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            // append
            char w[MAX_LEN];
            scanf("%s", w);

            strcat(S, w);

            
            history[hist_top].type = 1;
            history[hist_top].data = strdup(w);
            hist_top++;

        } else if (type == 2) {
           
            int k;
            scanf("%d", &k);

            int len = strlen(S);
            char *deleted = (char *)malloc((k + 1) * sizeof(char));
            strcpy(deleted, S + len - k);

            S[len - k] = '\0';

           
            history[hist_top].type = 2;
            history[hist_top].data = deleted;
            hist_top++;

        } else if (type == 3) {
          
            int k;
            scanf("%d", &k);
            printf("%c\n", S[k - 1]);

        } else if (type == 4) {
          
            if (hist_top > 0) {
                hist_top--;
                Operation last = history[hist_top];

                if (last.type == 1) {
                  
                    int len = strlen(S);
                    int k = strlen(last.data);
                    S[len - k] = '\0';

                } else if (last.type == 2) {
                    
                    strcat(S, last.data);
                }

                free(last.data);
            }
        }
    }

    free(S);
    free(history);
    return 0;
}

