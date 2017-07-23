<?php
session_start();

require("mysql_util.php");
require("css_util.php");
require("mllabhead.php");
require("mllabbody.php");

$loginStatus=false;

if(isset($_SESSION['username']))
{
	$loginStatus=true;
}

if($loginStatus==true)
{
	mllabhead("");
	echo "<body>";
	$content="<ul><li><a href=\"mllabappdownload.php\">MLLab Download</a><li><a href=\"mllabmandownload.php\">MLLab Manual Download</a></ul>";
	mllabbody("MLLab Download links", $content);
	echo "</body></html>";
}
else
{
	$_SESSION['current_request']='mllabdownload.php';
	header('location: mllab.php');
}
?>