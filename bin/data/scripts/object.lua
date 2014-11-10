module('pf', package.seeall)

Object = {}

function Object:new(o)
  o = o or {}
  setmetatable(o, self)
  self.__index = self
  return o
end

