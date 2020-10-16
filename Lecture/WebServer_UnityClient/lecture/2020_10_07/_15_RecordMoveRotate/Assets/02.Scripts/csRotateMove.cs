using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class csRotateMove : MonoBehaviour
{
    public float movSpeed = 20f;
    public float rotSpeed = 120f;
    void Update()
    {
        float h = Input.GetAxis("Horizontal");
        float v = Input.GetAxis("Vertical");

        h = h * rotSpeed * Time.deltaTime;
        v = v * movSpeed * Time.deltaTime;

        transform.Translate(Vector3.forward * v);
        transform.Rotate(Vector3.up * h);
    }
}
