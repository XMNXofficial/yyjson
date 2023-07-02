#include <iostream>
#include <yyjson.h>
using namespace std;
// void AddNewScript(yyjson_mut_doc* doc)
int main()
{
    yyjson_mut_doc *doc = yyjson_mut_doc_new(nullptr);
    yyjson_mut_val *root = yyjson_mut_obj(doc);
    yyjson_mut_doc_set_root(doc, root);
    yyjson_mut_val *key1 = yyjson_mut_str(doc, "name");
    yyjson_mut_val *val1 = yyjson_mut_arr(doc);
    yyjson_mut_obj_add(root,key1,val1);
    yyjson_mut_arr_add_int(doc,val1,520);
    yyjson_mut_arr_add_int(doc,val1,521);
    yyjson_mut_arr_add_int(doc,val1,522);
    cout << yyjson_mut_write(doc, YYJSON_WRITE_PRETTY, 0);
    return 0;
}