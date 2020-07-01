using System.Collections;
using System.Collections.Generic;
//using System.Numerics;
using UnityEngine;

public class PlayerScript : MonoBehaviour
{
    [SerializeField]
    float speed = 10.0f;
    float fireTime = 0.3f;
    float time;
    [SerializeField]
    GameObject bullet;
    // Start is called before the first frame update
    void Start()
    {
        time = 0.0f;
    }

    // Update is called once per frame
    void Update()
    {
        transform.Translate(new UnityEngine.Vector3(Input.GetAxis("Horizontal") * speed,
            0, Input.GetAxis("Vertical") * speed));

        if (Input.GetKey(KeyCode.Space) && time>=fireTime ) {
            Instantiate(bullet, transform.position, Quaternion.Euler(new Vector3(90,0,0)));
            time = 0;
        }
        time += Time.deltaTime;
    }
}
