<?php
function mllabhead($script)
{
	echo "
	<html>
	<head>
	<title>MLLab Home</title>
	<meta http-equiv=\"Content-Type\" content=\"text/html; charset=windows-1251\">
	<link href=\"style.css\" rel=\"stylesheet\" type=\"text/css\">
	";
	echo $script;
	echo "</head>";
}
?>