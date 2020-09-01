using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;
public class csUIManagerControll : MonoBehaviour
{
    public static GameObject playerPhone;
    public static GameObject witchPhone;
    public static Button btnPlayerPhone;
    public static GameObject albumUI;
    public static GameObject albumcontents;
    public static GameObject missionUI;
    public static GameObject missionContents;
    public static GameObject takePictureUI;
    public static bool isPlayerPhoneUsed = false;
    // Start is called before the first frame update
    void Start()
    {
        playerPhone = GameObject.Find("PlayerPhone").gameObject;
        btnPlayerPhone = GameObject.Find("btnPlayerPhone").gameObject.GetComponent<Button>();
        witchPhone = GameObject.Find("WitchPhone").gameObject as GameObject;
        albumUI = GameObject.Find("AlbumScrollView").gameObject;
        albumcontents = GameObject.Find("AlbumContents").gameObject;
        Debug.Log("album : " + albumcontents);
        missionUI = GameObject.Find("MissionScrollView").gameObject;
        missionContents = GameObject.Find("MissionContents").gameObject;
        takePictureUI = GameObject.Find("TakePictureUI").gameObject;
        //csMissionManager.initMission();
        csAlbumManager.initAlbum();
        initUIState();
    }     

    // Update is called once per frame
    void Update()
    {
    }
    // 게임을 처음 시작했을 때 UI상태
    private void initUIState() {
        //btnPlayerPhone.gameObject.SetActive(false);
        //witchPhone.SetActive(false);
        hidePlayerPhone();
        hideWitchPhone();
        hideAlbumUI();
        hidePlayerPhoneBtn();
        hideMissionUI();
        hideTakePictureUI();
    }

    // phone 사용중 되돌아가기 버튼을 누를 시
    public void backMainPhoneUI() {
        isPlayerPhoneUsed = true;
        showPlayerPhone();
        hideAlbumUI();
        hideMissionUI();
        hideTakePictureUI();
    }

    // phone 기능 관련 Ui를 모두 숨기고 phone btn만 남아 있는 상태
    public void hidePhoneFuncionUI() {
        hideAlbumUI();
        hideMissionUI();
        hideTakePictureUI();
    }
    public void usePlayerPhone() {
        if(!isPlayerPhoneUsed) {
            //playerPhone.SetActive(true);
            showPlayerPhone();
            hidePhoneFuncionUI();
            isPlayerPhoneUsed = true;
        }
        else {
            //playerPhone.SetActive(false);
            hidePlayerPhone();
            hidePhoneFuncionUI();
            isPlayerPhoneUsed = false;
        }
    }
    public static void showPlayerPhoneBtn() {
        btnPlayerPhone.gameObject.SetActive(true);
    }
    public static void hidePlayerPhoneBtn() {
        btnPlayerPhone.gameObject.SetActive(false);
    }
    public static void showPlayerPhone() {
        playerPhone.SetActive(true);
    }
    public static void hidePlayerPhone() {
        playerPhone.SetActive(false);
    }
    public static void showWitchPhone() {
        witchPhone.SetActive(true);
    }
    public static void hideWitchPhone() {
        witchPhone.SetActive(false);
    }
    public static void showAlbumUI() {
        albumUI.gameObject.SetActive(true);
    }
    public static void hideAlbumUI() {
        albumUI.gameObject.SetActive(false);
    }
    public static void showMissionUI() {
        missionUI.gameObject.SetActive(true);
    }
    public static void hideMissionUI() {
        missionUI.gameObject.SetActive(false);
    }
    public static void showTakePictureUI() {
        takePictureUI.gameObject.SetActive(true);
        csScreenShot.isCameraOn = true;
    }
    public static void hideTakePictureUI() {
        takePictureUI.gameObject.SetActive(false);
        csScreenShot.isCameraOn = false;
    }
}
