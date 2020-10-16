<?php
    $isrecord = $_REQUEST["isrecord"];
    $obj_id = $_REQUEST["obj_id"];
    $position_x = $_REQUEST["position_x"];
    $position_y = $_REQUEST["position_y"];
    $position_z = $_REQUEST["position_z"];
    $rotation_x = $_REQUEST["rotation_x"];
    $rotation_y = $_REQUEST["rotation_y"];
    $rotation_z = $_REQUEST["rotation_z"];
    $rotation_w = $_REQUEST["rotation_w"];
    $scale_x = $_REQUEST["scale_x"];
    $scale_y = $_REQUEST["scale_y"];
    $scale_z = $_REQUEST["scale_z"];

    $data = array();
    $data["error"] = 0;

    $ini_config = parse_ini_file("Config.ini");
    $db = new mysqli($ini_config["hostname"],
                     $ini_config["account"],
                     $ini_config["password"],
                     $ini_config["database"]);
    
    if(mysqli_connect_error()){
        $data["error"] = 1;
    }else if($isrecord == "1"){
        $query = sprintf("INSERT INTO objTransform".
                         "(obj_id,position_x,position_y,position_z,".
                        "rotation_x,rotation_y,rotation_z,rotation_w,".
                        "scale_x,scale_y,scale_z) VALUES".
                        "('%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s')",
                        $obj_id,$position_x,$position_y,$position_z,
                        $rotation_x,$rotation_y,$rotation_z,$rotation_w,
                        $scale_x,$scale_y,$scale_z);
        $db->query($query);
        $data["result"] = "insert";
    }else if($isrecord == "0"){
        $query = sprintf("SELECT * FROM objTransform WHERE obj_id='%s' ".
                        "ORDER BY serial_num", $obj_id);
        $res = $db->query($query);
        if($res->num_rows > 0){
            for($i=0;$i<$res->num_rows;$i=$i+1){
                $row = $res->fetch_assoc();
                $rdata = array();
                $rdata["serial_num"] = (int)$row["serial_num"];
                $rdata["position_x"] = (float)$row["position_x"];
                $rdata["position_y"] = (float)$row["position_y"];
                $rdata["position_z"] = (float)$row["position_z"];
                $rdata["rotation_x"] = (float)$row["rotation_x"];
                $rdata["rotation_y"] = (float)$row["rotation_y"];
                $rdata["rotation_z"] = (float)$row["rotation_z"];
                $rdata["rotation_w"] = (float)$row["rotation_w"];
                $rdata["scale_x"] = (float)$row["scale_x"];
                $rdata["scale_y"] = (float)$row["scale_y"];
                $rdata["scale_z"] = (float)$row["scale_z"];
                array_push($data, $rdata);
            }
            $data["result"] = "read";
        }else{
            $data["result"] = "noread";
        }
    }

    $db->close();

    echo json_encode($data);
?>