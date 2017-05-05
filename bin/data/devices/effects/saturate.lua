
local params = {alpha = {type = "uniform1f", value=1.0}}
local program = shader_program("saturate.vert", "saturate.frag")
bind_program(program, params)
