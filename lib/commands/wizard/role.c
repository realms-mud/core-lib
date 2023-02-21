//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Wizard";
    addCommandTemplate("role [-t ##Target##] [-a ##Values##] [-r ##Values##] "
        "[-l]");
}

/////////////////////////////////////////////////////////////////////////////
private nomask object getRoleTarget(string command, object initiator)
{
    object target = 0;
    if (sizeof(regexp(({ command }), "-t [^-]+")))
    {
        string targetString = 
            regreplace(command, ".*-t ([^-]+)( .*|$)", "\\1", 1);
        object *targets = filter(users(), 
            (: $1->RealName() == $2 :), targetString);

        if (sizeof(targets))
        {
            target = targets[0];
        }
    }
    return target;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getRoleName(string command, object initiator)
{
    string methodName = 0;
    if (sizeof(regexp(({ command }), "(-a|-r) (.*)")))
    {
        methodName = regreplace(command, ".*(-a|-r) (.*)", "\\2", 1);
    }
    return methodName;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void listAllRoles(object initiator)
{
    mapping roleList = availableRoles();
    string message = "";

    string colorConfiguration = initiator->colorConfiguration();

    if (sizeof(roleList))
    {
        message = configuration->decorate(
            sprintf("\n%-11s    %-52s  %-11s\n",
                "Role Type", "Name of the Role", "Granter LVL"),
            "description", "roles", colorConfiguration);

        string *keys = sort_array(m_indices(roleList), (: $1 > $2 :));

        foreach(string role in keys)
        {
            string roleToDisplay = role;
            if (sizeof(roleToDisplay) > 52)
            {
                roleToDisplay = roleToDisplay[0..48] + "...";
            }
            message += configuration->decorate(
                    sprintf("%-11s    %-52s ", 
                        capitalizeAllWords(roleList[role]["type"]),
                        roleToDisplay),
                    roleList[role]["type"], "roles", colorConfiguration) +
                configuration->decorate(
                    sprintf(" %-11s\n", 
                        capitalizeAllWords(roleList[role]["add level"])),
                    roleList[role]["add level"], "wizard levels",
                    colorConfiguration);
        }
    }
    else
    {
        message = configuration->decorate("No roles have been created.\n",
            "no roles available", "roles", colorConfiguration);
    }

    tell_object(initiator, message);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("role"))
    {
        ret = 1;
        if (sizeof(regexp(({ command }), "-l")))
        {
            listAllRoles(initiator);
        }
        else
        {
            object target = getRoleTarget(command, initiator);
            string role = getRoleName(command, initiator);
            mapping roles = availableRoles();

            string message = "";

            if (member(m_indices(roles), role) < 0)
            {
                message = format(sprintf("The '%s' role is not available. "
                    "If the role is what you intended to use, you will first "
                    "need to add it using the 'create-role' command.\n",
                    role), 78);
            }
            else if (!target)
            {
                message = "The target does not appear to exist.\n";
            }
            else if (sizeof(regexp(({ command }), "-a")))
            {
                if (target->addRole(role))
                {
                    message = sprintf("The '%s' role was added to %s.\n",
                        role, capitalize(target->RealName()));
                }
                else
                {
                    message = sprintf("Failed to add the '%s' role to %s.\n",
                        role, capitalize(target->RealName()));
                }
            }
            else if (sizeof(regexp(({ command }), "-r")))
            {
                if (target->removeRole(role))
                {
                    message = sprintf("The '%s' role was removed from %s.\n",
                        role, capitalize(target->RealName()));
                }
                else
                {
                    message = sprintf("Failed to remove the '%s' role "
                        "from %s.\n",
                        role, capitalize(target->RealName()));
                }
            }

            if (message)
            {
                tell_object(initiator, configuration->decorate(message,
                    "message", "wizard commands", 
                    initiator->colorConfiguration()));
            }
        }
        notify_fail("Unknown usage of the 'role' command.\n"
            "Type 'help role' for usage information.\n");
    }
    return ret;
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
            ret = "Specify the target user that the method is going "
                "to be called on.";
            break;
        }
        case "-a":
        {
            ret = "Specify the role to add to the target specified "
                "with -t.";
            break;
        }
        case "-r":
        {
            ret = "Specify the role to remove from the target specified "
                "with -t.";
            break;
        }
        case "-l":
        {
            ret = "List all of the available roles.";
            break;
        }
    }
    return format(ret, 72);
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Add/remove a role for the specified player or wizard";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The role command adds (-a) or removes (-r) the "
        "specified role to/from a player or wizard. The granting "
        "wizard must be of the appropriate level for the specified role. "
        "New roles can be created with the 'create-role' command and "
        "all available roles can be listed with the -l flag. The flags "
        "are mutually-exclusive and cannot be used together.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: create-role";
}
