# yyjson重要经验
## 这样居然也可以
### example 1
```cpp
#include <iostream>
#include <yyjson.h>
using namespace std;
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
```
### example 2
```cpp
#include <iostream>
#include <yyjson.h>
using namespace std;
int main()
{
    yyjson_mut_doc *doc = yyjson_mut_doc_new(nullptr);
    yyjson_mut_val *root = yyjson_mut_obj(doc);
    yyjson_mut_doc_set_root(doc, root);
    yyjson_mut_val *key1 = yyjson_mut_str(doc, "name");
    yyjson_mut_val *val1 = yyjson_mut_arr(doc);
    yyjson_mut_arr_add_int(doc,val1,520);
    yyjson_mut_arr_add_int(doc,val1,521);
    yyjson_mut_arr_add_int(doc,val1,522);
    yyjson_mut_obj_add(root,key1,val1);
    cout << yyjson_mut_write(doc, YYJSON_WRITE_PRETTY, 0);
    return 0;
}
```

## yyjson如何在数组中加入对象?
### 解决方法:使用`yyjson_mut_arr_add_obj`创建对象,假设你数组里有两个对象,就用这个函数创建两次,此函数返回值是val
### example 1
```cpp
#include <iostream>
#include <yyjson.h>
using namespace std;
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
```