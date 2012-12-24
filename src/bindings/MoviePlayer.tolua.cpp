/*
** Lua binding: MoviePlayer
** Generated automatically by tolua++-1.0.92 on Sun Dec 23 22:42:38 2012.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_MoviePlayer_open (lua_State* tolua_S);

#include "MoviePlayer.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_MoviePlayer (lua_State* tolua_S)
{
 MoviePlayer* self = (MoviePlayer*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"MoviePlayer");
}

/* method: new of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_new00
static int tolua_MoviePlayer_MoviePlayer_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MoviePlayer* tolua_ret = (MoviePlayer*)  Mtolua_new((MoviePlayer)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MoviePlayer");
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

/* method: new_local of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_new00_local
static int tolua_MoviePlayer_MoviePlayer_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MoviePlayer* tolua_ret = (MoviePlayer*)  Mtolua_new((MoviePlayer)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MoviePlayer");
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

/* method: delete of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_delete00
static int tolua_MoviePlayer_MoviePlayer_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: load of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_load00
static int tolua_MoviePlayer_MoviePlayer_load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
  const std::string path = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'load'", NULL);
#endif
  {
   self->load(path);
   tolua_pushcppstring(tolua_S,(const char*)path);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'load'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isPlayable of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_isPlayable00
static int tolua_MoviePlayer_MoviePlayer_isPlayable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isPlayable'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isPlayable();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isPlayable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWidth of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_getWidth00
static int tolua_MoviePlayer_MoviePlayer_getWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWidth'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHeight of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_getHeight00
static int tolua_MoviePlayer_MoviePlayer_getHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHeight'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAspectRatio of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_getAspectRatio00
static int tolua_MoviePlayer_MoviePlayer_getAspectRatio00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAspectRatio'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getAspectRatio();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAspectRatio'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPixelAspectRatio of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_getPixelAspectRatio00
static int tolua_MoviePlayer_MoviePlayer_getPixelAspectRatio00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPixelAspectRatio'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getPixelAspectRatio();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPixelAspectRatio'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDuration of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_getDuration00
static int tolua_MoviePlayer_MoviePlayer_getDuration00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDuration'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getDuration();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDuration'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFramerate of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_getFramerate00
static int tolua_MoviePlayer_MoviePlayer_getFramerate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFramerate'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getFramerate();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFramerate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNumFrames of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_getNumFrames00
static int tolua_MoviePlayer_MoviePlayer_getNumFrames00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNumFrames'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getNumFrames();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNumFrames'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasAlpha of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_hasAlpha00
static int tolua_MoviePlayer_MoviePlayer_hasAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasAlpha'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasAlpha();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasVisuals of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_hasVisuals00
static int tolua_MoviePlayer_MoviePlayer_hasVisuals00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasVisuals'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasVisuals();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasVisuals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasAudio of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_hasAudio00
static int tolua_MoviePlayer_MoviePlayer_hasAudio00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasAudio'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasAudio();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasAudio'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurrentTime of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_getCurrentTime00
static int tolua_MoviePlayer_MoviePlayer_getCurrentTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrentTime'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getCurrentTime();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrentTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: seekToTime of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_seekToTime00
static int tolua_MoviePlayer_MoviePlayer_seekToTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
  float seconds = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'seekToTime'", NULL);
#endif
  {
   self->seekToTime(seconds);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'seekToTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: seekToFrame of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_seekToFrame00
static int tolua_MoviePlayer_MoviePlayer_seekToFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
  int frame = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'seekToFrame'", NULL);
#endif
  {
   self->seekToFrame(frame);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'seekToFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: seekToStart of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_seekToStart00
static int tolua_MoviePlayer_MoviePlayer_seekToStart00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'seekToStart'", NULL);
#endif
  {
   self->seekToStart();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'seekToStart'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: seekToEnd of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_seekToEnd00
static int tolua_MoviePlayer_MoviePlayer_seekToEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'seekToEnd'", NULL);
#endif
  {
   self->seekToEnd();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'seekToEnd'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setActiveSegment of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_setActiveSegment00
static int tolua_MoviePlayer_MoviePlayer_setActiveSegment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
  float startTime = ((float)  tolua_tonumber(tolua_S,2,0));
  float duration = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setActiveSegment'", NULL);
#endif
  {
   self->setActiveSegment(startTime,duration);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setActiveSegment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resetActiveSegment of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_resetActiveSegment00
static int tolua_MoviePlayer_MoviePlayer_resetActiveSegment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resetActiveSegment'", NULL);
#endif
  {
   self->resetActiveSegment();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resetActiveSegment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLoop of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_setLoop00
static int tolua_MoviePlayer_MoviePlayer_setLoop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
  bool loop = ((bool)  tolua_toboolean(tolua_S,2,0));
  bool pingpong = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLoop'", NULL);
#endif
  {
   self->setLoop(loop,pingpong);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLoop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stepForward of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_stepForward00
static int tolua_MoviePlayer_MoviePlayer_stepForward00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stepForward'", NULL);
#endif
  {
   self->stepForward();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stepForward'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stepBackward of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_stepBackward00
static int tolua_MoviePlayer_MoviePlayer_stepBackward00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stepBackward'", NULL);
#endif
  {
   self->stepBackward();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stepBackward'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRate of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_setRate00
static int tolua_MoviePlayer_MoviePlayer_setRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
  float rate = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRate'", NULL);
#endif
  {
   self->setRate(rate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVolume of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_setVolume00
static int tolua_MoviePlayer_MoviePlayer_setVolume00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
  float volume = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVolume'", NULL);
#endif
  {
   self->setVolume(volume);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVolume'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getVolume of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_getVolume00
static int tolua_MoviePlayer_MoviePlayer_getVolume00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVolume'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getVolume();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getVolume'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isPlaying of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_isPlaying00
static int tolua_MoviePlayer_MoviePlayer_isPlaying00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isPlaying'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isPlaying();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isPlaying'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isDone of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_isDone00
static int tolua_MoviePlayer_MoviePlayer_isDone00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isDone'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isDone();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isDone'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: play of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_play00
static int tolua_MoviePlayer_MoviePlayer_play00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'play'", NULL);
#endif
  {
   self->play();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'play'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stop of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_stop00
static int tolua_MoviePlayer_MoviePlayer_stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stop'", NULL);
#endif
  {
   self->stop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw of class  MoviePlayer */
