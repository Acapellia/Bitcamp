using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class csRoateMove : MonoBehaviour
{
    public float rotSpeed = 120f;
    public float movSpeed = 20f;
    CRotMovMain rotMovMain;

    private void Start()
    {
        rotMovMain = GetComponent<CRotMovMain>();
    }

    void Update()
    {
        float h = Input.GetAxis("Horizontal");
        float v = Input.GetAxis("Vertical");

        h = h * rotSpeed * Time.deltaTime;
        v = v * movSpeed * Time.deltaTime;

        transform.Rotate(Vector3.up * h);
        transform.Translate(Vector3.forward * v);

        if(h != 0f)
            rotMovMain.sendRotMsg();
        if(v != 0f)
            rotMovMain.sendMovMsg();
    }
}
