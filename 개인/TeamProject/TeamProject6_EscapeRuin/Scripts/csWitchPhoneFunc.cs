using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class csWitchPhoneFunc : MonoBehaviour
{
    //private Button btnPlayerPhone;

    private void Start() {
        
    }
    public void btnAccept() {
        //btnPlayerPhone = csUIManagerControll.btnPlayerPhone.gameObject.GetComponent<Button>();
        //btnPlayerPhone.gameObject.SetActive(true);
        csUIManagerControll.showPlayerPhoneBtn();
        //this.gameObject.SetActive(false);
        csUIManagerControll.hideWitchPhone();
        Destroy(GameObject.Find("SmartPhone"));
    }

    public void btnRefuse() {
        //this.gameObject.SetActive(false);
        csUIManagerControll.hideWitchPhone();
    }
}
