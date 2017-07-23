<?php
session_start();

require("mysql_util.php");
require("css_util.php");
require("mllabhead.php");
require("mllabbody.php");

$loginStatus=false;
$isAdmin=false;

function getLoginTable()
{
	mllab_connect_2_server("localhost", "root", "");
	mysql_select_db("mysql");
	$query="SELECT * FROM MLLabLogin";
	$result=mysql_query($query) or die(mysql_error());
	$content = "";
	$content = $content . "<table border=\"1\">";
	$content = $content . "<tr ><td style=\"font-weight:bold\">Username</td><td style=\"font-weight:bold\">Password</td><td style=\"font-weight:bold\">Clearance</td></tr>";
	while($row=mysql_fetch_array($result))
	{
		$content = $content . "<tr>";
		$content = $content . "<td>" . $row['name'] . "</td>";
		$content = $content . "<td>" . $row['password'] . "</td>";
		$content = $content . "<td>" . $row['clearance'] . "</td>";
		$content = $content . "</tr>";
	}
	$content = $content . "</table>"; 
	mllab_disconnect();
	return $content;
}

function getAdminForm()
{
	$content = "";
	$content = $content . "<form action=\"" . basename($_SERVER['PHP_SELF']) . "\" method=\"post\">";
	$content = $content . "<hr />Admin Account Manager: <br />";
	$content = $content . "<ul>";
	$content = $content . "<li>ADD: enter username, password, clearance (0 for admin; 1 for normal), and click <strong>Add</strong> button";
	$content = $content . "<li>DEL: enter username, and click <strong>Delele</strong> button";
	$content = $content . "</ul>";
	$content = $content . "<table>";
	$content = $content . "<tr><td>Username: </td><td><input type=\"text\" name=\"username\" /></td></tr>";
	$content = $content . "<tr><td>Password: </td><td><input type=\"password\" name=\"password\" /></tr>";
	$content = $content . "<tr><td>Clearance (admin: 0): </td><td><input type=\"text\" name=\"clearance\" value=\"1\" /></tr>"; 
	$content = $content . "<tr><td colspan=\"2\"><input type=\"submit\" name=\"ADDACCOUNT\" value=\"Add\" />";
	$content = $content . "<input type=\"submit\" name=\"DELACCOUNT\" value=\"Delete\" /><input type=\"submit\" name=\"CONFIG\" value=\"Config\" /></tr>";
	$content = $content . "</table>";
	$content = $content . "</form>";
	
	return $content;
}

function isRepeatedAccount($username)
{
	$repeated=true;
	
	mllab_connect_2_server("localhost", "root", "");
	mysql_select_db("mysql");
	$query="SELECT COUNT(name) FROM MLLabLogin WHERE name='" . $username . "'";
	$result=mysql_query($query) or die(mysql_error());
	$row=mysql_fetch_array($result);
	if($row['COUNT(name)']==0)
	{
		$repeated=false;
	}
	mllab_disconnect();
	return $repeated;
}

function addAccount($username, $password, $clearance)
{
	mllab_connect_2_server("localhost", "root", "");
	mysql_select_db("mysql");
	$query="INSERT INTO MLLabLogin (name, password, clearance) VALUES ('" . $username . "', '" . $password . "', '" . $clearance . "')";
	mysql_query($query) or die(mysql_error());
	mllab_disconnect();
}

function accountExists($username)
{
	if(isRepeatedAccount($username))
	{
		return true;
	}
	else
	{
		return false;
	}
}

function delAccount($username)
{
	mllab_connect_2_server("localhost", "root", "");
	mysql_select_db("mysql");
	$query="DELETE FROM MLLabLogin where name='" . $username . "'";
	mysql_query($query) or die(mysql_error());
	mllab_disconnect();
}

function configAccount($username, $password, $clearance)
{
	mllab_connect_2_server("localhost", "root", "");
	mysql_select_db("mysql");
	$query="UPDATE MLLabLogin SET password='" . $password . "', clearance='" . $clearance . "' WHERE name='" . $username . "'";
	mysql_query($query) or die(mysql_error());
	mllab_disconnect();
}

if(isset($_SESSION['username']))
{
	$loginStatus=true;
	
	mllab_connect_2_server("localhost", "root", "");
	mysql_select_db("mysql");
	$query="SELECT clearance FROM MLLabLogin WHERE name='" . $_SESSION['username'] . "'";
	$result=mysql_query($query) or die(mysql_error());
	$row=mysql_fetch_array($result) or die(mysql_error());
	if($row['clearance'] == 0)
	{
		$isAdmin=true;
	}
	mllab_disconnect();
}

if($loginStatus==true)
{
	if($isAdmin==true)
	{
		mllabhead("");
		echo "<body>";
		$content = "";
		if(isset($_POST['ADDACCOUNT']))
		{
			if(isset($_POST['username']) && isset($_POST['password']))
			{
				$username=$_POST['username'];
				$password=$_POST['password'];
				$clearance=1;
				if(isset($_POST['clearance']))
				{
					$clearance=$_POST['clearance'];
				}
				if($username=='' or $password=='' or isRepeatedAccount($username))
				{
					$content=$content . "<hr />ADD: Invalid username or password<hr />";
				}
				else
				{
					addAccount($username, $password, $clearance);
				}
			}
		}
		elseif(isset($_POST['DELACCOUNT']))
		{
			if(isset($_POST['username']))
			{
				$username=$_POST['username'];
				if($username=='' or accountExists($username)==false)
				{
					$content=$content . "<hr />DEL: Invalid username<hr />";
				}
				else
				{
					delAccount($username);
				}
			}
		}
		elseif(isset($_POST['CONFIG']))
		{
			if(isset($_POST['username']) && isset($_POST['password']) && isset($_POST['clearance']))
			{
				$username=$_POST['username'];
				$password=$_POST['password'];
				$clearance=$_POST['clearance'];
				if($username=='' or $password=='' or accountExists($username)==false)
				{
					$content=$content . "<hr />CONFIG: Invalid username or password or clearance<hr />";
				}
				else
				{
					configAccount($username, $password, $clearance);
				}
			}
		}
		
		$content=$content . getLoginTable();
		$content=$content . getAdminForm();
		
		
		
		mllabbody("Administrator Panel", $content);
		echo "</body></html>";
	}
	else
	{
		mllabhead("");
		echo "<body>";
		mllabbody("Acess Denied", "You do not have enough clearance to access Administrator panel");
		echo "</body></html>";
	}
}
else
{
	$_SESSION['current_request']='mllabdownload.php';
	header('location: mllab.php');
}
?>