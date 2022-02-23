#include "enum.h"

// define the enumeration type
int main() {

    // set length and configure the names (optional)
    uint32_t len = 3;
    char names[] = "syn, ack, fin";

    Enum* enu = new_e(names, len);

    printf("\nDefault: \n");
    enu->print(enu);

    printf("\nI) Open TCP connection: \n");
    printf("\n1. Client -> Server: \n");

    if (~enu->is(enu, syn)) {
        enu->set(enu, syn);
    }
    enu->print(enu);
    
    printf("\n2. Server -> Client: \n");
    if (enu->is(enu, syn) & ~enu->is(enu, ack)) {
        enu->set(enu, ack);
    }
    enu->print(enu);

    printf("\n3. Client -> Server: \n");
    if (enu->is(enu, syn) & enu->is(enu, ack)) {
        enu->reset(enu, syn);
    }
    enu->print(enu);
    
        printf("\nII) Close TCP connection: \n");
    printf("\n1. Client -> Server: \n");

    if (enu->is(enu, ack) & ~enu->is(enu, fin)) {
        enu->reset(enu, ack);
        enu->set(enu, fin);
    }
    enu->print(enu);
    
    printf("\n2. Server -> Client: \n");
    if (enu->is(enu, fin) & ~enu->is(enu, ack)) {
        enu->set(enu, ack);
    }
    enu->print(enu);

    printf("\n3. Client -> Server: \n");
    if (enu->is(enu, fin) & enu->is(enu, ack)) {
        enu->reset(enu, fin);
    }
    enu->print(enu);

    // free memory
    del_e(enu);
}