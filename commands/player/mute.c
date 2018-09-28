//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        addCommandTemplate("mute [-a(ll|)] [-b(usy|)] [-s(houts*|)] "
            "[-c(han|hannels*|)] [##Target##]");
        addCommandTemplate("set silence [-a(ll|)] [-s(houts*|)] "
            "[-c(han|hannels*|)] [##Target##]");
        addCommandTemplate("set busy on");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        ret = 1;

        if (!initiator->isBusy() && ((command == "set busy on") ||
            sizeof(regexp(({ command }), "-b(usy)*"))))
        {
            initiator->toggleBusy();
            tell_object(initiator, "You have set your status to busy.\n");
        }
        else
        {
            string targetName = regreplace(command,
                "(mute|set silence) (-[a-z]+)* *([A-Za-z]+)$", "\\3", 1);

            if (initiator->block(targetName))
            {
                tell_object(initiator, format(sprintf("You are now blocking %s. You "
                    "will no longer see communication (say, tell, shout, channels, "
                    "emotes, or soul actions) from this person. All attempted "
                    "interactions by them will be logged in the event you need "
                    "to escalate a harassment claim.\n", 
                    capitalize(targetName)), 78));
            }
            else
            {
                tell_object(initiator, format(sprintf("Blocking %s failed. That "
                    "player does not exist.\n", targetName), 78));
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand)
{
    return "Send a message to everyone in your environment";
}

/////////////////////////////////////////////////////////////////////////////
protected string flagInformation(string flag)
{
    string ret = "";
    string parsedFlag = regreplace(flag, "[^-]*(-[a-zA-Z]+).*", "\\1");
    switch (parsedFlag)
    {
        case "-a":
        {
            ret = "This option will block all channels\n";
            break;
        }
        case "-b":
        {
            ret = "This option will set the player's busy flag, thereby "
                "temporarily blocking all tell attempts from others.\n";
            break;
        }
        case "-c":
        {
            ret = "This option will block the specified channel\n";
            break;
        }
        case "-s":
        {
            ret = "This option will block all shouts and poses.\n";
            break;
        }
    }
    return format(ret, 72);
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand)
{
    return format("Mute allows a player to block messages coming from "
        "individuals, channels, or shouts. It also allows players to "
        "set a 'busy' flag - a temporary block of directed (tell) "
        "messages.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand)
{
    return "See also: unmute, tell, whisper, reply, guild, and shout";
}