#ifndef TOLUA_DISABLE_tolua_MoviePlayer_MoviePlayer_draw00
static int tolua_MoviePlayer_MoviePlayer_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MoviePlayer",0,&tolua_err) ||
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
  MoviePlayer* self = (MoviePlayer*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int sizex = ((int)  tolua_tonumber(tolua_S,4,0));
  int sizey = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'", NULL);
#endif
  {
   self->draw(x,y,sizex,sizey);
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
TOLUA_API int tolua_MoviePlayer_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"MoviePlayer","MoviePlayer","",tolua_collect_MoviePlayer);
  #else
  tolua_cclass(tolua_S,"MoviePlayer","MoviePlayer","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"MoviePlayer");
   tolua_function(tolua_S,"new",tolua_MoviePlayer_MoviePlayer_new00);
   tolua_function(tolua_S,"new_local",tolua_MoviePlayer_MoviePlayer_new00_local);
   tolua_function(tolua_S,".call",tolua_MoviePlayer_MoviePlayer_new00_local);
   tolua_function(tolua_S,"delete",tolua_MoviePlayer_MoviePlayer_delete00);
   tolua_function(tolua_S,"load",tolua_MoviePlayer_MoviePlayer_load00);
   tolua_function(tolua_S,"isPlayable",tolua_MoviePlayer_MoviePlayer_isPlayable00);
   tolua_function(tolua_S,"getWidth",tolua_MoviePlayer_MoviePlayer_getWidth00);
   tolua_function(tolua_S,"getHeight",tolua_MoviePlayer_MoviePlayer_getHeight00);
   tolua_function(tolua_S,"getAspectRatio",tolua_MoviePlayer_MoviePlayer_getAspectRatio00);
   tolua_function(tolua_S,"getPixelAspectRatio",tolua_MoviePlayer_MoviePlayer_getPixelAspectRatio00);
   tolua_function(tolua_S,"getDuration",tolua_MoviePlayer_MoviePlayer_getDuration00);
   tolua_function(tolua_S,"getFramerate",tolua_MoviePlayer_MoviePlayer_getFramerate00);
   tolua_function(tolua_S,"getNumFrames",tolua_MoviePlayer_MoviePlayer_getNumFrames00);
   tolua_function(tolua_S,"hasAlpha",tolua_MoviePlayer_MoviePlayer_hasAlpha00);
   tolua_function(tolua_S,"hasVisuals",tolua_MoviePlayer_MoviePlayer_hasVisuals00);
   tolua_function(tolua_S,"hasAudio",tolua_MoviePlayer_MoviePlayer_hasAudio00);
   tolua_function(tolua_S,"getCurrentTime",tolua_MoviePlayer_MoviePlayer_getCurrentTime00);
   tolua_function(tolua_S,"seekToTime",tolua_MoviePlayer_MoviePlayer_seekToTime00);
   tolua_function(tolua_S,"seekToFrame",tolua_MoviePlayer_MoviePlayer_seekToFrame00);
   tolua_function(tolua_S,"seekToStart",tolua_MoviePlayer_MoviePlayer_seekToStart00);
   tolua_function(tolua_S,"seekToEnd",tolua_MoviePlayer_MoviePlayer_seekToEnd00);
   tolua_function(tolua_S,"setActiveSegment",tolua_MoviePlayer_MoviePlayer_setActiveSegment00);
   tolua_function(tolua_S,"resetActiveSegment",tolua_MoviePlayer_MoviePlayer_resetActiveSegment00);
   tolua_function(tolua_S,"setLoop",tolua_MoviePlayer_MoviePlayer_setLoop00);
   tolua_function(tolua_S,"stepForward",tolua_MoviePlayer_MoviePlayer_stepForward00);
   tolua_function(tolua_S,"stepBackward",tolua_MoviePlayer_MoviePlayer_stepBackward00);
   tolua_function(tolua_S,"setRate",tolua_MoviePlayer_MoviePlayer_setRate00);
   tolua_function(tolua_S,"setVolume",tolua_MoviePlayer_MoviePlayer_setVolume00);
   tolua_function(tolua_S,"getVolume",tolua_MoviePlayer_MoviePlayer_getVolume00);
   tolua_function(tolua_S,"isPlaying",tolua_MoviePlayer_MoviePlayer_isPlaying00);
   tolua_function(tolua_S,"isDone",tolua_MoviePlayer_MoviePlayer_isDone00);
   tolua_function(tolua_S,"play",tolua_MoviePlayer_MoviePlayer_play00);
   tolua_function(tolua_S,"stop",tolua_MoviePlayer_MoviePlayer_stop00);
   tolua_function(tolua_S,"draw",tolua_MoviePlayer_MoviePlayer_draw00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_MoviePlayer (lua_State* tolua_S) {
 return tolua_MoviePlayer_open(tolua_S);
};
#endif

