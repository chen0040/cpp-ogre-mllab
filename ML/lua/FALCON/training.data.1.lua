local data={};

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
data[1].states[1]=0.020584134861644565;
data[1].states[2]=0.84430703535816;
data[1].states[3]=0.020293090816463022;

data[2]={};
data[2].states={};
data[2].states[1]=0.5516730152104838;
data[2].states[2]=0.32969224115784923;
data[2].states[3]=0.8503499527703529;

data[3]={};
data[3].states={};
data[3].states[1]=0.02688579414713932;
data[3].states[2]=0.6255207467850085;
data[3].states[3]=0.26490177816453797;

data[4]={};
data[4].states={};
data[4].states[1]=0.523461355354165;
data[4].states[2]=0.3169154048981794;
data[4].states[3]=0.05598802330742081;

data[5]={};
data[5].states={};
data[5].states[1]=0.24620280401732653;
data[5].states[2]=0.4547553639159312;
data[5].states[3]=0.5227684468904068;

data[6]={};
data[6].states={};
data[6].states[1]=0.7548902556159991;
data[6].states[2]=0.9136290789668937;
data[6].states[3]=0.016954653015587295;

data[7]={};
data[7].states={};
data[7].states[1]=0.6131145482830375;
data[7].states[2]=0.5375180577111565;
data[7].states[3]=0.11205072853339515;

data[8]={};
data[8].states={};
data[8].states[1]=0.024540240977968253;
data[8].states[2]=0.8797367128534926;
data[8].states[3]=0.2127916918322068;

data[9]={};
data[9].states={};
data[9].states[1]=0.84025484514467;
data[9].states[2]=0.22077606150707396;
data[9].states[3]=0.5455249528851243;

data[10]={};
data[10].states={};
data[10].states[1]=0.0737918564973139;
data[10].states[2]=0.2029183362493766;
data[10].states[3]=0.47323058693170394;

data[11]={};
data[11].states={};
data[11].states[1]=0.5171013139798152;
data[11].states[2]=0.8309335928607912;
data[11].states[3]=0.006617345704405531;

data[12]={};
data[12].states={};
data[12].states[1]=0.3260194110043345;
data[12].states[2]=0.7987083213552423;
data[12].states[3]=0.8122768076185715;

data[13]={};
data[13].states={};
data[13].states[1]=0.27480563314445083;
data[13].states[2]=0.6048441084288951;
data[13].states[3]=0.6084071581544915;

data[14]={};
data[14].states={};
data[14].states[1]=0.818943263368606;
data[14].states[2]=0.6217340289338055;
data[14].states[3]=0.10000458416292368;

data[15]={};
data[15].states={};
data[15].states[1]=0.29329548041322107;
data[15].states[2]=0.3683367936801526;
data[15].states[3]=0.12157219539745212;

data[16]={};
data[16].states={};
data[16].states[1]=0.9629131818221075;
data[16].states[2]=0.7273694240325316;
data[16].states[3]=0.18383947002827083;

data[17]={};
data[17].states={};
data[17].states[1]=0.036532060702490154;
data[17].states[2]=0.3432410041637164;
data[17].states[3]=0.9938180547373702;

data[18]={};
data[18].states={};
data[18].states[1]=0.6968838206896575;
data[18].states[2]=0.5265830411917127;
data[18].states[3]=0.9666779446634137;

data[19]={};
data[19].states={};
data[19].states[1]=0.8029525340605216;
data[19].states[2]=0.015777012342150232;
data[19].states[3]=0.2533860789559286;

data[20]={};
data[20].states={};
data[20].states[1]=0.8073896853713673;
data[20].states[2]=0.2776365483752218;
data[20].states[3]=0.2853797760671746;

data[1].action=1;
data[2].action=2;
data[3].action=1;
data[4].action=0;
data[5].action=2;
data[6].action=1;
data[7].action=0;
data[8].action=1;
data[9].action=0;
data[10].action=2;
data[11].action=1;
data[12].action=2;
data[13].action=2;
data[14].action=0;
data[15].action=1;
data[16].action=0;
data[17].action=2;
data[18].action=2;
data[19].action=0;
data[20].action=0;

return data;