using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemyscript : MonoBehaviour
{
    Vector3 pos;
    [SerializeField]

    float speed;
    // Start is called before the first frame update
    void Start()
    {
        int x = Random.Range(-45, 45);
        speed = 5.0f;
        pos = new Vector3(x, 0, 45);//transform.position;
    }

    // Update is called once per frame
    void Update()
    {
        pos.z -= speed * Time.deltaTime;
        transform.position = pos;
        if (pos.z < -50) { Destroy(this.gameObject); }
    }

    void OnCollisionEnter(Collision col)
    {
        if (col.collider.tag == "Bullet")
        {
            print("hit");
            Destroy(this.gameObject);
        }
    }
}
