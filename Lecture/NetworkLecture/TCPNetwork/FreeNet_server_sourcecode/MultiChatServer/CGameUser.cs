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
		CUserToken token;
		public static bool isDebug = true;
		public CGameUser(CUserToken token)
		{
			this.token = token;
			this.token.set_peer(this);
		}

		void IPeer.on_message(Const<byte[]> buffer) {
			// ex)
			CPacket msg = new CPacket(buffer.Value, this);
			PROTOCOL protocol = (PROTOCOL)msg.pop_protocol_id();
			if(isDebug) {
				Console.WriteLine("------------------------------------------------------");
				Console.WriteLine("protocol id " + protocol);
			}
			switch(protocol) {
				case PROTOCOL.CHAT_MSG_REQ: {
						string text = msg.pop_string();
						if(isDebug) {
							Console.WriteLine(string.Format("text {0}", text));
						}
						/* 홍길동이 이 CGameUser객체(this)와 연결된 클라이언트라면
						 * 홍길동한테는 CHAT_MSG_ACK : 채팅 메시지 잘 받았어 라고 응답한다
						 * 
						 * 다른 클라이언트들인 임꺽정, 장길산한테는
						 * CHAT_MSG_DISPATCH : 받은 채팅데이터 전송해줄께
						 * 명령으로 전송한다
						 */
						CPacket response = CPacket.create((short)PROTOCOL.CHAT_MSG_ACK);
						response.push(text);
						send(response);

						response = CPacket.create((short)PROTOCOL.CHAT_MSG_DISPATCH);
						response.push(text);
						Program.sendAllClient(this, response);
					}
					break;
				case PROTOCOL.ROT_MSG_REQ: {
						float rotationX = msg.pop_Single();
						float rotationY = msg.pop_Single();
						float rotationZ = msg.pop_Single();
						float rotationW = msg.pop_Single();
						if(isDebug) {
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
				case PROTOCOL.MOV_MSG_REQ: {
						float positionX = msg.pop_Single();
						float positionY = msg.pop_Single();
						float positionZ = msg.pop_Single();
						if(isDebug) {
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
				case PROTOCOL.PARTICLE_MSG_REQ: {
						float positionX = msg.pop_Single();
						float positionY = msg.pop_Single();
						float positionZ = msg.pop_Single();
						int particleType = msg.pop_int32();

						if(isDebug) {
							Console.WriteLine(string.Format("posX {0}, posY {1}, posZ {2}, type {3}",
										positionX, positionY, positionZ, particleType));
						}
						CPacket response = CPacket.create((short)PROTOCOL.PARTICLE_MSG_ACK);
						response.push("OK");
						send(response);

						response = CPacket.create((short)PROTOCOL.PARTICLE_MSG_DISPATCH);
						response.push(positionX);
						response.push(positionY);
						response.push(positionZ);
						response.push(particleType);
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
