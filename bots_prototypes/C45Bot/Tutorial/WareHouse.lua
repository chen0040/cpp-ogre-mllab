local WareHouse={};
WareHouse.__index=WareHouse;

function WareHouse.create(scriptClassPath)
	local wh={};
	setmetatable(wh, WareHouse);
	
	
	wh.scriptClassPath=scriptClassPath;
	wh.records={};
	
	local recordFactory=dofile(scriptClassPath .. "\\Record.lua");
	wh.records[1]=recordFactory.create();
	wh.records[1]:setAttribute("outlook", "Sunny");
	wh.records[1]:setAttribute("temperature", "greater than or equal to 75");
	wh.records[1]:setAttribute("humidity", "smaller than 80");
	wh.records[1]:setAttribute("windy", "true");
	wh.records[1]:setAttribute("class", "Play");
	
	wh.records[2]=recordFactory.create();
	wh.records[2]:setAttribute("outlook", "Sunny");
	wh.records[2]:setAttribute("temperature", "greater than or equal to 75");
	wh.records[2]:setAttribute("humidity", "greater than or equal to 80");
	wh.records[2]:setAttribute("windy", "true");
	wh.records[2]:setAttribute("class", "Dont");
	
	wh.records[3]=recordFactory.create();
	wh.records[3]:setAttribute("outlook", "Sunny");
	wh.records[3]:setAttribute("temperature", "greater than or equal to 75");
	wh.records[3]:setAttribute("humidity", "greater than or equal to 80");
	wh.records[3]:setAttribute("windy", "false");
	wh.records[3]:setAttribute("class", "Dont");
	
	wh.records[4]=recordFactory.create();
	wh.records[4]:setAttribute("outlook", "Sunny");
	wh.records[4]:setAttribute("temperature", "smaller than 75");
	wh.records[4]:setAttribute("humidity", "greater than or equal to 80");
	wh.records[4]:setAttribute("windy", "true");
	wh.records[4]:setAttribute("class", "Dont");
	
	wh.records[5]=recordFactory.create();
	wh.records[5]:setAttribute("outlook", "Sunny");
	wh.records[5]:setAttribute("temperature", "smaller than 75");
	wh.records[5]:setAttribute("humidity", "smaller than 80");
	wh.records[5]:setAttribute("windy", "false");
	wh.records[5]:setAttribute("class", "Play");
	
	wh.records[6]=recordFactory.create();
	wh.records[6]:setAttribute("outlook", "Overcast");
	wh.records[6]:setAttribute("temperature", "smaller than 75");
	wh.records[6]:setAttribute("humidity", "greater than or equal to 80");
	wh.records[6]:setAttribute("windy", "true");
	wh.records[6]:setAttribute("class", "Play");
	
	wh.records[7]=recordFactory.create();
	wh.records[7]:setAttribute("outlook", "Overcast");
	wh.records[7]:setAttribute("temperature", "greater than or equal to 75");
	wh.records[7]:setAttribute("humidity", "smaller than 80");
	wh.records[7]:setAttribute("windy", "false");
	wh.records[7]:setAttribute("class", "Play");
	
	wh.records[8]=recordFactory.create();
	wh.records[8]:setAttribute("outlook", "Overcast");
	wh.records[8]:setAttribute("temperature", "smaller than 75");
	wh.records[8]:setAttribute("humidity", "smaller than 80");
	wh.records[8]:setAttribute("windy", "true");
	wh.records[8]:setAttribute("class", "Play");
	
	wh.records[9]=recordFactory.create();
	wh.records[9]:setAttribute("outlook", "Overcast");
	wh.records[9]:setAttribute("temperature", "greater than or equal to 75");
	wh.records[9]:setAttribute("humidity", "smaller than 80");
	wh.records[9]:setAttribute("windy", "false");
	wh.records[9]:setAttribute("class", "Play");
	
	wh.records[10]=recordFactory.create();
	wh.records[10]:setAttribute("outlook", "Rain");
	wh.records[10]:setAttribute("temperature", "smaller than 75");
	wh.records[10]:setAttribute("humidity", "greater than or equal to 80");
	wh.records[10]:setAttribute("windy", "true");
	wh.records[10]:setAttribute("class", "Dont");
	
	wh.records[11]=recordFactory.create();
	wh.records[11]:setAttribute("outlook", "Rain");
	wh.records[11]:setAttribute("temperature", "smaller than 75");
	wh.records[11]:setAttribute("humidity", "smaller than 80");
	wh.records[11]:setAttribute("windy", "true");
	wh.records[11]:setAttribute("class", "Dont");
	
	wh.records[12]=recordFactory.create();
	wh.records[12]:setAttribute("outlook", "Rain");
	wh.records[12]:setAttribute("temperature", "greater than or equal to 75");
	wh.records[12]:setAttribute("humidity", "greater than or equal to 80");
	wh.records[12]:setAttribute("windy", "false");
	wh.records[12]:setAttribute("class", "Play");
	
	wh.records[13]=recordFactory.create();
	wh.records[13]:setAttribute("outlook", "Rain");
	wh.records[13]:setAttribute("temperature", "smaller than 75");
	wh.records[13]:setAttribute("humidity", "greater than or equal to 80");
	wh.records[13]:setAttribute("windy", "false");
	wh.records[13]:setAttribute("class", "Play");

	wh.records[14]=recordFactory.create();
	wh.records[14]:setAttribute("outlook", "Rain");
	wh.records[14]:setAttribute("temperature", "smaller than 75");
	wh.records[14]:setAttribute("humidity", "greater than or equal to 80");
	wh.records[14]:setAttribute("windy", "false");
	wh.records[14]:setAttribute("class", "Play");
	
	local attrFactory=dofile(scriptClassPath .. "\\Attribute.lua");
	wh.attributes={};
	wh.attributes[1]=attrFactory.create("outlook");
	wh.attributes[1]:addValue("Sunny");
	wh.attributes[1]:addValue("Rain");
	wh.attributes[1]:addValue("Overcast");
				
	wh.attributes[2]=attrFactory.create("temperature");
	wh.attributes[2]:addValue("smaller than 75");
	wh.attributes[2]:addValue("greater than or equal to 75");
	
	wh.attributes[3]=attrFactory.create("humidity");
	wh.attributes[3]:addValue("smaller than 80");
	wh.attributes[3]:addValue("greater than or equal to 80");
	
	wh.attributes[4]=attrFactory.create("windy");
	wh.attributes[4]:addValue("true");
	wh.attributes[4]:addValue("false");
	
	wh.classAttribute=attrFactory.create("class");
	wh.classAttribute:addValue("Play");
	wh.classAttribute:addValue("Dont");
	
	return wh;
end

function WareHouse:getClassAttribute()
	return self.classAttribute;
end

function WareHouse:getRecord(index)
	return self.records[index];
end

function WareHouse:getAttribute(index)
	return self.attributes[index];
end

function WareHouse:getRecordCount()
	return (# self.records);
end

function WareHouse:getAttributeCount()
	return (# self.attributes);
end

return WareHouse;
