using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class csParticleManager : MonoBehaviour
{
    public GameObject particle;
    public Vector3 replace;
    // Start is called before the first frame update
    void Start()
    {
        
    }
    
    private void OnTriggerEnter(Collider other) {
        if(other.gameObject.tag == "Player") {
            Debug.Log("Explosion");
            Instantiate(particle, transform.position, transform.rotation);
        }
    }
    private void OnCollisionEnter(Collision collision) {
        if(collision.gameObject.tag == "Player") {
            Debug.Log("Explosion2");
            Instantiate(particle, transform.position + replace, transform.rotation);
        }
    }
    
}
