#if defined _utils_included
    #endinput
#endif
#define _utils_included

/*==============================================================================


	Tempo Utils

		              GNU GENERAL PUBLIC LICENSE
                       Version 3, 29 June 2007

	Authors:
		- Martín Santiago (@martiagop)

	Contributors:
		-

	Special Thanks:
		-

==============================================================================*/

#include <a_samp>
#include <TempoUtils\utils_user-interface>


/// <param name="playerid">The ID of the player to clear the chat.</param>
/// <remarks>Since the chat log cannot be cleared, it only prints several lines of empty text.</remarks>
stock Utils_ClearPlayerChat(playerid) 
{
    for (new i = 0; i < 50; ++i)
        if (IsPlayerConnected(playerid)) SendClientMessage(playerid, -1, "");
}

/// <param name="email">Email to be validated</param>
/// <returns>Returns <c>true</c> if it is a valid email, <c>false</c> otherwise.</returns>
/// <remarks>Function originally made by Jan "DracoBlue" Schütze, but modified by Martin Santiago (@martiagop)</remarks>
/// <remarks>This function must be tested with many inputs</remarks>
/// <seealso>ValidEmail</seealso>
stock Utils_IsValidEmail(const email[])
{
	new 
        len = strlen(email),
        cstate = 0;
	
    for (new i = 0; i < len; ++i)
	{
		if ((cstate==0 || cstate==1) && (email[i]>='A' && email[i]<='Z') || (email[i]>='a' && email[i]<='z')  || (email[i]=='.')  || (email[i]=='-')  || (email[i]=='_') || (email[i] >= '0' && email[i] <= '9'))
            continue;
		else
		{
			if ((cstate == 0) && (email[i]=='@'))
				cstate = 1;
			else return false;
		}
	}

	if (cstate < 1 || len < 6) return false;
	if ((email[len-3]=='.') || (email[len-4]=='.') || (email[len-5]=='.'))	return true;
	
    return false;
}

/// <param name="email">Email to be validated.</param>
/// <returns>Returns <c>true</c> if it is a valid email, <c>false</c> otherwise.</returns>
stock ValidEmail(const email[])
{
	return Utils_IsValidEmail(email);
}

stock IsValidName(const source[])
{
    new length = strlen(source);
    if (!(3 <= length <= 20)) return 0;
    new pos = strfind(source, "_");
    if (pos == -1) return 0;
    new    us_count;
    for (new i; i != length; ++i)
    {
        switch (source[i])
        {
            case '_': ++us_count;
        }
        if (!i || i == pos + 1)
        {
            switch (source[i])
            {
                case 'A' .. 'Z': continue;
                case 'a' .. 'z': continue;
				case '0' .. '9': continue;
                default: return 0;
            }
        }
        else if (i && i != pos && i != pos + 1)
        {
            switch (source[i])
            {
                case 'A' .. 'Z': continue;
                case 'a' .. 'z': continue;
				case '0' .. '9': continue;
                default: return 0;
            }
        }
    }
    return (us_count == 1 && source[length - 1] != '_');
}

// Useless function?
stock PlayerPlaySoundEx(playerid, sound, Float:X, Float:Y, Float:Z)
{
	PlayerPlaySound(playerid, sound, X, Y, Z);
	return 1;
}

// EOF
