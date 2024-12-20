//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";
#include "/lib/modules/secure/logging.h"

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "General";
    addCommandTemplate("issue [-teleport] [-t ##Target##] [-c ##Value##]");
}

/////////////////////////////////////////////////////////////////////////////
private object getIssueTarget(string command, object initiator)
{
    object target = 0;
    if (sizeof(regexp(({ command }), "-t [^-]+")))
    {
        string targetString = regreplace(command, ".*-t ([^-]+)( .*|$)", "\\1", 1);

        target = present(targetString, initiator) ||
            present(targetString, environment(initiator)) ||
            find_object(targetString);
    }

    if (!target)
    {
        target = environment(initiator);
    }
    return target;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        ret = 1;
        object target = getIssueTarget(command, initiator);

        if (objectp(target))
        {
            string longDesc = "???";
            catch (longDesc = target->long());

            int teleportUser = sizeof(regexp(({ command }), "-teleport"));

            mapping data = ([
                "status": 0,
                "logged by": initiator->RealName(),
                "affected object": program_name(target),
                "location": program_name(environment(initiator)),
                "data": regreplace(command, ".*-c (.*$)", "\\1", 1) +
                    (teleportUser ? sprintf("\n\n*** NOTE: %s used teleport to "
                        "safety.\n", capitalize(initiator->RealName())) : "") + 
                    "\n\nItem Description:\n" + longDesc +
                    "\n\nCurrent trace data:\n" + 
                    (driver_info(-44) || "No errors found.\n")
            ]);

            saveIssue(data);
            
            object channels = load_object("/lib/dictionaries/channelDictionary.c");
            if (channels)
            {
                channels->broadcastMessage("issue logged by", 
                    sprintf("A new issue has been logged:\n"
                        "Affected Object: %s\nLocation: %s\nDetails: %s\n",
                        data["affected object"], data["location"], data["data"]),
                    initiator);
            }
            if (teleportUser)
            {
                move_object(initiator, StartLocation());
                command("look", initiator);
            }

            tell_object(initiator, configuration->decorate(
                "Your issue details have been logged.\n", "issue", "help",
                initiator->colorConfiguration()));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Log a defect/issue/typo/idea with/for a MUD object, quest, "
        "area, or item";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The issue command will report any problems or other "
        "feedback that a player might have with respect to a room, item, "
        "monster, quest, or any other thing they might interact with in "
        "the MUD. Given that the living mud can have serious issues that "
        "place users in an untenable situation, there is also a -teleport "
        "flag that will send the player to a safe location.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: set";
}

/////////////////////////////////////////////////////////////////////////////
protected string flagInformation(string flag, string colorConfiguration)
{
    string ret = "";
    string parsedFlag = regreplace(flag, "[^-]*(-[a-zA-Z]+).*", "\\1");
    
    switch (parsedFlag)
    {
        case "-t":
        {
            ret = "This flag allows a user to specify a target item that has "
                "an issue.";
            break;
        }
        case "-c":
        {
            ret = "This option allows the player to add additional "
                "free-form commentary about the issue/idea they are logging";
            break;
        }
        case "-teleport":
        {
            ret = "This flag can be used to teleport the user to a safe, "
                "theoretically error-free location in the event that you have "
                "been placed in an untenable situation. It is important to "
                "note that this action is logged and feeds directly in to "
                "the defect tracking system of the MUD, so inappropriate use of "
                "it will both be extremely obvious (imagine all wizzes seeing "
                "100 new issues logged with '<your name> used the teleport to "
                "safety mechanism') and will result in disciplinary action. "
                "However, you are strongly encouraged to use this flag when "
                "you are placed in a situation where you are unable to react. "
                "This includes rooms that throw errors that result in you not "
                "being able to leave, situations where your character will "
                "die or be otherwise adversely affected, and so on. In short, "
                "use common sense. If you use this as a means of quickly "
                "getting to town, a means of escape from imminent death or "
                "'sucker punching' during player-killing, this is most "
                "definitely inappropriate.";
            break;
        }
    }
    return format(ret, 72);
}
