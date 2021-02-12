#include "set.h"
#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;

template <class Item>
   set<Item>::set() {
       data_count = 0;
       child_count = 0;
       for (auto& p : subset) {
           p = nullptr;
       }
   }
   
   
 template <class Item>
   set<Item>::set(const set<Item>& source) {
           //data_count = source.data_count;
           //child_count = source.child_count;
           //for (int i = 0; i < data_count; i++) {
           //   data[i] = source.data[i];
           //}
       this = b_tree_copy(&source);
   }

   template <class Item>
   void set<Item>::clear() {
       for (auto& v : data) {
           v = Item();
       }
       for (auto& p : subset) {
           b_tree_clear(p);
       }
       data_count = 0;
       child_count = 0;
   }

   template <class Item>
   void set<Item>::operator=(const set<Item>& source) {
       if (this == &source) {
           return;
       }
       clear();
       this = b_tree_copy(&source);
   }

   template <class Item>
   std::size_t set<Item>::count(const Item& target) {
       std::size_t i = get_index(target);
       if (i < data_count && !(target < data[i])) {
           return 1;
       }
       if (child_count == 0) {
           return 0;
       }
       return subset[i]->count(target);
   }

   template <class Item>
   bool set<Item>::loose_insert(const Item& entry) {
       std::size_t i = get_index(entry);
       if (i < data_count && !(entry < data[i])) {
           return false;
       }
       if (child_count == 0) {
           for (std::size_t ix = data_count - 1; ix >= i; ix--) {
               data[ix + 1] = data[ix];
           }
           data[i] = entry;
           data_count++;
           return true;
       }
       bool b = subset[i]->loose_insert(entry);
       if (subset[i]->data_count == MAXIMUM + 1) {
           fix_excess(i);
       }
   }

   template <class Item>
   void set<Item>::fix_excess(std::size_t i) {
       for (std::size_t ix = child_count - 1; ix > i; ix--) {
           subset[ix + 1] = subset[ix];
       }
       subset[i + 1] = new set<Item>;
       child_count++;
       for (std::size_t ix = MINIMUM + 1; ix < MAXIMUM + 2; ix++){
           subset[i + 1]->subset[ix - MINIMUM - 1] = subset[i]->subset[ix];
       }
       for (std::size_t ix = MINIMUM + 1; ix < MAXIMUM + 1; ix++){
           subset[i + 1]->data[ix - MINIMUM - 1] = subset[i] -> data[ix];
       }
       subset[i]->data_count = MINIMUM;
       subset[i + 1]->data_count = MINIMUM;
       subset[i]->child_count = MINIMUM + 1;
       subset[i + 1]->child_count = MINIMUM + 1;
       for (std::size_t ix = data_count - 1; ix >= i; ix--) {
           data[ix + 1] = data[ix];
       }
       data_count++;
       data[i] = subset[i]->data[MINIMUM];
   }

   template <class Item>
   bool set<Item>::insert(const Item& entry) {
       if (!loose_insert(entry)) {
           return false;
       }
       if (data_count > MAXIMUM) {
           set<Item>* pset = new set<Item>;
           pset->subset[0] = this;
           pset->child_count = 1;
           this = pset;
           fix_excess(0);
       }
       return true;
   }
   
   template <class Item>
std::size_t set<Item>::erase(const Item& target) {
    if (!loose_erase(target))
        return false;
        if ((data_count == 0) && (child_count == 1)) {
            set* targetptr = subset[0]; //Fix root so that it no longer has 0 entries.
            data = subset[0]->data;
            data_count = subset[0]->data_count;
            vector<set*> new_subset;
            for (size_t index = 0; index < subset[0]->child_count; ++index) {
                set* copied = new set(*(subset[0]->subset[index]));
                new_subset.push_back(copied);
            }
            child_count = subset[0]->child_count;
            subset = new_subset;
            delete targetptr;
    }
    return true;
}

template <class Item>
bool set<Item>::loose_erase(const Item& target) {
    size_t index = 0;
    while ((index < data_count) && (data[index] < target))
        ++index;	//then let index = data_count, indicating that all entries are less than target

    bool found = (index < data_count) && !(target < data[index]);

    if (is_leaf() && !found)
        return false;
    if (is_leaf() && found) {
        erase_entry(data, index);
        --data_count;
        return true;
    }
    if (!is_leaf() && !found) {
        bool erased = subset[index]->loose_erase(target);
        if (subset[index]->data_count < MINIMUM)
            fix_shortage(index);
        return erased;
    }
    if (!is_leaf() && found) {
        subset[index]->remove_biggest(data[index]);
        if (subset[index]->data_count < MINIMUM)
            fix_shortage(index);
        return true;
    }
}

template <class Item>
void set<Item>::remove_biggest(Item& removed_entry){
    if (is_leaf()) {
        removed_entry = data.back();
        data.pop_back();
        --data_count;
    } else {
        subset[child_count - 1]->remove_biggest(removed_entry);
        if (subset[child_count - 1]->data_count < MINIMUM)
        fix_shortage(child_count - 1);
    }
}

template <class Item>
void set<Item>::print(int indent) {
    cout << setw(indent * 4) << “”;
    if (data_count != 0){
        for (size_t index = 0; index < data_count; ++index)
            cout << data[index] << " ";
        if (child_count == 0)
            cout << "[Leaf]\n";
        else {
            cout << endl;
            for (size_t index = 0; index < data_count + 1; ++index)
                    subset[index]->print(indent + 1);
        }
    } else
        cout << "[Empty]\n";
}