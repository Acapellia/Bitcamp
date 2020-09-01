using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class csDroneCreator : MonoBehaviour
{
    public GameObject[] drone;
    public static int createDroneIdx = -1;
    public static int gainedItemCnt = 0;

    private void Update() {
        if(createDroneIdx != -1) {
            Instantiate(drone[createDroneIdx],transform.position,transform.rotation);
            createDroneIdx = -1;
        }
    }

}
