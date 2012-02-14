/*
** Lua binding: TestClass
** Generated automatically by tolua++-1.0.92 on Wed Nov  2 21:13:43 2011.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"
#include "TestClass.h"

/* Exported function */
extern "C" int  tolua_TestClass_open (lua_State* tolua_S);


/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_TestClass (lua_State* tolua_S)
{
 TestClass* self = (TestClass*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"TestClass");
}

/* method: new of class  TestClass */
#ifndef TOLUA_DISABLE_tolua_TestClass_TestClass_new00
static int tolua_TestClass_TestClass_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TestClass",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TestClass* tolua_ret = (TestClass*)  Mtolua_new((TestClass)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TestClass");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  TestClass */
#ifndef TOLUA_DISABLE_tolua_TestClass_TestClass_new00_local
static int tolua_TestClass_TestClass_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TestClass",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TestClass* tolua_ret = (TestClass*)  Mtolua_new((TestClass)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TestClass");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  TestClass */
#ifndef TOLUA_DISABLE_tolua_TestClass_TestClass_delete00
static int tolua_TestClass_TestClass_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TestClass",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TestClass* self = (TestClass*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hello of class  TestClass */
#ifndef TOLUA_DISABLE_tolua_TestClass_TestClass_hello00
static int tolua_TestClass_TestClass_hello00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TestClass",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TestClass* self = (TestClass*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hello'", NULL);
#endif
  {
   self->hello();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hello'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_TestClass_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"TestClass","TestClass","",tolua_collect_TestClass);
  #else
  tolua_cclass(tolua_S,"TestClass","TestClass","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"TestClass");
   tolua_function(tolua_S,"new",tolua_TestClass_TestClass_new00);
   tolua_function(tolua_S,"new_local",tolua_TestClass_TestClass_new00_local);
   tolua_function(tolua_S,".call",tolua_TestClass_TestClass_new00_local);
   tolua_function(tolua_S,"delete",tolua_TestClass_TestClass_delete00);
   tolua_function(tolua_S,"hello",tolua_TestClass_TestClass_hello00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


extern "C"{
	 int luaopen_TestClass (lua_State* tolua_S) {
		 return tolua_TestClass_open(tolua_S);
	 };
 }
