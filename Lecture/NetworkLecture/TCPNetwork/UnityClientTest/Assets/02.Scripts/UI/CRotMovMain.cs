using FreeNet;
using FreeNetUnity;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class CRotMovMain : MonoBehaviour
{
    CNetworkManager network_manager;
    public List<GameObject> particle;

    private void Awake()
    {
        this.network_manager = GameObject.Find("NetworkManager").GetComponent<CNetworkManager>();
    }

    public void sendRotMsg()
    {
        CPacket msg = CPacket.create((short)PROTOCOL.ROT_MSG_REQ);
        msg.push(transform.rotation.x);
        msg.push(transform.rotation.y);
        msg.push(transform.rotation.z);
        msg.push(transform.rotation.w);
        this.network_manager.send(msg);
    }

    public void sendMovMsg()
    {
        CPacket msg = CPacket.create((short)PROTOCOL.MOV_MSG_REQ);
        msg.push(transform.position.x);
        msg.push(transform.position.y);
        msg.push(transform.position.z);
        this.network_manager.send(msg);
    }

    public void sendParticleMsg(int type) {
        CPacket msg = CPacket.create((short)PROTOCOL.PARTICLE_MSG_REQ);
        msg.push(transform.position.x);
        msg.push(transform.position.y);
        msg.push(transform.position.z);
        msg.push(type);
        this.network_manager.send(msg);
    }

    public void on_receive_particle_msg(float posX, float posY, float posZ, int type) {
        Instantiate(particle[type], transform.position + new Vector3(0, 3, 0), Quaternion.identity);
        Debug.Log("Recv Particle Create Message");
    }

    public void on_receive_rot_msg(float rotX, float rotY, float rotZ, float rotW)
    {
        transform.rotation = new Quaternion(rotX, rotY, rotZ, rotW);
    }

    public void on_receive_mov_msg(float posX, float posY, float posZ)
    {
        transform.position = new Vector3(posX, posY, posZ);
    }

    public void on_receive_chat_msg(string msg)
    {
        Debug.Log(msg);
    }

    
}
