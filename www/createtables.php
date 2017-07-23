<?php
require("mysql_util.php");
require("css_util.php");
function createMLLabLogin($database)
{
	$tablename="MLLabLogin";
	//create table if not exists or clear table if already exist
	$fields['id']='INT NOT NULL AUTO_INCREMENT';
	$fields['name']='VARCHAR(30)';
	$fields['password']='VARCHAR(30)';
	$fields['clearance']='INT';
	$primary_key='id';
	mllab_create_table($database, $tablename, $fields, $primary_key);
	//echo mllab_markup_div_with_style($tablename . " table is created in mysql database", "color: #00ff00") . "<br />";

	//insert admin account
	mllab_insert_into_table("MLLabLogin", array('name', 'password', 'clearance'), array('xianshun', '123123', '0'));
}

function createMLLabScoreBoard($database)
{
	$tablename="MLLabScoreBoard";
	//create table if not exists or clear table if already exist
	$fields['id']='INT NOT NULL AUTO_INCREMENT';
	$fields['name']='VARCHAR(30)';
	$fields['AgentId']='VARCHAR(30)';
	$fields['AgentLife']='INT';
	$fields['AgentScore']='FLOAT(7, 4)';
	$fields['AgentEnemy']='VARCHAR(30)';
	$fields['AgentState']='VARCHAR(30)';
	$fields['AgentScriptId']='VARCHAR(30)';
	$fields['AgentTag']='VARCHAR(30)';
	$fields['AgentDateTime']='DATETIME';
	$fields['Active']='INT';
	$fields['AgentMilliSecond']='INT';
	$primary_key='id';
	mllab_create_table($database, $tablename, $fields, $primary_key);
	//echo mllab_markup_div_with_style($tablename . " table is created in mysql database", "color: #00ff00") . "<br />";
}

function createMLLabBotConfig($database)
{
	$tablename="MLLabBotConfig";
	//create table if not exists or clear table if already exist
	$fields['id']='INT NOT NULL AUTO_INCREMENT';
	$fields['name']='VARCHAR(30)';
	$fields['param']='VARCHAR(30)';
	$fields['value']='VARCHAR(30)';
	$fields['scriptId']='VARCHAR(30)';
	$primary_key='id';
	mllab_create_table($database, $tablename, $fields, $primary_key);
}
?>
<html>
<head><title>Create MLLab Tables</title></head>
<body style="background-color: #000000; color: #00ff00" >
<?php
$failed=true;
if(isset($_POST['post_back']) && isset($_POST['username']) && isset($_POST['password']))
{
	$username=$_POST['username'];
	$password=$_POST['password'];
	
	if($username=='xianshun' && $password=='123123')
	{
		$failed=FALSE;
	}
}

if($failed==TRUE)
{
	echo "<form action=\"" . basename($_SERVER['PHP_SELF']) . "\" method=\"post\">";
	echo "Administrator: <input type=\"text\" name=\"username\" value=\"xianshun\" /> <br />";
	echo "Password: <input type=\"password\" name=\"password\" /> <br />";
	if(isset($_POST['post_back']))
	{
		echo "<hr />";
		echo "<h2>Incorrect login details!</h2>";
	}
	echo "<hr />";
	echo "<h2>By clicking confirm, the tables selected below will be created in mysql database</h2>";
	echo mllab_markup_div_with_style("<h3>Warning: if a table is already existing, it is will deleted and rebuilt; Proceed with caution<h3>", "color: #ff0000") . "<hr />";
	echo "<input type=\"checkbox\" name=\"MLLabLogin\" value=\"yes\" /> Create MLLabLogin table<br />";
	echo "<input type=\"checkbox\" name=\"MLLabScoreBoard\" value=\"yes\" /> Create MLLabScoreBoard table<br />";
	echo "<input type=\"checkbox\" name=\"MLLabBotConfig\" value=\"yes\" /> Create MLLabBotConfig table<br />";
	echo "<input type=\"submit\" name=\"post_back\" value=\"Confirm\" />";
	echo "</form>";
}
else
{
	$username="root";
	$password="";
	$address="localhost";
	$database="mysql";

	//connect to database server
	mllab_connect_2_server($address, $username, $password);
	
	echo "<ul>";
	if(isset($_POST['MLLabLogin']))
	{
		createMLLabLogin($database);
		echo "<li>MLLabLogin created!";
	}
	
	if(isset($_POST['MLLabScoreBoard']))
	{
		createMLLabScoreBoard($database);
		echo "<li>MLLabScoreBoard created!";
	}
	
	if(isset($_POST['MLLabBotConfig']))
	{
		createMLLabBotConfig($database);
		echo "<li>MLLabBotConfig created!";
	}
	echo "</ul>";
	echo "<hr />";

	if(isset($_POST['MLLabLogin']))
	{
		//print accounts in MLLabLogin
		echo mllab_markup_div_with_style("MLLabLogin table content", "color: #00ff00") . "<br />";
		$accounts=mllab_select_from_table("MLLabLogin", array('name', 'password', 'clearance'), "");
		echo mllab_markup_sql_table($accounts, "color: #00ff00", array('name', 'password', 'clearance'));
	}

	mllab_disconnect();
}
?>
</body>
</html>