//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Wizard";
    addCommandTemplate("create-role [-t ##Values##] [-r ##Values##] [.*]");
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getType(string command, object initiator)
{
    string type = 0;
    if (sizeof(regexp(({ command }), ".*-t ([^-]+)")))
    {
        type = regreplace(command, ".*-t ([^-]+) -.*", "\\1", 1);
    }
    return type;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getRoleName(string command, object initiator)
{
    string role = 0;
    if (sizeof(regexp(({ command }), "-r (.+)")))
    {
        role = regreplace(command, ".*-r (.+)$", "\\1", 1);
    }
    return role;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("create-role"))
    {
        ret = 1;
        string role = getRoleName(command, initiator);
        string type = getType(command, initiator);
        mapping roles = availableRoles();

        string message = "";

        if (member(m_indices(roles), role) > -1)
        {
            message = sprintf("The '%s' role already exists.\n", role);
        }
        else if (!sizeof(regexp(({ command }), ".*-t ([^-]+) -r (.+)")))
        {
            message = "Both the -t and -r flags must be specified.\n";
        }
        else if (role && type && (role != "") && (type != ""))
        {
            if (createRole(role, type))
            {
                message = sprintf("The '%s' role was created.\n",
                    role);
            }
            else
            {
                message = sprintf("Failed to create the '%s' role.\n",
                    role);
            }
        }

        if (message)
        {
            tell_object(initiator, configuration->decorate(message,
                "message", "wizard commands", 
                initiator->colorConfiguration()));
        }
        notify_fail("Unknown usage of the 'create role' command.\n"
            "Type 'help create role' for usage information.\n");
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
            ret = "Specify the type of role that is being created. "
                "This must be one of: development, web master, area, "
                "guild, hr, liason, or leadership.";
            break;
        }
        case "-r":
        {
            ret = "Specify the name of the role to create.";
            break;
        }
    }
    return format(ret, 72);
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Create a role to be usable on the MUD.";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The create role command adds a role of the specified "
        "type that can then be used by players and wizards. Both the -t and "
        "-r flags must be used during invocation.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: role";
}
