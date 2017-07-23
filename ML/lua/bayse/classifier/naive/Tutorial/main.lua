dofile("GameUtil.lua");
dofile("GameWorld.lua");

local wareHouseFactory=dofile(getDefaultScriptPath() .. "\\WareHouse.lua");
local wareHouse=wareHouseFactory.create(getDefaultScriptPath());

local nbcFactory=dofile(getDefaultScriptPath() .. "\\NaiveBayseClassifier.lua");
classifier=nbcFactory.create();

--build C45
local records={};
for recordIndex=1, wareHouse:getRecordCount() do
	records[recordIndex]=wareHouse:getRecord(recordIndex);
end
	
for recordIndex=1, wareHouse:getRecordCount() do
	local predicted=classifier:predict(records[recordIndex], records, wareHouse:getClassAttribute());
	local recorded=records[recordIndex]:getAttributeValue("class");
	print2Console("recorded: " .. recorded .. "\tpredicted: " .. predicted);
end