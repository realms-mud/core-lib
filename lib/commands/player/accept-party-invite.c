//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Party";
    addCommandTemplate("accept party invite");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        object dictionary = load_object("/lib/dictionaries/partyDictionary.c");

        if (dictionary->hasPendingPartyRequest(initiator))
        {
            dictionary->acceptPartyRequest(initiator);

            object party = initiator->getParty();
            if (party)
            {
                ret = 1;
                tell_object(initiator, sprintf("You have joined the '%s' "
                    "party (%s)\n", capitalize(initiator->partyName()),
                    capitalize(party->creator()->RealName())));
            }
            else
            {
                notify_fail("You were unable to join the party.\n");
            }
        }
        else
        {
            notify_fail("You do not have a pending party invitation.\n");
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Accept an invite to join a party";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("Accept party invite is a command used to confirm "
        "a party invite that has been sent using the 'add party member' "
        "command.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: create party, leave party, add party member, "
        "remove party member, dissolve party, party, follow party member, "
        "stop following party member";
}
