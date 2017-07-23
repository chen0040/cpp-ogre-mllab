<?php
session_start();

require("mysql_util.php");
require("css_util.php");

function display_normal()
{
	if(isset($_SESSION['username']))
	{
		echo "<html><head><title>ScoreBoard</title>\n";
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
		$tablename="MLLabScoreBoard";

		//connect to database server
		mllab_connect_2_server($address, $username, $password);
		
		//select database
		mysql_select_db($database);
		
		$query1="SELECT * FROM " . $tablename . " WHERE Active='1' AND name='" . $_SESSION['username'] . "' ORDER BY AgentId";
		$result=mysql_query($query1) or die(mysql_error());
		echo mllab_markup_sql_table($result, "color: $000000", array('name', 'AgentId', 'AgentLife', 'AgentScore', 'AgentEnemy', 'AgentState', 'AgentScriptId', 'AgentTag', 'AgentDateTime', 'AgentMilliSecond', 'Active'));
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
	if(isset($_POST['username']) && isset($_POST['AgentId']) && isset($_POST['AgentLife']) && isset($_POST['AgentScore']) && isset($_POST['AgentEnemy']) && isset($_POST['AgentState']) && isset($_POST['AgentScriptId']) && isset($_POST['AgentTag']) && isset($_POST['AgentDateTime']) && isset($_POST['AgentMilliSecond']))
	{
		/*if(!isset($_SESSION['username']))
		{
			echo "Session TimeOut!";
		}
		elseif($_SESSION['username'] == $_POST['username'])
		{*/
			$username="root";
			$password="";
			$address="localhost";
			$database="mysql";
			$tablename="MLLabScoreBoard";

			$name=$_POST['username'];
			$agentId=$_POST['AgentId'];
			$agentLife=$_POST['AgentLife'];
			$agentScore=$_POST['AgentScore'];
			$agentEnemy=$_POST['AgentEnemy'];
			$agentState=$_POST['AgentState'];
			$agentScriptId=$_POST['AgentScriptId'];
			$agentTag=$_POST['AgentTag'];
			$agentDateTime=$_POST['AgentDateTime'];
			$agentMilliSecond=$_POST['AgentMilliSecond'];
			
			//connect to database server
			mllab_connect_2_server($address, $username, $password);
			
			//select database
			mysql_select_db($database);
		
			//delete all past time records
			$query1="DELETE FROM " . $tablename . " WHERE (AgentDateTime != '" . $agentDateTime . "' OR AgentMilliSecond != '" . $agentMilliSecond . "') AND name='" . $name . "'";
			//$query1="UPDATE " . $tablename . " SET Active='0' WHERE Active='1' AND (AgentDateTime != '" . $agentDateTime . "' OR AgentMilliSecond != '" . $agentMilliSecond . "')";
			mysql_query($query1) or die(mysql_error());
			
			$query2="INSERT INTO " . $tablename . " (name, AgentId, AgentLife, AgentScore, AgentEnemy, AgentState, AgentScriptId, AgentTag, AgentDateTime, AgentMilliSecond, Active) VALUES ('" . $name . "', '" . $agentId . "', '" . $agentLife . "', '" . $agentScore . "', '" . $agentEnemy . "', '" . $agentState . "', '" . $agentScriptId . "', '" . $agentTag . "', '" . $agentDateTime . "', '". $agentMilliSecond . "', '1')";
			
			mysql_query($query2) or die(mysql_error());
			
			echo "POST SUCCESSFUL";
		/*}
		else
		{
			echo "Unmatched session and post username!";
		} */
	}
	else
	{
		echo "Unmatch post data type!";
	}
}
?>