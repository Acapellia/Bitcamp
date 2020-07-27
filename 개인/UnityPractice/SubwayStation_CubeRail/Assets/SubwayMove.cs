using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SubwayMove : MonoBehaviour {
    Transform transform;
    public Transform cameraTransform;
    float speed = 5.0f;
    bool touch = false;
    // Start is called before the first frame update
    void Start() {
        transform = GetComponent<Transform>();
    }

    // Update is called once per frame
    void Update() {
        transform.position += transform.right * speed * Time.deltaTime;
    }
    private void OnTriggerEnter(Collider other) {
        if(other.tag == "Rail") {
            Rail rail = other.GetComponent<Rail>();
            
            if(rail.pass == false) {
                Transform railTransform = rail.railTransform;
                transform.position = Vector3.Lerp(transform.position,
                    new Vector3((rail.transform.position.x - rail.transform.localScale.x / 2), 0,
                    (rail.transform.position.z - rail.transform.localScale.z / 2)), Time.deltaTime * 5.0f);
                transform.rotation = railTransform.rotation;
                Vector3 dif;
                cameraTransform.position = Vector3.Lerp(cameraTransform.position,transform.position,Time.deltaTime*5.0f);
                if(railTransform.rotation.eulerAngles.y > 180) {
                    dif = new Vector3(0, 360 - railTransform.rotation.eulerAngles.y, 0);
                    cameraTransform.rotation = Quaternion.Slerp(cameraTransform.rotation, 
                        Quaternion.Euler(new Vector3(0, 90, 0) - dif), Time.deltaTime * 0.5f);
                    //cameraTransform.rotation = Quaternion.Euler(new Vector3(0,90,0) - dif);
                }
                else {
                    dif = new Vector3(0, railTransform.rotation.eulerAngles.y, 0);
                    cameraTransform.rotation = Quaternion.Slerp(cameraTransform.rotation, 
                        Quaternion.Euler(new Vector3(0, 90, 0) + dif), Time.deltaTime * 0.5f);
                    //cameraTransform.rotation = Quaternion.Euler(new Vector3(0, 90, 0) + dif);
                }
                rail.pass = true;
            }
        }
    }
    private void OnTriggerExit(Collider other) {
    }
}
