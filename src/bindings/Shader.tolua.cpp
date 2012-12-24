/*
** Lua binding: Shader
** Generated automatically by tolua++-1.0.92 on Sun Dec 23 18:42:40 2012.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Shader_open (lua_State* tolua_S);

#include "Shader.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Shader (lua_State* tolua_S)
{
 Shader* self = (Shader*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Shader");
}

/* method: new of class  Shader */
#ifndef TOLUA_DISABLE_tolua_Shader_Shader_new00
static int tolua_Shader_Shader_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Shader",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string vertexFile = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string fragmentFile = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  {
   Shader* tolua_ret = (Shader*)  Mtolua_new((Shader)(vertexFile,fragmentFile));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Shader");
   tolua_pushcppstring(tolua_S,(const char*)vertexFile);
   tolua_pushcppstring(tolua_S,(const char*)fragmentFile);
  }
 }
 return 3;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Shader */
#ifndef TOLUA_DISABLE_tolua_Shader_Shader_new00_local
static int tolua_Shader_Shader_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Shader",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string vertexFile = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string fragmentFile = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  {
   Shader* tolua_ret = (Shader*)  Mtolua_new((Shader)(vertexFile,fragmentFile));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Shader");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
   tolua_pushcppstring(tolua_S,(const char*)vertexFile);
   tolua_pushcppstring(tolua_S,(const char*)fragmentFile);
  }
 }
 return 3;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: bind of class  Shader */
#ifndef TOLUA_DISABLE_tolua_Shader_Shader_bind00
static int tolua_Shader_Shader_bind00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Shader",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Shader* self = (Shader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'bind'", NULL);
#endif
  {
   self->bind();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bind'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unbind of class  Shader */
#ifndef TOLUA_DISABLE_tolua_Shader_Shader_unbind00
static int tolua_Shader_Shader_unbind00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Shader",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Shader* self = (Shader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unbind'", NULL);
#endif
  {
   self->unbind();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unbind'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: uniform1f of class  Shader */
#ifndef TOLUA_DISABLE_tolua_Shader_Shader_uniform1f00
static int tolua_Shader_Shader_uniform1f00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Shader",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Shader* self = (Shader*)  tolua_tousertype(tolua_S,1,0);
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  float data = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'uniform1f'", NULL);
#endif
  {
   self->uniform1f(name,data);
   tolua_pushcppstring(tolua_S,(const char*)name);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'uniform1f'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: uniform2f of class  Shader */
#ifndef TOLUA_DISABLE_tolua_Shader_Shader_uniform2f00
static int tolua_Shader_Shader_uniform2f00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Shader",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Shader* self = (Shader*)  tolua_tousertype(tolua_S,1,0);
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  float data = ((float)  tolua_tonumber(tolua_S,3,0));
  float data2 = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'uniform2f'", NULL);
#endif
  {
   self->uniform2f(name,data,data2);
   tolua_pushcppstring(tolua_S,(const char*)name);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'uniform2f'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: uniform3f of class  Shader */
#ifndef TOLUA_DISABLE_tolua_Shader_Shader_uniform3f00
static int tolua_Shader_Shader_uniform3f00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Shader",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Shader* self = (Shader*)  tolua_tousertype(tolua_S,1,0);
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  float data = ((float)  tolua_tonumber(tolua_S,3,0));
  float data2 = ((float)  tolua_tonumber(tolua_S,4,0));
  float data3 = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'uniform3f'", NULL);
#endif
  {
   self->uniform3f(name,data,data2,data3);
   tolua_pushcppstring(tolua_S,(const char*)name);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'uniform3f'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: uniform4f of class  Shader */
#ifndef TOLUA_DISABLE_tolua_Shader_Shader_uniform4f00
static int tolua_Shader_Shader_uniform4f00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Shader",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Shader* self = (Shader*)  tolua_tousertype(tolua_S,1,0);
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  float data = ((float)  tolua_tonumber(tolua_S,3,0));
  float data2 = ((float)  tolua_tonumber(tolua_S,4,0));
  float data3 = ((float)  tolua_tonumber(tolua_S,5,0));
  float data4 = ((float)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'uniform4f'", NULL);
#endif
  {
   self->uniform4f(name,data,data2,data3,data4);
   tolua_pushcppstring(tolua_S,(const char*)name);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'uniform4f'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: uniform1i of class  Shader */
#ifndef TOLUA_DISABLE_tolua_Shader_Shader_uniform1i00
static int tolua_Shader_Shader_uniform1i00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Shader",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Shader* self = (Shader*)  tolua_tousertype(tolua_S,1,0);
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  int data = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'uniform1i'", NULL);
#endif
  {
   self->uniform1i(name,data);
   tolua_pushcppstring(tolua_S,(const char*)name);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'uniform1i'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: uniform2i of class  Shader */
#ifndef TOLUA_DISABLE_tolua_Shader_Shader_uniform2i00
static int tolua_Shader_Shader_uniform2i00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Shader",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Shader* self = (Shader*)  tolua_tousertype(tolua_S,1,0);
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  int data = ((int)  tolua_tonumber(tolua_S,3,0));
  int data2 = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'uniform2i'", NULL);
#endif
  {
   self->uniform2i(name,data,data2);
   tolua_pushcppstring(tolua_S,(const char*)name);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'uniform2i'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Shader_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Shader","Shader","",tolua_collect_Shader);
  #else
  tolua_cclass(tolua_S,"Shader","Shader","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Shader");
   tolua_function(tolua_S,"new",tolua_Shader_Shader_new00);
   tolua_function(tolua_S,"new_local",tolua_Shader_Shader_new00_local);
   tolua_function(tolua_S,".call",tolua_Shader_Shader_new00_local);
   tolua_function(tolua_S,"bind",tolua_Shader_Shader_bind00);
   tolua_function(tolua_S,"unbind",tolua_Shader_Shader_unbind00);
   tolua_function(tolua_S,"uniform1f",tolua_Shader_Shader_uniform1f00);
   tolua_function(tolua_S,"uniform2f",tolua_Shader_Shader_uniform2f00);
   tolua_function(tolua_S,"uniform3f",tolua_Shader_Shader_uniform3f00);
   tolua_function(tolua_S,"uniform4f",tolua_Shader_Shader_uniform4f00);
   tolua_function(tolua_S,"uniform1i",tolua_Shader_Shader_uniform1i00);
   tolua_function(tolua_S,"uniform2i",tolua_Shader_Shader_uniform2i00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Shader (lua_State* tolua_S) {
 return tolua_Shader_open(tolua_S);
};
#endif

