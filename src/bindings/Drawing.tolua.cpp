/*
** Lua binding: Drawing
** Generated automatically by tolua++-1.0.92 on Tue Nov  8 00:34:29 2011.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Drawing_open (lua_State* tolua_S);

#include "Drawing.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
}

/* function: color */
#ifndef TOLUA_DISABLE_tolua_Drawing_color00
static int tolua_Drawing_color00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float r = ((float)  tolua_tonumber(tolua_S,1,0));
  float g = ((float)  tolua_tonumber(tolua_S,2,0));
  float b = ((float)  tolua_tonumber(tolua_S,3,0));
  float a = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   color(r,g,b,a);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'color'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: line */
#ifndef TOLUA_DISABLE_tolua_Drawing_line00
static int tolua_Drawing_line00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int startx = ((int)  tolua_tonumber(tolua_S,1,0));
  int starty = ((int)  tolua_tonumber(tolua_S,2,0));
  int endx = ((int)  tolua_tonumber(tolua_S,3,0));
  int endy = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   line(startx,starty,endx,endy);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'line'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: solidCircle */
#ifndef TOLUA_DISABLE_tolua_Drawing_solidCircle00
static int tolua_Drawing_solidCircle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int centerx = ((int)  tolua_tonumber(tolua_S,1,0));
  int centery = ((int)  tolua_tonumber(tolua_S,2,0));
  int radius = ((int)  tolua_tonumber(tolua_S,3,0));
  int numsegments = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   solidCircle(centerx,centery,radius,numsegments);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'solidCircle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Drawing_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_function(tolua_S,"color",tolua_Drawing_color00);
  tolua_function(tolua_S,"line",tolua_Drawing_line00);
  tolua_function(tolua_S,"solidCircle",tolua_Drawing_solidCircle00);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Drawing (lua_State* tolua_S) {
 return tolua_Drawing_open(tolua_S);
};
#endif

