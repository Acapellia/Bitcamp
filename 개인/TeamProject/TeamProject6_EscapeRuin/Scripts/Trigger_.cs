using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Photon.Pun;
public class Trigger_ : MonoBehaviourPunCallbacks
{
    private Light fireLight;
    private ParticleSystem fireParticle;
    private GameObject trigger;
    public GameObject[] ghost;
    
    private void Start()
    {
        trigger = transform.GetChild(0).gameObject;
        //StartCoroutine("Test");
        
    }

    //IEnumerator Test()
    //{
    //    yield return new WaitForSeconds(5f);
    //    trigger.SetActive(true);

    ////}
    private void OnTriggerEnter(Collider other)
    {
        if (other.tag == "Player")
        {
            trigger.SetActive(true);
            PhotonNetwork.Instantiate($"MiniGhost ({Random.Range(1, 5)})", this.transform.position, this.transform.rotation);
        }
    }
}
