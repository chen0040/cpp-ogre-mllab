dofile("GameUtil.lua");
dofile("GameWorld.lua");

local wareHouseFactory=dofile(getDefaultScriptPath() .. "\\WareHouse.lua");
local wareHouse=wareHouseFactory.create(getDefaultScriptPath());

local decisionTreeFactory=dofile(getDefaultScriptPath() .. "\\DecisionTree.lua");
decisionTree=decisionTreeFactory.create(getDefaultScriptPath(), wareHouse:getClassAttribute());

for i=1, wareHouse:getAttributeCount() do
	decisionTree:addAttribute(wareHouse:getAttribute(i));
end

--build C45
local records={};
for recordIndex=1, wareHouse:getRecordCount() do
	records[recordIndex]=wareHouse:getRecord(recordIndex);
end
decisionTree:build(records);
decisionTree:printXML(getDefaultScriptPath() .. "\\Saved.xml");
	
for recordIndex=1, wareHouse:getRecordCount() do
	local predicted=decisionTree:predict(records[recordIndex]);
	local recorded=records[recordIndex]:getAttributeValue("class");
	print2Console("recorded: " .. recorded .. "\tpredicted: " .. predicted);
end