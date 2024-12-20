//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Party";
    addCommandTemplate("leave party");
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
            ret = 1;
            tell_object(initiator, sprintf("You have left your party: %s\n",
                initiator->partyName()));
            party->leaveParty(initiator);
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
    return "Leave your party";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("Leave party allows a player to leave the party of which "
        "they are currently a member.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: create party, add party member, remove party member, "
        "dissolve party, party, follow party member, "
        "stop following party member";
}
