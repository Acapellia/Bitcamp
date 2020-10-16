using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using FreeNet;

namespace CSampleServer
{
	using GameServer;

	/// <summary>
	/// 하나의 session객체를 나타낸다.
	/// </summary>
	class CGameUser : IPeer
	{
		public static bool isDebug = true;
		CUserToken token;

		public CGameUser(CUserToken token)
		{
			this.token = token;
			this.token.set_peer(this);
		}

		void IPeer.on_message(Const<byte[]> buffer)
		{
			// ex)
			CPacket msg = new CPacket(buffer.Value, this);
			PROTOCOL protocol = (PROTOCOL)msg.pop_protocol_id();
			if (isDebug)
			{
				Console.WriteLine("------------------------------------------------------");
				Console.WriteLine("protocol id " + protocol);
			}
			switch (protocol)
			{
				case PROTOCOL.CHAT_MSG_REQ:
					{
						string text = msg.pop_string();
						if (isDebug)
						{
							Console.WriteLine(string.Format("text {0}", text));
						}
                        CPacket response = CPacket.create((short)PROTOCOL.CHAT_MSG_ACK);
                        response.push(text);
                        send(response);

                        response = CPacket.create((short)PROTOCOL.CHAT_MSG_DISPATCH);
						response.push(text);
						Program.sendAllClient(this, response);
					}
					break;
				case PROTOCOL.ROT_MSG_REQ:
					{
						float rotationX = msg.pop_Single();
						float rotationY = msg.pop_Single();
						float rotationZ = msg.pop_Single();
						float rotationW = msg.pop_Single();
						if (isDebug)
						{
							Console.WriteLine(string.Format("rotX {0}, rotY {1}, rotZ {2}, rotW {3}",
										rotationX, rotationY, rotationY, rotationW));
						}
                        CPacket response = CPacket.create((short)PROTOCOL.ROT_MSG_ACK);
                        response.push("OK");
                        send(response);

                        response = CPacket.create((short)PROTOCOL.ROT_MSG_DISPATCH);
						response.push(rotationX);
						response.push(rotationY);
						response.push(rotationZ);
						response.push(rotationW);
						Program.sendAllClient(this, response);
					}
					break;
				case PROTOCOL.MOV_MSG_REQ:
					{
						float positionX = msg.pop_Single();
						float positionY = msg.pop_Single();
						float positionZ = msg.pop_Single();
						if (isDebug)
						{
							Console.WriteLine(string.Format("posX {0}, posY {1}, posZ {2}",
										positionX, positionY, positionZ));
						}
                        CPacket response = CPacket.create((short)PROTOCOL.MOV_MSG_ACK);
                        response.push("OK");
                        send(response);

                        response = CPacket.create((short)PROTOCOL.MOV_MSG_DISPATCH);
						response.push(positionX);
						response.push(positionY);
						response.push(positionZ);
						Program.sendAllClient(this, response);
					}
					break;
			}
		}

		void IPeer.on_removed()
		{
			Console.WriteLine("The client disconnected.");

			Program.remove_user(this);
		}

		public void send(CPacket msg)
		{
			this.token.send(msg);
		}

		void IPeer.disconnect()
		{
			this.token.socket.Disconnect(false);
		}

		void IPeer.process_user_operation(CPacket msg)
		{
		}
	}
}
