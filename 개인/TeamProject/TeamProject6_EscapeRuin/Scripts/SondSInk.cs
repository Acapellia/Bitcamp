using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Photon.Pun;

public class SondSInk : MonoBehaviourPunCallbacks
{

    // Start is called before the first frame update
    void Start()
    {
        photonView.RPC(nameof(SinkSound), RpcTarget.All);
    }

    // Update is called once per frame

    [SerializeField]
    AudioSource AudioSource;
    [SerializeField]
    AudioClip clip;
    
    [PunRPC]
    void SinkSound()
    {
        AudioSource.clip = clip;
        AudioSource.Play();
        Debug.Log("Played");
    }
}
