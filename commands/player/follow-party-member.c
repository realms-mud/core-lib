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
        addCommandTemplate("follow party member ##Target##");
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
            regreplace(command, "follow party member (.*)", "\\1", 1);

        object party = initiator->getParty();
        if (party && targetName)
        {
            object *members = filter(party->members(),
                (: capitalize($1->RealName()) ==
                    capitalize($2) :), targetName);

            if (sizeof(members) == 1)
            {
                if (environment(initiator) != environment(members[0]))
                {
                    notify_fail("You must both be in the same location.\n");
                }
                else if(party->following(initiator))
                {
                    string leaderName = party->following(initiator);
                    notify_fail(sprintf("You are currently following %s.\n"
                        "If you wish to follow someone else, stop following "
                        "%s first.\n", leaderName, leaderName));
                }
                else
                {
                    ret = 1;

                    tell_object(members[0], sprintf("You are now being followed by %s.\n",
                        capitalize(initiator->RealName())));

                    tell_object(initiator, sprintf("You are now following %s.\n",
                        capitalize(members[0]->RealName())));

                    party->follow(members[0], initiator);

                    object channels = load_object("/lib/dictionaries/channelDictionary.c");
                    channels->broadcastMessage(party->partyName(),
                        sprintf("%s is now following %s.",
                            capitalize(initiator->RealName()),
                            capitalize(members[0]->RealName())), party);
                }
            }
            else
            {
                notify_fail(sprintf("There is nobody named '%s' in "
                    "your party.\n", capitalize(targetName)));
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
    return "Follow a party member.";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("Follow party member allows you to automatically move to "
        "the location of another party member when they move. In order to "
        "initiate this action, you must be in the same location as the "
        "member you wish to follow. To end this action, you can use the "
        "'stop following party member' command.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: accept party invite, leave party, create party, "
        "add party member, dissolve party, party, remove party member, "
        "stop following party member";
}
