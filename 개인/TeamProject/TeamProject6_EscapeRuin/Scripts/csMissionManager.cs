using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Photon.Pun;
using UnityEngine.UI;

public class csMissionManager : MonoBehaviourPunCallbacks
{
    public class Mission {
        public GameObject missionObj { get; set; }
        public int missionIdx { get; set; }
        public string missionText { get; set; }
        public string missionTarget { get; set; }
        public Mission(GameObject _obj, int _idx, string _text, string _target) {
            missionObj = _obj;
            missionIdx = _idx;
            missionText = _text;
            missionTarget = _target;
        }
    }
    private static bool isMissionCreated = false;
    public static List<Mission> mission;
    private static GameObject missionContents;
    public GameObject MissionPrefab;
    static GameObject staticMissoinPrefab;

    public GameObject[] drone;
    private bool[] isActivatedTarget = new bool[3] { false, false, false};
    public static int createDroneIdx = -1;
    public static int gainedItemCnt = 0;

    private void Start() {
        staticMissoinPrefab = MissionPrefab;
        isMissionCreated = false;
    }

    private void Update() {
            if (createDroneIdx != -1 && isActivatedTarget[createDroneIdx] == false)
            {
                Instantiate(drone[createDroneIdx], transform.position, transform.rotation);
                isActivatedTarget[createDroneIdx] = true;
                createDroneIdx = -1;
            }
    }

    // Start is called before the first frame update
    public void initMission() {

        if(isMissionCreated == false) {
            missionContents = csUIManagerControll.missionContents;
            mission = new List<Mission>(3);
           
            isMissionCreated = true;
            makeNewMission("스켈레톤 사진찍기", 0, "Skeletone");
            makeNewMission("도깨비 사진찍기", 1, "Monster");
            makeNewMission("호박 사진찍기", 2, "Pumpkin");
            //makeNewMission("스켈레톤 사진찍기", 0, "Cube1");
            //makeNewMission("도깨비 사진찍기", 1, "Cube2");
            //makeNewMission("호박 사진찍기", 2, "Cube3");
        }
    }

    public void makeNewMission(string missionString,int idx, string targetName = "") {
        if(isMissionCreated == true) {
            GameObject newMission = Instantiate(staticMissoinPrefab) as GameObject;
            Text missionText = newMission.GetComponentInChildren<Text>();
            missionText.text = missionString;
            missionText.fontSize = 20;
            newMission.transform.localScale = new Vector3(0.85f, 0.8f, 1f);
            newMission.transform.parent = missionContents.transform;
            mission.Add(new Mission(newMission, idx, missionString, targetName));
            Debug.Log("MissionCreate");
        }
    }

    public static void deleteMission(int idx) {
        if(isMissionCreated == true) {
            Destroy(mission[idx].missionObj);
            mission.Remove(mission[idx]);
        }
    }
}
