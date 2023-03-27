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

#include <YSI_Coding\y_va>

/// <summary>Set the string of a specified player textdraw (with formatted option) Returns <c>0</c> on success.</summary>
/// <param name="playerid">The ID of the player to modify its player textdraw.</param>
/// <param name="textdraw">The textdraw to be modified.</param>
/// <param name="format">The format string.</param>
stock UI_SetPlayerTextDrawString(playerid, PlayerText:textdraw, const format[], ...)
{
	new 
		str[400];
	
	if (!IsPlayerConnected(playerid) || textdraw == INVALID_PLAYER_TEXT_DRAW) return 1;
	
	format(str, sizeof str, format, ___(3));
	PlayerTextDrawSetString(playerid, textdraw, str);
	return 0;
}

// EOF
