<?php
session_start();

require("mysql_util.php");
require("css_util.php");

function display_normal()
{
	if(isset($_SESSION['username']))
	{
		echo "<html><head><title>Bot Config</title>\n";
		echo "<script type=\"text/JavaScript\">\n";
		echo "<!--\n";
		echo "function timedRefresh() {\n";
		echo "location.reload(true);\n";
		echo "}\n";
		echo "window.setInterval(\"timedRefresh()\", 1000);\n";
		echo "//   -->\n";
		echo "</script>\n";
		echo "</head>\n";
		echo "<body>\n";
		
		echo "Server Time: " . date("y-m-d H:i:s") . "\n"; 
		$username="root";
		$password="";
		$address="localhost";
		$database="mysql";
		$tablename="MLLabBotConfig";

		//connect to database server
		mllab_connect_2_server($address, $username, $password);
		
		//select database
		mysql_select_db($database);
		
		$query1="SELECT * FROM " . $tablename . " WHERE name='" . $_SESSION['username'] . "' ORDER BY scriptId";
		$result=mysql_query($query1) or die(mysql_error());
		echo mllab_markup_sql_table($result, "color: $000000", array('name', 'scriptId', 'param', 'value'));
		echo "</body></html>";
	}
	else
	{
		header('location: mllab.php');
	}
}

if(!isset($_POST['username']))
{
	display_normal();
}
else
{
	if(isset($_POST['username']) && isset($_POST['scriptId']))
	{
		$username="root";
		$password="";
		$address="localhost";
		$database="mysql";
		$tablename="MLLabBotConfig";

		$name=$_POST['username'];
		$scriptId=$_POST['scriptId'];
		
		//connect to database server
		mllab_connect_2_server($address, $username, $password);
		
		//select database
		mysql_select_db($database);
	
		//delete all past time records
		foreach($_POST as $key => $value)
		{
			if($key != $name && $key != $scriptId)
			{
				$query1="DELETE FROM " . $tablename . " WHERE param = '" . $key . "' AND name = '" . $name . "' AND scriptId='" . $scriptId . "'";
				mysql_query($query1) or die(mysql_error());
				
				$query2="INSERT INTO " . $tablename . " (name, scriptId, param, value) VALUES ('" . $name . "', '" . $scriptId . "', '" . $key . "', '" . $value . "')";
		
				mysql_query($query2) or die(mysql_error());
			}
		}
		
		echo "POST SUCCESSFUL";
	}
	else
	{
		echo "Unmatch post data type!";
	}
}
?>