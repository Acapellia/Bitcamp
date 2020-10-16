using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameServer
{
	public enum PROTOCOL : short
	{
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

		END
	}
}
