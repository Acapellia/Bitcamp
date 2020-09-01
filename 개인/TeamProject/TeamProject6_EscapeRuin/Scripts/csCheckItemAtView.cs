using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class csCheckItemAtView : MonoBehaviour
{
    Camera mainCamera;
    GameObject[] target;
    public float targetDistance;
    // Start is called before the first frame update
    void Start()
    {
        mainCamera = GetComponent<Camera>();
        target = GameObject.FindGameObjectsWithTag("Target");
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetButtonDown("Jump") /*&& csScreenShot.isCameraOn==true*/) {
            Debug.Log("Find Target");
            for(int i = 0; i < target.Length; i++) {
                Vector3 viewPos = mainCamera.WorldToViewportPoint(target[i].transform.position);
                if((0<viewPos.x && viewPos.x<1) && (0 < viewPos.y && viewPos.y < 1) && 0 < viewPos.z && viewPos.z < targetDistance) {
                    Debug.Log("Target : " + target[i].name);
                    for(int j=0; j<csMissionManager.mission.Count; j++) {
                        if(target[i].name == csMissionManager.mission[j].missionTarget) {
                            Debug.Log("Mission : " + target[i].name);
                            csMissionManager.createDroneIdx = csMissionManager.mission[j].missionIdx;
                            csMissionManager.deleteMission(j);
                        }
                    }
                }
            }
        }
    }
}
