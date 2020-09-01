using System;
using System.CodeDom;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEngine;
using UnityEngine.AI;

public class GhostNavy_Patrol : MonoBehaviour {
    public LayerMask whatIsTarget;

    private List<GameObject> patrol_Point = new List<GameObject>();
    public GameObject PtPoint_0;

    private PatrolPoint patrolPt;

    private NavMeshAgent pathFinder;
    private Animator miniGhostAnimator;

    private GameObject target;

    private int patrol_Count;
    private bool targetExist = false;
    private bool start_path = true;

    private void Awake() {
        pathFinder = GetComponent<NavMeshAgent>();
        patrol_Count = 0;
    }
    private void Start() {
        PtPoint_0 = GameObject.Find("PtPoint_");
        //Debug.Log(PtPoint_0.transform.childCount);
        for(int i = 0; i < PtPoint_0.transform.childCount; i++) {
            patrol_Point.Add(PtPoint_0.transform.GetChild(i).gameObject);
        }
        StartCoroutine("UpdatePath");
    }

    private IEnumerator UpdatePath() {
        while(true) {
            if(targetExist) {
                pathFinder.SetDestination(target.transform.position);
                if(Math.Abs(transform.position.x - target.transform.position.x) < (float)0.5
                    && Math.Abs(transform.position.z - target.transform.position.z) < (float)0.5) {
                    // 기절
                    //Debug.Log("작동");
                }
            }
            else {
                Collider[] colliders =
                    Physics.OverlapSphere(transform.position, 20f, whatIsTarget);
                // 캐릭터 기준 20칸의 구안에서 whatIsTarget 레이어마스크를 가진 놈을 찾는다.

                for(int i = 0; i < colliders.Length; i++) {
                    Player_1 play = colliders[i].GetComponent<Player_1>();

                    if(play != null) {
                        target = colliders[i].gameObject;
                        targetExist = true;
                    }
                }

                if(start_path) {
                    pathFinder.SetDestination(patrol_Point[UnityEngine.Random.Range(0, patrol_Point.Count)].transform.position);
                    start_path = false;
                }
                //Debug.Log(patrol_Count);
                //Debug.Log(transform.position);
                //Debug.Log("Ghost" + transform.position.x);
                //Debug.Log("Patrol" + patrol_Point[patrol_Count].transform.position.x);
                if(Math.Abs(transform.position.x - patrol_Point[patrol_Count].transform.position.x) < (float)0.5
                       && Math.Abs(transform.position.z - patrol_Point[patrol_Count].transform.position.z) < (float)0.5) {
                    //Debug.Log("띠롱");
                    //patrol_Count++;
                    //    if (patrol_Count > patrol_Point.Count+1)
                    //    {
                    //        patrol_Count = 0;
                    //    }
                    patrol_Count = UnityEngine.Random.Range(0, patrol_Count);
                    pathFinder.SetDestination(patrol_Point[patrol_Count].transform.position);
                }
                //}
              
            }
            yield return new WaitForSeconds(0.25f);
        }


    }
}
