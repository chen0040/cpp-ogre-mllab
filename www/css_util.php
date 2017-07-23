<?php
function mllab_markup_div_with_style($content, $style)
{
	$data="<div style=\"" . $style . "\">" . $content . "</div>";
	return $data;
}

function mllab_markup_sql_table($data, $style, $fields)
{
	$content="<table style=\"" . $style . "\" border=\"1\">";
	

	$content = $content . "<tr>";
	foreach($fields as $value)
	{
		$content = $content . "<td style=\"font-weight:bold\">" . $value . "</td>";
	}
	$content = $content . "</tr>";
			
	while($row = mysql_fetch_array($data))
	{
		
		$content = $content . "<tr>";
		foreach($fields as $key)
		{
			$content = $content . "<td>" . $row[$key] . "</td>";
		}
		$content = $content . "</tr>";
	}
	
	$content=$content . "</table>";
	return $content;
}
?>