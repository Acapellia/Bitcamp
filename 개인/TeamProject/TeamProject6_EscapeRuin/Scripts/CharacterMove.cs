
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using UnityEngine;
using Photon.Pun;

public class CharacterMove : MonoBehaviourPun
{
    public float speed = 8f;
    public float rotSpeed = 20f;
    // Update is called once per frame
    Camera userCamera;
    Animator anim;

    private Vector3 currPos;
    private Quaternion currRot;
    private void Start()
    {
        userCamera = this.gameObject.GetComponentInChildren<Camera>();
        anim = GetComponent<Animator>();
    }
    void Update()
    {
        if (photonView.IsMine)
        {
            float vr = 0;
            float hr = 0;
            if (Input.GetMouseButton(0))
            {
                vr = Input.GetAxis("Mouse X");
                hr = Input.GetAxis("Mouse Y");
            }
            float h = Input.GetAxis("Horizontal");
            float v = Input.GetAxis("Vertical");

            h *= speed * Time.deltaTime;
            v *= speed * Time.deltaTime;

            if (v != 0)
            {
                anim.SetInteger("move", 1);
            }
            else
            {
                anim.SetInteger("move", 0);
            }
            //Camera.main.transform.Rotate(new Vector3(0, vr, 0));
            if (Mathf.Abs(hr) > Mathf.Abs(vr))
            {
                userCamera.transform.Rotate(new Vector3(-hr * 2, 0, 0));
            }
            else
            {
                //transform.Rotate(new Vector3(0, vr*2, 0));
            }
            transform.Rotate(new Vector3(0, h * rotSpeed, 0));
            transform.Translate(0, 0, v);
        }

    }

}
