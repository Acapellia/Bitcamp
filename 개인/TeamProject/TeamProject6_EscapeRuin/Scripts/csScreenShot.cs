using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class csScreenShot : MonoBehaviour
{
    public static bool isCameraOn;
    // Start is called before the first frame update

    // Update is called once per frame
    void Update()
    {
        if(Input.GetButtonDown("Jump") && isCameraOn == true) {
            Debug.Log("take picture");
            string date = DateTime.Now.Year.ToString() + DateTime.Now.Month.ToString() + DateTime.Now.Day.ToString()
               + DateTime.Now.Hour.ToString() + DateTime.Now.Minute.ToString() + DateTime.Now.Second.ToString();
            string path = "ScreenShot" + date + ".png";
            ScreenCapture.CaptureScreenshot(path);
        }
    }
}
