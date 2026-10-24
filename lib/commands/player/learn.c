//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Player R&D";
    addCommandTemplate("lessons from ##Target##");
    addCommandTemplate("learn ##Value## from ##Target##");
    addCommandTemplate("enroll with ##Target##");
    addCommandTemplate("advance with ##Target##");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;
    if (canExecuteCommand(command))
    {
        ret = 1;
        string teacherName = regreplace(command,
            "^.* (from|with) (.+)$", "\\2");
        object teacher = getTarget(initiator,
            "lessons from " + teacherName, TargetEnvironment);
        string message;
        if (!teacher || !function_exists("teachableResearch", teacher))
        {
            message = "There is no research teacher by that name here.\n";
        }
        else if (sizeof(regexp(({ command }), "^lessons from ")))
        {
            message = sprintf("%s offers these lessons:\n", teacher->Name());
            foreach(string item in teacher->teachableResearch())
            {
                string name = getService("lessons")->lessonName(item);
                string refusal = teacher->lessonRefusal(initiator, item);
                message += sprintf("  %s: %s\n", name,
                    sizeof(refusal) ? refusal : "Ready to learn.");
            }
        }
        else if (sizeof(regexp(({ command }), "^enroll with ")))
        {
            string guild = teacher->teachingGuild();
            message = !guild ? "This teacher does not enroll students.\n" :
                (initiator->joinGuild(guild) ?
                    sprintf("You join the %s guild.\n", guild) :
                    "You cannot join: check existing membership, guild "
                        "exclusions, and any rejoining delay.\n");
        }
        else if (sizeof(regexp(({ command }), "^advance with ")))
        {
            string guild = teacher->teachingGuild();
            message = !guild ? "This teacher does not oversee promotions.\n" :
                (initiator->advanceRank(guild) ?
                    sprintf("You advance to %s in the %s guild.\n",
                        initiator->guildRank(guild), guild) :
                    "You cannot advance: check membership, the next "
                        "rank's level and research prerequisites, and "
                        "any promotion delay.\n");
        }
        else
        {
            string name = lower_case(regreplace(command,
                "^learn (.+) from .+$", "\\1"));
            string *matches = getService("lessons")->matchingLessons(
                teacher->teachableResearch(), name);
            message = "That lesson is not uniquely identified in this "
                "teacher's curriculum. Use 'lessons from <teacher>'.\n";
            if (sizeof(matches) == 1)
            {
                string item = matches[0];
                string refusal = teacher->lessonRefusal(initiator, item);
                if (sizeof(refusal))
                {
                    message = refusal + "\n";
                }
                else if (initiator->learnResearchFrom(teacher, item))
                {
                    message = sprintf("You %s %s with %s.\n",
                        initiator->isResearched(item) ? "learn" :
                            "begin studying", name, teacher->Name());
                }
                else
                {
                    message = "The lesson could not begin. Check your "
                        "research prerequisites and available points.\n";
                }
            }
        }
        tell_object(initiator, message);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Learn research from a nearby teacher.";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("Use 'lessons from <teacher>' to see a teacher's curriculum "
        "and requirements, then 'learn <lesson> from <teacher>'. A lesson "
        "uses the normal research prerequisites and costs. Some teachers "
        "also accept 'enroll with <teacher>' to join their guild and "
        "'advance with <teacher>' to request a promotion.", 78);
}
