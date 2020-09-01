using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class csDroneActivate : MonoBehaviour
{
    public GameObject player;
    public GameObject item;
    Vector3 droneToPlayerPos;
    public float speed;
    // Start is called before the first frame update
    void Start()
    {
        player = GameObject.FindGameObjectWithTag("Player");
        droneToPlayerPos = new Vector3(player.transform.position.x,this.transform.position.y, player.transform.position.z);
    }

    // Update is called once per frame
    void Update()
    {
        if(Vector3.Distance(droneToPlayerPos, this.transform.position) > 0.5f) {
            Vector3 newPos = this.transform.position + (droneToPlayerPos - this.transform.position).normalized * speed * Time.deltaTime;
            this.transform.position = newPos;
        }
        else {
            Debug.Log("Arrived");
            Instantiate(item, this.transform.position, this.transform.rotation);
            Destroy(this.gameObject);
        }
    }
}
