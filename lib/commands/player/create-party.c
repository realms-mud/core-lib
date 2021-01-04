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
        addCommandTemplate("create party ##Value##");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        object Dictionary = load_object("/lib/dictionaries/partyDictionary.c");

        string name = regreplace(command, "create party( )*([^#]*)$", "\\2", 1);

        if (initiator->getParty())
        {
            notify_fail(sprintf("You are already in a party (%s).\n"
                "You must first leave it before joining another party.\n",
                initiator->partyName()));
        }
        else if (name)
        {
            ret = 1;
            tell_object(initiator, sprintf("You have created a party: %s\n",
                name));
            Dictionary->createParty(name, initiator);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Create a party";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("Create party allows a player to create a party that "
        "they can then add additional players to. This will provide "
        "a communication channel through which they can talk, the "
        "ability to see where other members are, and a way to share "
        "experience gained through questing together and adventuring "
        "or killing together.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: leave party, add party member, remove party member, "
        "dissolve party, party, follow party member, "
        "stop following party member";
}
