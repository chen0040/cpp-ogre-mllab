<?php
session_start();

$page='';
if(isset($_SESSION['current_request']))
{
	$page=$_SESSION['current_request'];
}

unset($_SESSION['username']);

if($page=='')
{
	header('location: mllab.php');
}
else
{
	header('location: ' . $page);
}
?>