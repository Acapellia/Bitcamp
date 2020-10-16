using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class csMakeParticle : MonoBehaviour
{
    CRotMovMain rotMovMain;
    public List<GameObject> particle;
    // Start is called before the first frame update
    void Start()
    {
        rotMovMain = GetComponent<CRotMovMain>();
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.Keypad0)) {
            Instantiate(particle[0], transform.position + new Vector3(0,3,0), Quaternion.identity);
            rotMovMain.sendParticleMsg(0);
            Debug.Log("Particle 0 Created");
        }
        else if(Input.GetKeyDown(KeyCode.Keypad1)) {
            Instantiate(particle[1], transform.position + new Vector3(0, 3, 0), Quaternion.identity);
            rotMovMain.sendParticleMsg(1);
            Debug.Log("Particle 0 Created");
        }
        else if(Input.GetKeyDown(KeyCode.Keypad2)) {
            Instantiate(particle[2], transform.position + new Vector3(0, 3, 0), Quaternion.identity);
            rotMovMain.sendParticleMsg(2);
            Debug.Log("Particle 0 Created");
        }
    }
}
