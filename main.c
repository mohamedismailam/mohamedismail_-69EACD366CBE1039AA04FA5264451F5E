#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* linear_search_product(char** product_list, int list_size, const char* target_product, int* result_size) {
    int* indices = NULL;
    int count = 0;

    // Find the occurrences and allocate memory
    for (int i = 0; i < list_size; i++) {
        if (strcmp(product_list[i], target_product) == 0) {
            // Increase the count and reallocate memory for the indices
            count++;
            indices = (int*)realloc(indices, count * sizeof(int));
            if (indices == NULL) {
                // Memory allocation failed
                perror("Memory allocation failed");
                *result_size = 0;
                return NULL;
            }
            indices[count - 1] = i;
        }
    }

    *result_size = count;
    return indices;
}

int main() {
    char* products[] = {"Apple", "Banana", "Orange", "Apple", "Mango", "Apple"};
    int list_size = 6;
    const char* target = "Apple";

    int result_size;
    int* result = linear_search_product(products, list_size, target, &result_size);

    if (result != NULL) {
        printf("The product '%s' was found at indices: ", target);
        for (int i = 0; i < result_size; i++) {
            if (i > 0) {
                printf(", ");
            }
            printf("%d", result[i]);
        }
        printf("\n");
        free(result); // Don't forget to free the allocated memory
    } else {
        printf("The product '%s' was not found in the list.\n", target);
    }

    return 0;
}
