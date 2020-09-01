using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;
using UnityEngine.UI;
public class CheckPhoneArea : MonoBehaviour {
    private void OnTriggerEnter(Collider other) {
        if(other.gameObject.name == "SmartPhoneArea") {
            Debug.Log("SmartPhoneArea");
        }
    }
}
