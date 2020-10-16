using FreeNet;
using FreeNetUnity;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class CGameMain : MonoBehaviour
{
    public InputField chatList;
    public InputField msgField;
    public Text chatLog;

    string input_text;
    List<string> received_texts;
    CNetworkManager network_manager;

    public void sendMsg()
    {
        CPacket msg = CPacket.create((short)PROTOCOL.CHAT_MSG_REQ);
        msg.push(msgField.GetComponent<InputField>().text);
        this.network_manager.send(msg);
        addChatList("=> Server : " + msgField.GetComponent<InputField>().text);

        msgField.GetComponent<InputField>().text = "";
        msgField.ActivateInputField();
        msgField.Select();
    }

    public void addChatList(string msg)
    {
        //chatList.GetComponent<InputField>().text += msg + "\r\n";
        if(chatLog)
            chatLog.text += msg + "\r\n";
    }

    private void Awake()
    {
        this.input_text = "";
        this.received_texts = new List<string>();
        this.network_manager = GameObject.Find("NetworkManager").GetComponent<CNetworkManager>();
    }

    public void on_receive_chat_msg(string text)
    {
        this.received_texts.Add(text);
        addChatList("Client <= : " + text);
    }
}
