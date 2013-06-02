<?php
	
	if (!isset($_GET['length']) || !isset($_GET['count']))
	{
		echo "{}";
		exit;
	}
	
	$length = intval($_GET['length']);
	$count = intval($_GET['count']);
	
	exec("./getwords {$length} {$count} 40", $results, $exitstatus);
	
	if ($exitstatus == 0)
	{
		echo $results[0];
	}
	else
	{
		echo "{}";
	}
?>