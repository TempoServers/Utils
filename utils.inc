#if defined _INC_tempo_utils
	#endinput
#endif
#define _INC_tempo_utils

/*==============================================================================


	Tempo Services

		Copyright (C) 2022 Martin Santiago and contributors

		This Source Code Form is subject to the terms of the Mozilla Public
		License, v. 2.0. If a copy of the MPL was not distributed with this
		file, You can obtain one at http://mozilla.org/MPL/2.0/.



==============================================================================*/

#include <a_samp>

stock Utils_ClearChat(playerid) {
    for (new i = 0; i < 30; i++) {
        SendClientMessage(playerid, -1, "");
    }
}

stock Utils_EncodePlayerName(playerid) {
    static
        currentUsername[MAX_PLAYER_NAME],
        encodedUsername[MAX_PLAYER_NAME];

    GetPlayerName(playerid, currentUsername);
    Base64Encode(encodedUsername, currentUsername);
    SetPlayerName(playerid, encodedUsername);
}

stock Utils_IsValidEmail(const email[]) //By Jan "DracoBlue" Schütze
{
	new len=strlen(email);
	new cstate=0;
	for(new i=0;i<len;i++)
	{
		if ((cstate==0 || cstate==1) && (email[i]>='A' && email[i]<='Z') || (email[i]>='a' && email[i]<='z')  || (email[i]=='.')  || (email[i]=='-')  || (email[i]=='_'))
		{
		}
		else
		{
			if ((cstate==0) &&(email[i]=='@'))
			{
				cstate=1;
			}
			else
			{
				return false;
			}
		}
	}
	if (cstate<1)
	{
		return false;
	}
	if (len<6)
	{
		return false;
	}
	if ((email[len-3]=='.') || (email[len-4]=='.') || (email[len-5]=='.'))
	{
		return true;
	}
	return false;
}

stock Utils_ValidEmail(const email[])
{
	return IsValidEmail(email);
}