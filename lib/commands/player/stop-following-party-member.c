//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        CommandType = "Party";
        addCommandTemplate("stop following [party member]");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        object Dictionary = load_object("/lib/dictionaries/partyDictionary.c");
        object party = initiator->getParty();

        if (party)
        {
            string wasFollowing = party->stopFollowing(initiator);

            if (stringp(wasFollowing))
            {
                ret = 1;
                tell_object(initiator, sprintf("You are no longer following : %s\n",
                    wasFollowing));

                object channels = load_object("/lib/dictionaries/channelDictionary.c");
                channels->broadcastMessage(party->partyName(),
                    sprintf("%s is no longer following %s.",
                        capitalize(initiator->RealName()),
                        wasFollowing), party);
            }
            else
            {
                notify_fail("You are not following anybody.\n");
            }
        }
        else
        {
            notify_fail("You are not currently in a party.\n");
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Stop following a party member";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("Stop following party member allows a player in a party "
        "to stop following the member they are currently following.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: create party, add party member, remove party member, "
        "dissolve party, party, follow party member, "
        "leave party";
}
