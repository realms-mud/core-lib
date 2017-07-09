//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void init()
{
    addCommandTemplate("skills [-co(mbat|)] [-cr(afting|)] [-e(rudite|)] "
        "[-g(eneral|)] [-l(anguage|)] [-m(agic|)] [-s(ubterfuge|)] [-a(ll|)] "
        "[-advance ##Item##] [-by ##Value##] [.*]");
}

/////////////////////////////////////////////////////////////////////////////
private nomask int executeAdvanceSkill(string command, object initiator)
{
    int ret = 0;

    if (sizeof(regexp(({ command }), "-advance [A-Za-z ]+")))
    {
        int value = 1;
        if (sizeof(regexp(({ command }), "-by ")))
        {
            value = to_int(regreplace(command, ".* -by ([0-9]+)", "\\1", 1));
            command = regreplace(command, " -by ([0-9]+)", "", 1);
        }

        string skill = regreplace(command, ".*-advance ([A-Za-z ]+)", "\\1", 1);
        object skills = load_object("/lib/dictionaries/skillsDictionary.c");
        if (skills)
        {
            if (skills->isValidSkill(skill))
            {
                ret = initiator->advanceSkill(skill, value);

                if (!ret)
                {
                    notify_fail(sprintf(
                        "Cannot advance '%s', it would cost %d points to raise it to level %d.\n",
                        skill, initiator->advanceSkillCost(skill, value),
                        initiator->getSkill(skill)));
                }
            }
            else
            {
                notify_fail(sprintf("Invalid skill: '%s'.\n", skill));
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int executeListSkills(string command, object initiator)
{
    string *types = ({});
    if (sizeof(regexp(({ command }), "-co(mbat)*( |$)")))
    {
        types += ({ "combat" });
    }
    if (sizeof(regexp(({ command }), "-cr(afting)*( |$)")))
    {
        types += ({ "crafting" });
    }
    if (sizeof(regexp(({ command }), "-e(rudite)*( |$)")))
    {
        types += ({ "erudite" });
    }
    if (sizeof(regexp(({ command }), "-g(eneral)*( |$)")))
    {
        types += ({ "general" });
    }
    if (sizeof(regexp(({ command }), "-l(anguage)*( |$)")))
    {
        types += ({ "language" });
    }
    if (sizeof(regexp(({ command }), "-m(agic)*( |$)")))
    {
        types += ({ "magic" });
    }
    if (sizeof(regexp(({ command }), "-s(ubterfuge)*( |$)")))
    {
        types += ({ "subterfuge" });
    }
    if (sizeof(regexp(({ command }), "-a(ll)*( |$)")) ||
        (command == "skills"))
    {
        types += ({ "combat", "crafting", "erudite", "subterfuge", "general",
            "magic", "language" });
    }

    if (sizeof(types))
    {
        tell_object(initiator, initiator->skillsList(types));
    }

    return sizeof(types) > 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    // This should always be true, but if not, the command should fail
    if (canExecuteCommand(command))
    {
        notify_fail("skills: invalid subcommand.\n");
        
        ret = executeAdvanceSkill(command, initiator) ||
            executeListSkills(command, initiator);
    }
    return ret;
}