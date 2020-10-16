using FreeNet;
using FreeNetUnity;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices.ComTypes;
using UnityEngine;

public class CNetworkManager : MonoBehaviour
{
    CFreeNetUnityService gameserver;

    private void Awake()
    {
        this.gameserver = gameObject.AddComponent<CFreeNetUnityService>();
        this.gameserver.appcallback_on_status_changed += on_status_changed;
        this.gameserver.appcallback_on_message += on_message;
    }

    void Start()
    {
        connect();
    }

    void connect()
    {
        this.gameserver.connect("127.0.0.1", 7979);
        //this.gameserver.connect("10.89.1.77", 7979);
        //this.gameserver.connect("10.89.31.221", 7979);
    }

    void on_status_changed(NETWORK_EVENT status)
    {
        switch (status)
        {
            case NETWORK_EVENT.connected:
                {
                    Debug.Log("on connected");
                    CPacket msg = CPacket.create((short)PROTOCOL.CHAT_MSG_REQ);
                    msg.push("Hello!!!");
                    this.gameserver.send(msg);
                }
                break;
            case NETWORK_EVENT.disconnected:
                Debug.Log("disconnected");
                break;
        }
    }

    void on_message(CPacket msg)
    {
        PROTOCOL protocol_id = (PROTOCOL)msg.pop_protocol_id();

        switch (protocol_id)
        {
            case PROTOCOL.CHAT_MSG_ACK:
                {
                    string text = msg.pop_string();
                    //GameObject.Find("Cube").GetComponent<CRotMovMain>().on_receive_chat_msg("CHAT ACK: " + text);
                    GameObject.Find("GameMain").GetComponent<CGameMain>().on_receive_chat_msg(text);
                }
                break;
            case PROTOCOL.CHAT_MSG_DISPATCH:

                {
                    string text = msg.pop_string();
                    //GameObject.Find("Cube").GetComponent<CRotMovMain>().on_receive_chat_msg("DISPATCH: " + text);
                    GameObject.Find("GameMain").GetComponent<CGameMain>().on_receive_chat_msg(text);
                }
                break;
            case PROTOCOL.ROT_MSG_ACK:
                {
                    string text = msg.pop_string();
                    GameObject.Find("Cube").GetComponent<CRotMovMain>().on_receive_chat_msg("ROT ACK: " + text);
                }
                break;
            case PROTOCOL.ROT_MSG_DISPATCH:
                {
                    float rotX = msg.pop_Single();
                    float rotY = msg.pop_Single();
                    float rotZ = msg.pop_Single();
                    float rotW = msg.pop_Single();
                    GameObject.Find("Cube").GetComponent<CRotMovMain>().on_receive_rot_msg(rotX, rotY, rotZ, rotW);
                }
                break;
            case PROTOCOL.MOV_MSG_ACK:
                {
                    string text = msg.pop_string();
                    GameObject.Find("Cube").GetComponent<CRotMovMain>().on_receive_chat_msg("MOV ACK: " + text);
                }
                break;
            case PROTOCOL.MOV_MSG_DISPATCH:
                {
                    float posX = msg.pop_Single();
                    float posY = msg.pop_Single();
                    float posZ = msg.pop_Single();
                    GameObject.Find("Cube").GetComponent<CRotMovMain>().on_receive_mov_msg(posX, posY, posZ);
                }
                break;
            case PROTOCOL.PARTICLE_MSG_ACK: {
                    string text = msg.pop_string();
                    GameObject.Find("Cube").GetComponent<CRotMovMain>().on_receive_chat_msg("PARTICLE ACK: " + text);
                }
                break;
            case PROTOCOL.PARTICLE_MSG_DISPATCH: {
                    float posX = msg.pop_Single();
                    float posY = msg.pop_Single();
                    float posZ = msg.pop_Single();
                    int type = msg.pop_int32();
                    GameObject.Find("Cube").GetComponent<CRotMovMain>().on_receive_particle_msg(posX, posY, posZ, type);
                    Debug.Log("Particle Msg Dispatch");
                }
                break;
        }
    }

    public void send(CPacket msg)
    {
        this.gameserver.send(msg);
    }
}
