//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Party";
    addCommandTemplate("add party member ##Target##");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        object Dictionary = load_object("/lib/dictionaries/partyDictionary.c");
        string targetName = 
            regreplace(command, "add party member (.*)", "\\1", 1);

        object *targets = filter(users(), 
            (: lower_case($1->RealName()) == $2 :), lower_case(targetName));
        object target = sizeof(targets) ? targets[0] : 0;

        if (target)
        {
            object party = initiator->getParty();
            if (target->getParty())
            {
                notify_fail(sprintf("%s is already in a party (%s).\n"
                    "They must first leave it before joining another party.\n",
                    target->RealName(), target->partyName()));
            }
            else if(party)
            {
                ret = 1;

                tell_object(initiator, sprintf("You have added %s to your "
                    "party: %s\n", capitalize(target->RealName()), 
                    initiator->partyName()));

                tell_object(target, sprintf("You have a pending invite "
                    "to join a party: %s (%s)\nType 'accept party invite' "
                    "to join this party.\n", initiator->partyName(), 
                    capitalize(initiator->RealName())));

                Dictionary->createPartyRequest(target, party);
            }
            else
            {
                notify_fail("You must first create a party.\n");
            }
        }
        else
        {
            notify_fail(sprintf("Could not find a player named %s.\n",
                capitalize(targetName)));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Send out an invite to add a party member";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("Add party member sends an invite to another player "
        "so that they may join a party you have created. They can then "
        "accept the invite using tept party invite' command.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: accept party invite, leave party, create party, "
        "remove party member, dissolve party, party, follow party member, "
        "stop following party member";
}
