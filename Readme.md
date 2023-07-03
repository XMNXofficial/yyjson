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

    // StatEditArr
    yyjson_mut_val *key_arr_StatEdit = yyjson_mut_str(doc, "StatEdit");
    yyjson_mut_val *val_arr_StatEdit = yyjson_mut_arr(doc);
    yyjson_mut_obj_add(root, key_arr_StatEdit, val_arr_StatEdit);
    // StatEditArr-MemberObj

    yyjson_mut_val *val_arr_StatEdit_obj_Member =  yyjson_mut_arr_add_obj(doc,val_arr_StatEdit);
   

    yyjson_mut_val *key_arr_StatEdit_obj_Member_str_key_ScriptName = yyjson_mut_str(doc, "Script");
    yyjson_mut_val *key_arr_StatEdit_obj_Member_str_val_ScriptName = yyjson_mut_str(doc, "佩里科岛");
    yyjson_mut_obj_add(val_arr_StatEdit_obj_Member,key_arr_StatEdit_obj_Member_str_key_ScriptName,key_arr_StatEdit_obj_Member_str_val_ScriptName);



    cout << yyjson_mut_write(doc, YYJSON_WRITE_PRETTY, 0);
    return 0;
}
```

## 如何读入数据并且修改?
### 方法:先不可变读入,然后使用copy函数创建可变json
```cpp
    //不可变转为可变
    char* str=R"({"userName":"test"})";
    yyjson_doc* temp=yyjson_read(str,strlen(str),0);
    yyjson_mut_doc* temp_mut= yyjson_doc_mut_copy(temp,nullptr);

    yyjson_mut_val* temp_mut_root=yyjson_mut_doc_get_root(temp_mut);
    yyjson_mut_obj_add(temp_mut_root,yyjson_mut_str(temp_mut,"你好"),yyjson_mut_str(temp_mut,"世界"));
    cout<<yyjson_mut_write(temp_mut,0,0);
```