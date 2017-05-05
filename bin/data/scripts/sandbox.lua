module ("pf.sandbox", package.seeall)

function environment()
  return {
  ipairs = ipairs,
  next = next,
  pairs = pairs,
  pcall = pcall,
  print = print,
  tonumber = tonumber,
  tostring = tostring,
  type = type,
  unpack = unpack,
  coroutine = { create = coroutine.create, resume = coroutine.resume,
      running = coroutine.running, status = coroutine.status,
      wrap = coroutine.wrap },
  string = { byte = string.byte, char = string.char, find = string.find,
      format = string.format, gmatch = string.gmatch, gsub = string.gsub,
      len = string.len, lower = string.lower, match = string.match,
      rep = string.rep, reverse = string.reverse, sub = string.sub,
      upper = string.upper },
  table = { insert = table.insert, maxn = table.maxn, remove = table.remove,
      sort = table.sort },
  math = { abs = math.abs, acos = math.acos, asin = math.asin,
      atan = math.atan, atan2 = math.atan2, ceil = math.ceil, cos = math.cos,
      cosh = math.cosh, deg = math.deg, exp = math.exp, floor = math.floor,
      fmod = math.fmod, frexp = math.frexp, huge = math.huge,
      ldexp = math.ldexp, log = math.log, log10 = math.log10, max = math.max,
      min = math.min, modf = math.modf, pi = math.pi, pow = math.pow,
      rad = math.rad, random = math.random, sin = math.sin, sinh = math.sinh,
      sqrt = math.sqrt, tan = math.tan, tanh = math.tanh },
  os = { clock = os.clock, difftime = os.difftime, time = os.time },
  of = of
}
end

function do_func(env, func, args)
  setfenv(func, env)
  if args then return pcall(func, unpack(args))
  else
    local status, message = pcall(func)
    if not status then print(message) end
    return status, message
  end
end

function inject(env, code)
  local func, message = loadstring(code)

  if not func then
    print(message)
    return nil, message
  end

  return do_func(env, func)
end

function setup(env, ...)
  if env.setup then
    env.setup(...)
  end
end

function update(env, ...)
  if env.update then
    env.update(...)
  end
end

function draw(env, ...)
  if env.draw then
    env.draw(...)
  end
end

function composite(env, ...)
  if env.composite then
    env.composite(...)
  end
end

return pf.sandbox
