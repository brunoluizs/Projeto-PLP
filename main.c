#include "hdr/list.h"
#include "hdr/visual.h"
#include "hdr/control.h"

#include <string.h>


int main()
{
    node_Lista *head, *tail;

    iniciar_Lista(&head, &tail);

    file_to_list(tail);

    run(head, tail);

    list_to_file(head);

    return 0;
}
