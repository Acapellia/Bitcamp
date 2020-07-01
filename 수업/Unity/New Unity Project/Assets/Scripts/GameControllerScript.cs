using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameControllerScript : MonoBehaviour
{
    [SerializeField]
    GameObject enemy;

    float time;
    // Start is called before the first frame update
    void Start()
    {
        time = Time.deltaTime;
        Instantiate(enemy, this.transform.position, Quaternion.identity);
    }

    // Update is called once per frame
    void Update()
    {
        if (time >=2)
        {
            Instantiate(enemy, this.transform.position, Quaternion.identity);
            time = 0;
        }
        time += Time.deltaTime;
        print(time);
    }
}
