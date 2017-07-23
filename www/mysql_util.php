<?php 
function mllab_table_exists($database, $table)
{
	$tables=mysql_list_tables($database) or die(mysql_error());
	while(list($temp)=mysql_fetch_array($tables))
	{
		if(strtolower($temp) == strtolower($table))
		{
			return TRUE;
		}
	}
	return FALSE;
}

function mllab_connect_2_server($address, $username, $password)
{
	if($password=='')
	{
		$password='chen0469';
	}
	mysql_connect($address, $username, $password) or die(mysql_error());
}

function mllab_delete_table($database, $table_name)
{
	mysql_select_db($database) or die(mysql_error());
	$query="DROP TABLE " . $table_name;
	mysql_query($query) or die(mysql_error());
}

function mllab_create_table($database, $table_name, $fields, $primary_key)
{
	if(mllab_table_exists($database, $table_name)==TRUE)
	{
		mllab_delete_table($database, $table_name);
	}
	mysql_select_db($database) or die(mysql_error());
	$query="CREATE TABLE " . $table_name . " (";
	foreach($fields as $key => $detail)
	{
		$query=$query . $key . " " . $detail . ", ";
		if($key==$primary_key)
		{
			$query=$query . "PRIMARY KEY(" . $key . "), ";
		}
	}
	$query=substr_replace($query, ")", -2);
	//echo $query;
	
	mysql_query($query) or die(mysql_error());
}

function mllab_insert_into_table($table_name, $keys, $values)
{
	$query="INSERT INTO " . $table_name . " (";
	foreach($keys as $key)
	{
		$query=$query . $key . ", ";
	}
	$query=substr_replace($query, ")", -2);
	$query=$query . " VALUES (";
	foreach($values as $value)
	{
		$query=$query . "'" . $value . "', ";
	}
	$query=substr_replace($query, ")", -2);
	//echo $query;
	mysql_query($query) or die(mysql_error());
}

function mllab_select_from_table($table_name, $keys, $criteria)
{
	$query="SELECT ";
	if(count($keys) == 0)
	{
		$query=$query . "*";
	}
	else
	{
		foreach($keys as $key)
		{
			$query=$query . $key . ", ";
		}
	}
	$query=substr_replace($query, "", -2);
	$query=$query . " FROM " . $table_name;
	if($criteria != "")
	{
		$query=$query . " " . $criteria;
	}
	//echo $query;
	$result=mysql_query($query) or die(mysql_error());
	
	return $result;
}

function mllab_disconnect()
{
	mysql_close();
}

function mllab_test_1()
{
	mllab_connect_2_server("localhost", "root", "");

	$fields['id']='INT NOT NULL AUTO_INCREMENT';
	$fields['name']='VARCHAR(30)';
	$fields['passworld']='VARCHAR(30)';
	$fields['clearance']='INT';
	mllab_create_table("mysql", "MLLabLogin", $fields, 'id');
}

function mllab_test_2()
{
	mllab_connect_2_server("localhost", "root", "");
	if(mllab_table_exists("mysql", "MLLabLogin"))
	{
		mysql_select_db("mysql");
	}
	else
	{
		mllab_test_1();
	}
	
	mllab_insert_into_table("MLLabLogin", array('name', 'password', 'clearance'), array('xianshun', 'xianshun123', '0'));
}

function mllab_test_3()
{
	mllab_connect_2_server("localhost", "root", "");
	if(mllab_table_exists("mysql", "MLLabLogin"))
	{
		mysql_select_db("mysql");
	}
	else
	{
		mllab_test_1();
	}
	
	mllab_select_from_table("MLLabLogin", array('name', 'password', 'clearance'), "");
}

?>