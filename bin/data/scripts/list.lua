
local list = {}

function list.has_node(l, node)
  for n in list.nodes(l) do
    if n == node then return true end
  end
  return false
end

function list.prepend_node(l, node)
  if not l.first then
    l.first = node
    l.last = node
  else
    l.first.prev = node
    node.next = l.first
    l.first = node
  end
  return node
end

function list.prepend(l, value)
  local node = {value = value}
  return list.prepend_node(l, node)
end

function list.append_node(l, node)
  if not l.last then
    l.last = node
    l.first = node
  else
    l.last.next = node
    node.prev = l.last
    l.last = node
  end
  return node
end

function list.append(l, value)
  local node = {value = value}
  return list.append_node(l, node) 
end

function list.pop_node(l)
  local node = l.last
  list.delete_node(l, node)
  return node
end

function list.pop(l)
  return list.pop_node(l).value
end

function list.take_node(l)
  local node = l.first
  list.delete_node(l, node)
  return node
end

function list.take(l)
  return list.take_node(l).value
end

function list.insert_after_node(l, node, new)
  node.next = new
  if node == l.last then
    l.last = new
  else
    new.next.prev = new
  end
  return new
end

function list.insert_after(l, node, value)
  local new = {prev = node, next = node.next, value = value}
  return list.insert_after_node(l, node, new)
end

function list.delete_node(l, node)
  if not list.has_node(l, node) then
    error("it's not in the thing!!11")
  end
  if node == l.first then
    l.first = node.next
  else
    if node.prev then
      node.prev.next = node.next
    end
  end

  if node == l.last then
    l.last = node.prev
  else
    if node.next then
      node.next.prev = node.prev
    end
  end
  node.next = nil
  node.prev = nil
end

function list.next(l, node)
  return (not node and l.first) or node.next
end

function list.nodes(l)
  local node = l.first
  return function()
    local cur = node
    if cur then
      node = list.next(l, node)
      return cur
    else
      return nil
    end
  end
end

function list.values(l)
  local iter = list.nodes(l)
  return function()
    local node = iter()
    return node and node.value
  end
end

return list

