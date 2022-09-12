//
// Created by hloi on 9/12/2022.
//

#ifndef CH04DLINKEDLISTFA22_DNODE_H
#define CH04DLINKEDLISTFA22_DNODE_H

/** A DNode is the building block for a double-linked list. */
struct DNode {
/** A copy of the data */
    Item_Type data;
/** A pointer to the next DNode */
    DNode* next;
/** A pointer to the previous DNode */
    DNode* prev;
    DNode(const Item_Type& the_data,
          DNode* prev_val = nullptr, DNode* next_val = nullptr) :
            data(the_data), next(next_val), prev(prev_val) {}
};

#endif //CH04DLINKEDLISTFA22_DNODE_H
