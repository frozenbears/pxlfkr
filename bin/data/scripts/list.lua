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

function list.insert_before_node(l, node, new)
  if node == l.first then
    l.first = new
  else
    node.prev.next = new
    new.prev = node.prev
  end

  new.next = node
  node.prev = new
  return new
end

function list.insert_before(l, node, value)
  local new = {value = value}
  return list.insert_before_node(l, node, new)
end

function list.insert_after_node(l, node, new)
  if node == l.last then
    l.last = new
  else
    node.next.prev = new
    new.next = node.next
  end

  new.prev = node
  node.next = new

  return new
end

function list.insert_after(l, node, value)
  local new = {value = value}
  return list.insert_after_node(l, node, new)
end

function list.replace_node(l, node, new)
  if node == l.last then
    l.last = new
    node.prev.next = new
    new.prev = node.prev
  elseif node == l.first then
    l.first = new
    node.next.prev = new
    new.next = node.next
  else
    node.next.prev = new
    node.prev.next = new
    new.prev = node.prev
    new.next = node.next
  end
  return new
end

function list.replace(l, node, value)
  local new = {prev = node, next = node.next, value = value}
  return list.replace_node(l, node, new)
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
