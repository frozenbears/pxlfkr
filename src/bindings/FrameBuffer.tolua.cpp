/*
** Lua binding: FrameBuffer
** Generated automatically by tolua++-1.0.92 on Sun Apr  8 21:29:10 2012.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_FrameBuffer_open (lua_State* tolua_S);

#include "cinder/gl/gl.h"
#include "cinder/gl/Fbo.h"

#include "FrameBuffer.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_FrameBuffer (lua_State* tolua_S)
{
 FrameBuffer* self = (FrameBuffer*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"FrameBuffer");
}

/* method: new of class  FrameBuffer */
#ifndef TOLUA_DISABLE_tolua_FrameBuffer_FrameBuffer_new00
static int tolua_FrameBuffer_FrameBuffer_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FrameBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const int sizex = ((const int)  tolua_tonumber(tolua_S,2,0));
  const int sizey = ((const int)  tolua_tonumber(tolua_S,3,0));
  {
   FrameBuffer* tolua_ret = (FrameBuffer*)  Mtolua_new((FrameBuffer)(sizex,sizey));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FrameBuffer");
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

/* method: new_local of class  FrameBuffer */
#ifndef TOLUA_DISABLE_tolua_FrameBuffer_FrameBuffer_new00_local
static int tolua_FrameBuffer_FrameBuffer_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FrameBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const int sizex = ((const int)  tolua_tonumber(tolua_S,2,0));
  const int sizey = ((const int)  tolua_tonumber(tolua_S,3,0));
  {
   FrameBuffer* tolua_ret = (FrameBuffer*)  Mtolua_new((FrameBuffer)(sizex,sizey));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FrameBuffer");
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

/* method: bind of class  FrameBuffer */
#ifndef TOLUA_DISABLE_tolua_FrameBuffer_FrameBuffer_bind00
static int tolua_FrameBuffer_FrameBuffer_bind00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FrameBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FrameBuffer* self = (FrameBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: unbind of class  FrameBuffer */
#ifndef TOLUA_DISABLE_tolua_FrameBuffer_FrameBuffer_unbind00
static int tolua_FrameBuffer_FrameBuffer_unbind00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FrameBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FrameBuffer* self = (FrameBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: draw of class  FrameBuffer */
#ifndef TOLUA_DISABLE_tolua_FrameBuffer_FrameBuffer_draw00
static int tolua_FrameBuffer_FrameBuffer_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FrameBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FrameBuffer* self = (FrameBuffer*)  tolua_tousertype(tolua_S,1,0);
  int startx = ((int)  tolua_tonumber(tolua_S,2,0));
  int starty = ((int)  tolua_tonumber(tolua_S,3,0));
  int sizex = ((int)  tolua_tonumber(tolua_S,4,0));
  int sizey = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'", NULL);
#endif
  {
   self->draw(startx,starty,sizex,sizey);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_FrameBuffer_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"FrameBuffer","FrameBuffer","",tolua_collect_FrameBuffer);
  #else
  tolua_cclass(tolua_S,"FrameBuffer","FrameBuffer","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"FrameBuffer");
   tolua_function(tolua_S,"new",tolua_FrameBuffer_FrameBuffer_new00);
   tolua_function(tolua_S,"new_local",tolua_FrameBuffer_FrameBuffer_new00_local);
   tolua_function(tolua_S,".call",tolua_FrameBuffer_FrameBuffer_new00_local);
   tolua_function(tolua_S,"bind",tolua_FrameBuffer_FrameBuffer_bind00);
   tolua_function(tolua_S,"unbind",tolua_FrameBuffer_FrameBuffer_unbind00);
   tolua_function(tolua_S,"draw",tolua_FrameBuffer_FrameBuffer_draw00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_FrameBuffer (lua_State* tolua_S) {
 return tolua_FrameBuffer_open(tolua_S);
};
#endif

