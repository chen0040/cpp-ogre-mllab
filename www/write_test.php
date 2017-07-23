<html>
<head>
<title>cUrl Unit Test</title>
</head>

<body>
<?php echo "Hello World\n" ?>
<?php 
$username=$_POST['username'];
$password=$_POST['password'];

$filename="data.txt";
$filehandler=null;
If(file_exists($filename)) 
{
	$filehandler=fopen($filename, 'a') or die('cannot open file');
}
Else
{
	$filehandler=fopen($filename, 'w') or die('cannot create file');
}

fwrite($filehandler, "username: " . $username . "\n");
fwrite($filehandler, "password: " . $password . "\n");
fwrite($filehandler, "");

fclose($filehandler);
?>
</body>