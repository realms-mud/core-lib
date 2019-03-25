//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        CommandType = "Party";
        addCommandTemplate("remove party member ##Target##");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        object Dictionary = load_object("/lib/dictionaries/partyDictionary.c");
        string targetName = 
            regreplace(command, "remove party member (.*)", "\\1", 1);

        object party = initiator->getParty();
        if (party && targetName)
        {
            if (initiator != party->creator())
            {
                notify_fail(sprintf("Only the party's creator/owner (%s) can "
                    "remove members.\n", 
                    capitalize(party->creator()->RealName())));
            }
            else
            {
                object *members = filter(party->members(),
                    (: capitalize($1->RealName()) == 
                        capitalize($2) :), targetName);

                if (sizeof(members) == 1)
                {
                    ret = 1;

                    tell_object(initiator, sprintf("You have removed %s from your "
                        "party: %s\n", capitalize(members[0]->RealName()),
                        initiator->partyName()));

                    tell_object(members[0], sprintf("You have been removed from the "
                        "party: %s (%s)\n", initiator->partyName(),
                        capitalize(initiator->RealName())));

                    party->leaveParty(members[0]);

                    object channels = load_object("/lib/dictionaries/channelDictionary.c");
                    channels->broadcastMessage(party->partyName(), 
                        sprintf("%s has been removed from the party.",
                            capitalize(members[0]->RealName())), party);
                }
                else
                {
                    notify_fail(sprintf("There is nobody named '%s' in "
                        "your party.\n", capitalize(targetName)));
                }
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
    return "Remove a player from your party.";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("Remove party member removes a player from your current "
        "party. In order to use this command, you must be the creator or "
        "current owner of the party.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: accept party invite, leave party, create party, "
        "add party member, dissolve party, party, follow party member";
}
