<?php
session_start();
require("mysql_util.php");

$loginStatus=false;
$postBack=false;

if(isset($_SESSION['username']))
{
	$loginStatus=true;
}
	
if(isset($_POST['username']) && isset($_POST['password']))
{	
	$postBack=true;
	
	$username=$_POST['username'];
	$password=$_POST['password'];
	if(validate($username, $password)==TRUE)
	{
		$_SESSION['username']=$username;
		$loginStatus=true;
		if(isset($_SESSION['current_request']))
		{
			header('location: ' . $_SESSION['current_request']);
		}
	}
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

<html>
<head>
<title>MLLab Home</title>
<meta http-equiv="Content-Type" content="text/html; charset=windows-1251">
<link href="style.css" rel="stylesheet" type="text/css">
</head>
<body bgcolor="#FFFFFF" leftmargin="0" topmargin="0" marginwidth="0" marginheight="0">
<table width="1000" border="0" align="center" cellpadding="0" cellspacing="0">
  <tr>
    <td><table width="100%" border="0" cellspacing="0" cellpadding="0">
      <tr>
        <td height="33" background="images/index_01.gif"><table width="100%" border="0" cellspacing="5" cellpadding="0">
          <tr>
            <td class="p" width="64%"><table width="100%" border="0" cellspacing="5" cellpadding="0">
              <tr>
                <td width="2%"><img src="images/home.gif" width="12" height="11"></td>
                <td width="98%"> <a href="#">home page</a></td>
              </tr>
            </table></td>
            <td width="36%" align="center">Today's date is <?php echo date('l, F d, Y'); ?></td>
          </tr>
        </table></td>
      </tr>
      <tr>
        <td><img src="images/index_03.jpg" width="1000" height="199" alt=""></td>
      </tr>
      <tr>
        <td><table width="100%" border="0" cellspacing="0" cellpadding="0">
          <tr>
            <td><a href="mllab.php"><img src="images/index_04.gif" alt="" width="171" height="38" border="0"></a></td>
            <td><a href="mllabmanual.php"><img src="images/index_05.gif" alt="" width="110" height="38" border="0"></a></td>
            <td><a href="mllabdownload.php"><img src="images/index_06.gif" alt="" width="126" height="38" border="0"></a></td>
            <td><a href="mllabbotconfig.php"><img src="images/index_07.gif" alt="" width="116" height="38" border="0"></a></td>
            <td><a href="mllabscoreboard.php"><img src="images/index_08.gif" alt="" width="123" height="38" border="0"></a></td>
            <td><a href="mllablogout.php"><img src="images/index_09.gif" alt="" width="114" height="38" border="0"></a></td>
            <td><img src="images/index_10.gif" width="240" height="38" alt=""></td>
          </tr>
        </table></td>
      </tr>
    </table></td>
  </tr>
</table>
<table width="1000" border="0" align="center" cellpadding="0" cellspacing="0">
  <tr>
    <td class="bg1"><table width="100%" border="0" cellspacing="10" cellpadding="0">
      <tr>
        <td width="71%" valign="top" class="bord"><table width="100%" border="0" cellspacing="10" cellpadding="0">
          <tr>
            <td><table width="100%" border="0" cellspacing="5" cellpadding="0">
                <tr>
                  <td width="2%"><img src="images/index_14.gif" width="11" height="11" alt=""></td>
                  <td width="98%"><h2>Welcome to Machine Learning Laboratory (MLLab)</h2></td>
                </tr>
            </table></td>
          </tr>
          <tr>
            <td><table width="100%" border="0" cellspacing="10" cellpadding="0">
                <tr>
                  <td width="3%"><img src="images/index_18.jpg" width="69" height="83" alt=""></td>
                  <td width="97%">
				   <?php
					if($loginStatus==false)
					{
						echo "<form action=\"" . basename($_SERVER['PHP_SELF']) . "\" method=\"post\">";
						echo "<table>";
						echo "<tr>";
						echo "<td>Username: </td><td><input type=\"text\" name=\"username\" /></td>";
						echo "</tr>";
						echo "<td>Password: </td><td><input type=\"password\" name=\"password\" /></td>";
						echo "</tr>";
						if($postBack==true)
						{
							echo "<tr>";
							echo "Invalid acount<br />";
							echo "</tr>";
						}
						echo "<tr>";
						echo "<td colspan=\"2\"><input type=\"submit\" name=\"submit\" value=\"login\" /></td>";
						echo "</tr>";
						echo "</table>";
						echo "</form>";
					}
					else
					{
						echo "<strong>You have successfully login</strong><br />";
						echo "You can proceed to access the following resources<br />";
						echo "<table><tr><td>";
						echo "<ul>";
						echo "<li><a href=\"mllabbotconfig.php\" class=\"yellow-text-underline\">User-Configured Bots</a>";
						echo "<li><a href=\"mllabscoreboard.php\" class=\"yellow-text-underline\">User-Uploaded Bot scores</a>";
						echo "</ul></td><td>";
						echo "<ul>";
						echo "<li><a href=\"mllabmanual.php\" class=\"yellow-text-underline\">MLLab Online Quick Tutorial</a>";
						echo "<li><a href=\"mllabdownload.php\" class=\"yellow-text-underline\">MLLab Download</a>";
						echo "</ul></td></tr></table>";
					}
				  ?>
				  </td>
                </tr>
            </table></td>
          </tr>
          </table></td>
        <td width="29%" rowspan="2" valign="top" class="bord"><table width="100%" border="0" cellspacing="10" cellpadding="0">
          <tr>
            <td><table width="100%" border="0" cellspacing="5" cellpadding="0">
                <tr>
                  <td width="8%"><img src="images/index_14.gif" width="11" height="11" alt=""></td>
                  <td width="92%"><h2>Posted Comments</h2></td>
                </tr>
            </table></td>
          </tr>
          <tr>
            <td class="p"><p><strong>July 26, 2009</strong></p>
                <p>I completed the MLLab network connection</p>
              <p align="right"><a href="#" class="yellow-text-underline"><strong>read more</strong></a></p></td>
          </tr>
          <tr>
            <td class="p"><p><strong><?php echo date("F d, Y")?></strong></p>
                <p>I just set up this web site for some demo purpose </p>
              <p align="right"><a href="#" class="yellow-text-underline"><strong>read more</strong></a></p></td>
          </tr>
        </table></td>
      </tr>
      <tr>
        <td valign="top" class="bord"><table width="100%" border="0" cellspacing="10" cellpadding="0">
          <tr>
            <td width="33%" valign="top"><table width="100%" border="0" cellspacing="5" cellpadding="0">
                <tr>
                  <td><table width="100%" border="0" cellspacing="5" cellpadding="0">
                      <tr>
                        <td width="8%"><img src="images/index_14.gif" width="11" height="11" alt=""></td>
                        <td width="92%"><h2>User Data</h2></td>
                      </tr>
                  </table></td>
                </tr>
                <tr>
                  <td>
				  <a href="mllabbotconfig.php" class="yellow-text-underline">User-Configured Bots</a>
				  </td>
				 </tr>
				 <tr>
				 <td>
				  <a href="mllabscoreboard.php" class="yellow-text-underline">User-Uploaded Bot Scores</a>
				  </td>
                </tr>
                       </table></td>
            <td width="1" valign="top" bgcolor="#000000"><img src="images/spacer.gif" width="1" height="1"></td>
            <td width="33%" valign="top"><table width="100%" border="0" cellspacing="5" cellpadding="0">
                <tr>
                  <td><table width="100%" border="0" cellspacing="5" cellpadding="0">
                      <tr>
                        <td width="8%"><img src="images/index_14.gif" width="11" height="11" alt=""></td>
                        <td width="92%"><h2>Links</h2></td>
                      </tr>
                  </table></td>
                </tr>
                <tr>
                  <td><a href="mllabmanual.php" class="yellow-text-underline">MLLab Online Quick Tutorial</a><br>
                    <a href="mllabdownload.php" class="yellow-text-underline">MLLab Download</a><br />
					<a href="mllabadmin.php" class="yellow-text-underline">MLLab Admin</a><br />
                    </td>
                </tr>
                    </table></td>
            <td width="1" valign="top" bgcolor="#000000"><img src="images/spacer.gif" width="1" height="1"></td>
            <td width="34%" valign="top"><table width="100%" border="0" cellspacing="5" cellpadding="0">
                <tr>
                  <td><table width="100%" border="0" cellspacing="5" cellpadding="0">
                      <tr>
                        <td width="8%"><img src="images/index_14.gif" width="11" height="11" alt=""></td>
                        <td width="92%"><h2>Contacts</h2></td>
                      </tr>
                  </table></td>
                </tr>
                <tr>
                  <td><a href="www.ntu.edu.sg" class="yellow-text-underline">Nanyang Technological University</a></td>
                </tr>
             </table></td>
          </tr>
        </table></td>
        </tr>
      <tr>
        <td class="bord"><table width="100%" border="0" cellspacing="10" cellpadding="0">
          <tr>
            <td><table width="100%" border="0" cellspacing="5" cellpadding="0">
                <tr>
                  <td width="2%"><img src="images/index_14.gif" width="11" height="11" alt=""></td>
                  <td width="98%"><h2>About MLLab</h2></td>
                </tr>
            </table></td>
          </tr>
          <tr>
            <td><table width="100%" border="0" cellspacing="10" cellpadding="0">
                <tr>
                  <td width="89%"><strong>Machine Learning Laboratory (MLLab)</strong><br>
<strong>MLLab</strong> is a 3D agent simulation environment that allows user to test various machine learning and computational intelligence algorithms in a 3D environment by providing a game simulation environment in which game agents or bots, which are equipped with the algorithms, compete against each other.</td>
                  <td width="11%"><img src="images/index_22.jpg" width="65" height="65" alt=""></td>
                </tr>
            </table></td>
          </tr>
        </table></td>
        <td valign="top" class="bord"><table width="100%" border="0" cellspacing="5" cellpadding="0">
          <tr>
            <td><table width="100%" border="0" cellspacing="5" cellpadding="0">
                <tr>
                  <td width="8%"><img src="images/index_14.gif" width="11" height="11" alt=""></td>
                  <td width="92%"><h2>Promoted Bot Script</h2></td>
                </tr>
            </table></td>
          </tr>
          <tr>
            <td><strong>Multi-Layer Perceptron</strong><br>
<a href="http://en.wikipedia.org/wiki/Multilayer_perceptron" class="yellow-text-underline">Multi-Layer Perceptron (MLP)</a> is a feedforward artificial neural network model that maps sets of input data onto a set of appropriate output. It is a modification of the standard linear perceptron in that it uses three or more layers of neurons (nodes) with nonlinear activation functions, and is more powerful than the perceptron in that it can distinguish data that is not linearly separable, or separable by a hyperplane.</td>
          </tr>
        </table></td>
      </tr>
    </table></td>
  </tr>
</table>
<table width="1000" border="0" align="center" cellpadding="0" cellspacing="0">
  <tr>
    <td height="75" background="images/index_25.gif"><table width="100%" border="0" cellspacing="10" cellpadding="0">
      <tr>
        <td class="p" width="54%"><a href="#" class="yellow-text-underline"><strong>Terms of Use</strong></a> <strong class="yellow-text-regular">|</strong><a href="#" class="yellow-text-underline"><strong> Privacy Statement </strong></a></td>
        <td width="46%" align="center">Copyright &copy; Sitename.com. All rights reserved. 
Design by Stylish <a href="http://www.stylishtemplate.com" style="color:#fff; text-decoration:none;">Website Templates</a></td>
      </tr>
    </table></td>
  </tr>
</table>
</body>
</html>