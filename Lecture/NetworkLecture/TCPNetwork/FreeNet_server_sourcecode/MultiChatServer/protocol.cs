using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameServer
{
	/* REQ : 채팅/MOV/ROT를 발생시킨 Client에서
	 *       서버로 전송하는 msg
	 * ACK : 서버에서 명령을 발생시킨 Client에 
	 *       잘 받았다고 전송하는 msg
	 * DISPATCH : 서버에서 수신한 명령을 
	 *            (명령을 발생시킨 Client를 제외한)
	 *            모든 Client에 Broadcasting하는 msg
	 */
	public enum PROTOCOL : short {
		BEGIN = 0,

		CHAT_MSG_REQ = 1,
		CHAT_MSG_ACK = 2,
		CHAT_MSG_DISPATCH = 3,

		ROT_MSG_REQ = 4,
		ROT_MSG_ACK = 5,
		ROT_MSG_DISPATCH = 6,

		MOV_MSG_REQ = 7,
		MOV_MSG_ACK = 8,
		MOV_MSG_DISPATCH = 9,

		PARTICLE_MSG_REQ = 10,
		PARTICLE_MSG_ACK = 11,
		PARTICLE_MSG_DISPATCH = 12,

		END
	}
}
