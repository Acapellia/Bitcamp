using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraMove : MonoBehaviour
{
    public Transform subway;
    // Start is called before the first frame update
    void Start()
    {
        //subway = GetComponent<Transform>();
    }

    // Update is called once per frame
    void Update()
    {
        transform.position = Vector3.Lerp(transform.position, subway.position - subway.right*5,Time.deltaTime*5.0f);
    }
}
