<?php
session_start();

require("mysql_util.php");
require("css_util.php");
require("mllabhead.php");
require("mllabbody.php");

if(isset($_SESSION['username']))
{	
	$script = "<script type=\"text/JavaScript\">\n";
	$script = $script . "<!--\n";
	$script = $script . "function timedRefresh() {\n";
	$script = $script . "location.reload(true);\n";
	$script = $script . "}\n";
	$script = $script . "window.setInterval(\"timedRefresh()\", 1000);\n";
	$script = $script . "//   -->\n";
	$script = $script . "</script>\n";
	mllabhead($script);
	echo "<body bgcolor=\"#FFFFFF\" leftmargin=\"0\" topmargin=\"0\" marginwidth=\"0\" marginheight=\"0\">\n";
	
	$username="root";
	$password="";
	$address="localhost";
	$database="mysql";
	$tablename="MLLabScoreBoard";

	//connect to database server
	mllab_connect_2_server($address, $username, $password);
	
	//select database
	mysql_select_db($database);
	
	$query1="SELECT * FROM " . $tablename . " WHERE Active='1' AND name='" . $_SESSION['username'] . "' ORDER BY AgentId";
	$result=mysql_query($query1) or die(mysql_error());
	$content= mllab_markup_sql_table($result, "color: $000000", array('name', 'AgentId', 'AgentLife', 'AgentScore', 'AgentEnemy', 'AgentState', 'AgentScriptId', 'AgentTag', 'AgentDateTime', 'AgentMilliSecond', 'Active'));
	mllabbody("MLLab Score Board", $content);
	echo "</body></html>";
}
else
{
	header('location: mllab.php');
}
?>

