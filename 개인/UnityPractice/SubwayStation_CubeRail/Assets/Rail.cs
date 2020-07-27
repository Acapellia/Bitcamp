using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Rail : MonoBehaviour
{
    // Start is called before the first frame update
    public Transform railTransform;
    public bool pass;
    void Start()
    {
        railTransform = GetComponent<Transform>();
        pass = false;
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
