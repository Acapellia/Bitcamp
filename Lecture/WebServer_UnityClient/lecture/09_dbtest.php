<?php
	$ini_config = parse_ini_file('config.ini');
	echo $ini_config['hostname']."<br>".
	       $ini_config['account']."<br>".
                   $ini_config['password']."<br>".
	       $ini_config['database']."<br>";
?>