<?php
session_start();
require("mysql_util.php");

if(isset($_POST['username']) && isset($_POST['password']))
{	
	if(isset($_SESSION['username']))
	{
		unset($_SESSION['username']);
	}
	
	$username=$_POST['username'];
	$password=$_POST['password'];
	if(validate($username, $password)==TRUE)
	{
		$_SESSION['username']=$username;
		echo "LOGIN SUCCESSFUL";
	}
	else
	{
		echo "Invalide account";
	}
}
else
{
	
	echo "<html><body style=\"background-color: #000000; color: #00ff00\">";
	echo "<h3>You are viewing the non-MLLab interaction page!</h3><hr />";
	echo "<form action=\"" . basename($_SERVER['PHP_SELF']) . "\" method=\"post\">";
	echo "Username: <input type=\"text\" name=\"username\" /><br />";
	echo "Password: <input type=\"text\" name=\"password\" /><br />";
	echo "<input type=\"submit\" name=\"submit\" value=\"login\" />";
	echo "</form>";
	echo "</body></html>";
}

function validate($username, $password)
{
	mllab_connect_2_server("localhost", "root", "");
	mysql_select_db("mysql") or die(mysql_error());
	$accounts=mllab_select_from_table("MLLabLogin", array('COUNT(name)'), "WHERE name='" . $username . "' AND password='" . $password . "'");
	$valid=FALSE;
	$rows = mysql_fetch_array($accounts) or die(mysql_error());
	if($rows['COUNT(name)']==0)
	{
		$valid=FALSE;
	}
	else
	{
		$valid=TRUE;
	}
	mllab_disconnect();
	return $valid;
}

?>