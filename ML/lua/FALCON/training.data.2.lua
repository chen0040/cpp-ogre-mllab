data={};

function data.print()
	for i=1, 20 do
		for j=1, 3 do
			print("data[" .. i .. "].states[" .. j .. "] = " .. data[i].states[j]);
		end
		print("data[" .. i .. "].action = " .. data[i].action);
		print("///////////////////////////////////////////");
	end
end

function data.size()
	return 20;
end

function data.getStateSize()
	return 3;
end

function data.getActionSize()
	return 3;
end

data[1]={};
data[1].states={};
data[1].states[1]=0.17339673890941742;
data[1].states[2]=0.4692211121956644;
data[1].states[3]=0.6118624780401619;

data[2]={};
data[2].states={};
data[2].states[1]=0.4345522632434815;
data[2].states[2]=0.37384127626732866;
data[2].states[3]=0.08995624192736396;

data[3]={};
data[3].states={};
data[3].states[1]=0.5257165932590587;
data[3].states[2]=0.3102404509079232;
data[3].states[3]=0.8376538467824642;

data[4]={};
data[4].states={};
data[4].states[1]=0.2406379685017247;
data[4].states[2]=0.03666139948508451;
data[4].states[3]=0.795696072409079;

data[5]={};
data[5].states={};
data[5].states[1]=0.9831272752590662;
data[5].states[2]=0.1906020730838658;
data[5].states[3]=0.011456891974850447;

data[6]={};
data[6].states={};
data[6].states[1]=0.26968175188563515;
data[6].states[2]=0.9548129808444301;
data[6].states[3]=0.9364675996561578;

data[7]={};
data[7].states={};
data[7].states[1]=0.5716104609712392;
data[7].states[2]=0.7294069149480339;
data[7].states[3]=0.3216014803715048;

data[8]={};
data[8].states={};
data[8].states[1]=0.02403684636872183;
data[8].states[2]=0.3944831111510476;
data[8].states[3]=0.6764865553110722;

data[9]={};
data[9].states={};
data[9].states[1]=0.09447924833173049;
data[9].states[2]=0.3077994276343844;
data[9].states[3]=0.7289240785006561;

data[10]={};
data[10].states={};
data[10].states[1]=0.22024347509513442;
data[10].states[2]=0.9642609422942081;
data[10].states[3]=0.9450677022056018;

data[11]={};
data[11].states={};
data[11].states[1]=0.7039549535188925;
data[11].states[2]=0.15876014452790943;
data[11].states[3]=0.24260418832936503;

data[12]={};
data[12].states={};
data[12].states[1]=0.6375917937328514;
data[12].states[2]=0.17015834322863832;
data[12].states[3]=0.7170323793451933;

data[13]={};
data[13].states={};
data[13].states[1]=0.9788712380447;
data[13].states[2]=0.5055722369939716;
data[13].states[3]=0.8808082515633038;

data[14]={};
data[14].states={};
data[14].states[1]=0.6967717163149654;
data[14].states[2]=0.12091031588855583;
data[14].states[3]=0.007308723438917641;

data[15]={};
data[15].states={};
data[15].states[1]=0.29341215717032754;
data[15].states[2]=0.023848884365195056;
data[15].states[3]=0.3895867498207978;

data[16]={};
data[16].states={};
data[16].states[1]=0.0022939723737634976;
data[16].states[2]=0.6522181152332344;
data[16].states[3]=0.06706633102125559;

data[17]={};
data[17].states={};
data[17].states[1]=0.7449022256586455;
data[17].states[2]=0.39638159944764584;
data[17].states[3]=0.2983724515275905;

data[18]={};
data[18].states={};
data[18].states[1]=0.6458926410964855;
data[18].states[2]=0.9357979074400268;
data[18].states[3]=0.8047278547518646;

data[19]={};
data[19].states={};
data[19].states[1]=0.3467967344488997;
data[19].states[2]=0.3449873371431428;
data[19].states[3]=0.6462453323311261;

data[20]={};
data[20].states={};
data[20].states[1]=0.32152654678019044;
data[20].states[2]=0.9674852438682547;
data[20].states[3]=0.6097897124620485;

data[1].action=2;
data[2].action=0;
data[3].action=2;
data[4].action=2;
data[5].action=0;
data[6].action=1;
data[7].action=1;
data[8].action=2;
data[9].action=2;
data[10].action=1;
data[11].action=0;
data[12].action=2;
data[13].action=0;
data[14].action=0;
data[15].action=2;
data[16].action=1;
data[17].action=0;
data[18].action=1;
data[19].action=2;
data[20].action=1;


return data;
