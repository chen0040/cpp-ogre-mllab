local CategoryField={};
CategoryField.__index=CategoryField;

function CategoryField.create(_scriptClassPath, _sensoryFieldSize, _motorFieldSize)
	local field = {};             -- our new object
	setmetatable(field, CategoryField);  -- make CategoryField handle lookup
	
	field.scriptClassPath=_scriptClassPath;
	field.sensoryFieldSize=_sensoryFieldSize;
	field.motorFieldSize=_motorFieldSize;
	
	field.nodeCount=1;
	field.nodes={};
	local categoryNodeFactory=dofile(_scriptClassPath .. "\\CategoryNode.lua");
	field.nodes[1]=categoryNodeFactory.create(_sensoryFieldSize, _motorFieldSize);

	return field;
end

function CategoryField:size()
	return self.nodeCount;
end

function CategoryField:createNode()
	self.nodeCount=self.nodeCount + 1;
	local categoryNodeFactory=dofile(self.scriptClassPath .. "\\CategoryNode.lua");
	self.nodes[self.nodeCount]=categoryNodeFactory.create(self.sensoryFieldSize, self.motorFieldSize);
end

function CategoryField:getNode(_index)
	return self.nodes[_index];
end

return CategoryField;