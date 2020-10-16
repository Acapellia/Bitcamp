using FreeNet;
using FreeNetUnity;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Net;
using UnityEngine;

public class CFreeNetUnityService : MonoBehaviour
{
    CFreeNetEventManager event_manager;

    IPeer gameserver;
    CNetworkService service;

    public delegate void StatusChangedHandler(NETWORK_EVENT status);
    public StatusChangedHandler appcallback_on_status_changed;

    public delegate void MessageHandler(CPacket msg);
    public MessageHandler appcallback_on_message;

    private void Update()
    {
        if (this.event_manager.has_message())
        {
            CPacket msg = this.event_manager.dequeue_network_message();
            if(this.appcallback_on_message != null)
            {
                this.appcallback_on_message(msg);
            }
        }

        if (this.event_manager.has_event())
        {
            NETWORK_EVENT status = this.event_manager.dequeue_network_event();
            if(this.appcallback_on_status_changed != null)
            {
                this.appcallback_on_status_changed(status);
            }
        }
    }

	void Awake()
	{
		CPacketBufferManager.initialize(10);
		this.event_manager = new CFreeNetEventManager();
	}

	public void connect(string host, int port)
	{
		if (this.service != null)
		{
			Debug.LogError("Already connected.");
			return;
		}

		// CNetworkService객체는 메시지의 비동기 송,수신 처리를 수행한다.
		this.service = new CNetworkService();

		// endpoint정보를 갖고있는 Connector생성. 만들어둔 NetworkService객체를 넣어준다.
		CConnector connector = new CConnector(service);
		// 접속 성공시 호출될 콜백 매소드 지정.
		connector.connected_callback += on_connected_gameserver;
		IPEndPoint endpoint = new IPEndPoint(IPAddress.Parse(host), port);
		connector.connect(endpoint);
	}


	public bool is_connected()
	{
		return this.gameserver != null;
	}


	/// <summary>
	/// 접속 성공시 호출될 콜백 매소드.
	/// </summary>
	/// <param name="server_token"></param>
	void on_connected_gameserver(CUserToken server_token)
	{
		this.gameserver = new CRemoteServerPeer(server_token);
		((CRemoteServerPeer)this.gameserver).set_eventmanager(this.event_manager);

		// 유니티 어플리케이션으로 이벤트를 넘겨주기 위해서 매니저에 큐잉 시켜 준다.
		this.event_manager.enqueue_network_event(NETWORK_EVENT.connected);
	}

	public void send(CPacket msg)
	{
		try
		{
			this.gameserver.send(msg);
			CPacket.destroy(msg);
		}
		catch (Exception e)
		{
			Debug.LogError(e.Message);
		}
	}

	/// <summary>
	/// 정상적인 종료시에는 OnApplicationQuit매소드에서 disconnect를 호출해 줘야 유니티가 hang되지 않는다.
	/// </summary>
	void OnApplicationQuit()
	{
		if (this.gameserver != null)
		{
			((CRemoteServerPeer)this.gameserver).token.disconnect();
		}
	}
}
