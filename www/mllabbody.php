<?php
function mllabbody($title, $content)
{
	$username="";
	if(isset($_SESSION['username']))
	{
		$username="<strong>[" . $_SESSION['username'] . "]</strong>";
	}
	echo "
	<table width=\"1000\" border=\"0\" align=\"center\" cellpadding=\"0\" cellspacing=\"0\">
	  <tr>
		<td><table width=\"100%\" border=\"0\" cellspacing=\"0\" cellpadding=\"0\">
		  <tr>
			<td height=\"33\" background=\"images/index_01.gif\"><table width=\"100%\" border=\"0\" cellspacing=\"5\" cellpadding=\"0\">
			  <tr>
				<td class=\"p\" width=\"64%\"><table width=\"100%\" border=\"0\" cellspacing=\"5\" cellpadding=\"0\">
				  <tr>
					<td width=\"2%\"><img src=\"images/home.gif\" width=\"12\" height=\"11\"></td>
					<td width=\"98%\"> <a href=\"mllab.php\">home page</a>" . $username . "</td>
				  </tr>
				</table></td>
				<td width=\"36%\" align=\"center\">Today's date is " . date('l, F d, Y') . "</td>
			  </tr>
			</table></td>
		  </tr>
		  <tr>
			<td><img src=\"images/index_03.jpg\" width=\"1000\" height=\"199\" alt=\"\"></td>
		  </tr>
		  <tr>
			<td><table width=\"100%\" border=\"0\" cellspacing=\"0\" cellpadding=\"0\">
			  <tr>
				<td><a href=\"mllab.php\"><img src=\"images/index_04.gif\" alt=\"\" width=\"171\" height=\"38\" border=\"0\"></a></td>
				<td><a href=\"mllabmanual.php\"><img src=\"images/index_05.gif\" alt=\"\" width=\"110\" height=\"38\" border=\"0\"></a></td>
				<td><a href=\"mllabdownload.php\"><img src=\"images/index_06.gif\" alt=\"\" width=\"126\" height=\"38\" border=\"0\"></a></td>
				<td><a href=\"mllabbotconfig.php\"><img src=\"images/index_07.gif\" alt=\"\" width=\"116\" height=\"38\" border=\"0\"></a></td>
				<td><a href=\"mllabscoreboard.php\"><img src=\"images/index_08.gif\" alt=\"\" width=\"123\" height=\"38\" border=\"0\"></a></td>
				<td><a href=\"mllablogout.php\"><img src=\"images/index_09.gif\" alt=\"\" width=\"114\" height=\"38\" border=\"0\"></a></td>
				<td><img src=\"images/index_10.gif\" width=\"240\" height=\"38\" alt=\"\"></td>
			  </tr>
			</table></td>
		  </tr>
		</table></td>
	  </tr>
	</table>
	<table width=\"1000\" border=\"0\" align=\"center\" cellpadding=\"0\" cellspacing=\"0\">
	  <tr>
		<td class=\"bg1\"><table width=\"100%\" border=\"0\" cellspacing=\"10\" cellpadding=\"0\">
		  <tr>
			<td width=\"71%\" valign=\"top\" class=\"bord\">
			<table width=\"100%\" border=\"0\" cellspacing=\"10\" cellpadding=\"0\">
			  <tr>
				<td><table width=\"100%\" border=\"0\" cellspacing=\"5\" cellpadding=\"0\">
					<tr>
					  <td width=\"2%\"><img src=\"images/index_14.gif\" width=\"11\" height=\"11\" alt=\"\"></td>
					  <td width=\"98%\"><h2>";
					  echo $title;
					  echo "</h2></td>
					</tr>";
					echo "<tr><td colspan=\"2\">";
			echo $content;
			echo "</td></tr>";
			echo "
				</table>
				</td>          
			</tr>
			</table>
		</td>
	  </tr>
	</table>
	<table width=\"1000\" border=\"0\" align=\"center\" cellpadding=\"0\" cellspacing=\"0\">
	  <tr>
		<td height=\"75\" background=\"images/index_25.gif\"><table width=\"100%\" border=\"0\" cellspacing=\"10\" cellpadding=\"0\">
		  <tr>
			<td class=\"p\" width=\"54%\"><a href=\"#\" class=\"yellow-text-underline\"><strong>Terms of Use</strong></a> <strong class=\"yellow-text-regular\">|</strong><a href=\"#\" class=\"yellow-text-underline\"><strong> Privacy Statement </strong></a></td>
			<td width=\"46%\" align=\"center\">Copyright &copy; Sitename.com. All rights reserved. 
	Design by Stylish <a href=\"http://www.stylishtemplate.com\" style=\"color:#fff; text-decoration:none;\">Website Templates</a></td>
		  </tr>
		</table></td>
	  </tr>
	</table>";
}
?>