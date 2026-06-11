typedef struct intTreeNode IntTreeNode, *IntTree;
struct intTreeNode
{
    IntTree left;
    int data;
    IntTree right;
};

typedef struct report
{
    int min;
    int max;
} Report, *ReportPtr;

typedef enum response
{
    ADDED,
    OVERWRITTEN,
    OUT_OF_MEMORY,
    ERROR
} Response;