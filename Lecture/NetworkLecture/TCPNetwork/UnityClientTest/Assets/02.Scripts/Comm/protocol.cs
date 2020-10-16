using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace FreeNetUnity
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

		PARTICLE_MSG_REQ = 10,
		PARTICLE_MSG_ACK = 11,
		PARTICLE_MSG_DISPATCH = 12,

		END
	}
}
