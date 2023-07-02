#include <iostream>
#include <yyjson.h>
using namespace std;
// void AddNewScript(yyjson_mut_doc* doc)
int main()
{
    yyjson_mut_doc *doc = yyjson_mut_doc_new(nullptr);
    yyjson_mut_val *root = yyjson_mut_obj(doc);
    yyjson_mut_doc_set_root(doc, root);

    // StateEditArr
    yyjson_mut_val *key_arr_StateEdit = yyjson_mut_str(doc, "StateEdit");
    yyjson_mut_val *val_arr_StateEdit = yyjson_mut_arr(doc);
    yyjson_mut_obj_add(root, key_arr_StateEdit, val_arr_StateEdit);
    // StateEditArr-MemberObj

    yyjson_mut_val *val_arr_StateEdit_obj_Member =  yyjson_mut_arr_add_obj(doc,val_arr_StateEdit);
   

    yyjson_mut_val *key_arr_StateEdit_obj_Member_str_key_ScriptName = yyjson_mut_str(doc, "Script");
    yyjson_mut_val *key_arr_StateEdit_obj_Member_str_val_ScriptName = yyjson_mut_str(doc, "佩里科岛");
    yyjson_mut_obj_add(val_arr_StateEdit_obj_Member,key_arr_StateEdit_obj_Member_str_key_ScriptName,key_arr_StateEdit_obj_Member_str_val_ScriptName);

    cout << yyjson_mut_write(doc, YYJSON_WRITE_PRETTY, 0);
    return 0;
}