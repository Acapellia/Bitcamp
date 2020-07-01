using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BulletScript : MonoBehaviour
{
    Vector3 pos;
    [SerializeField]

    float speed;
    // Start is called before the first frame update
    void Start()
    {
        pos = transform.position;
        speed = 20.0f;
    }

    // Update is called once per frame
    void Update()
    {
        pos.z += speed * Time.deltaTime;
        transform.position = pos;
        if (pos.z > 50) { Destroy(this.gameObject); }
    }
    void OnCollisionEnter(Collision col)
    {
        if (col.collider.tag == "Enemy")
        {
            print("hit");
            Destroy(this.gameObject);
        }
    }
}
