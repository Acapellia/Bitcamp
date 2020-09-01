using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerPhoneFunc : MonoBehaviour
{
    // Start is called before the first frame update

    public void btnMissionClicked() {
        csUIManagerControll.showMissionUI();
        Debug.Log("btnMissionClicked");
    }
    public void btnCameraClicked() {
        csUIManagerControll.showTakePictureUI();
        csUIManagerControll.isPlayerPhoneUsed = false;
        csUIManagerControll.hidePlayerPhone();
        Debug.Log("btnCameraClicked");

    }
    public void btnEmailClicked() {
        csUIManagerControll.showAlbumUI();
        Debug.Log("btnEmailClicked");

    }
    public void btnSettingClicked() {

        Debug.Log("btnSettingClicked");

    }
}
