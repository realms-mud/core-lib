//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Party";
    addCommandTemplate("dissolve party");
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
            object creator = party->creator();
            if (initiator == creator)
            {
                ret = 1;
                tell_object(initiator, sprintf(
                    "You have dissolved your party: %s\n",
                    initiator->partyName()));
                party->dissolveParty();
            }
            else
            {
                notify_fail("Only the creator of the party can dissolve it.\n");
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
    return "Dissolve your party";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("Dissolve party allows a player to destroy the party of which "
        "they are currently a member and creator.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: create party, leave party, add party member, remove "
        "party member, party, follow party member, "
        "stop following party member";
}
