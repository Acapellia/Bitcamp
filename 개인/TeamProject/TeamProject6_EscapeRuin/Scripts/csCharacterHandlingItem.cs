using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Photon.Pun;
using UnityEngine.UI;

public class csCharacterHandlingItem : MonoBehaviourPunCallbacks
{
    private GameObject[] Winer;
    //private GameObject witchPhone;
    // Start is called before the first frame update
    void Start()
    {
        //witchPhone = csUIManagerControll.witchPhone;
        //btnPlayerPhone = GameObject.Find("btnPlayerPhone").gameObject.GetComponent<Button>();
    }

    // Update is called once per frame
    private void OnTriggerStay(Collider other) {
        if(other.gameObject.name == "SmartPhone") {
            if(Input.GetKey(KeyCode.Z)) {
                csUIManagerControll.showWitchPhone();
            }
        }
    }

    private void OnCollisionStay(Collision collision) {
        if(collision.collider.gameObject.tag == "Item") {
            if(Input.GetKey(KeyCode.Z)) {
                csMissionManager.gainedItemCnt++;
                Destroy(collision.collider.gameObject);
            }
            if(csMissionManager.gainedItemCnt == 1)
            {
                
                if (GameObject.Find("EndGameBallon(Clone)") == null)
                {
                    GameObject ballon = PhotonNetwork.Instantiate("EndGameBallon", new Vector3(105, (float)0.34, (float)61.45), Quaternion.identity);
                    //this.gameObject.GetComponent<BoxCollider>().isTrigger = true;
                    gameObject.transform.position = ballon.transform.position + new Vector3(0,2,0);
                    gameObject.transform.parent = ballon.transform;
                }
            }
        }
    }
}
