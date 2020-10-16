<?php
	// 서버주소/07_request_response.php?a=100&b=50
	// Request 요청중에 인자를 통해서 값을 꺼내라
	$a = $_REQUEST["a"];// a 인자값을 꺼내라
	$b = $_REQUEST["b"];// b 인자값을 꺼내라
	
	echo $a+$b;	// Response
?>