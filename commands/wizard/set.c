//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

private mapping parametersToFunction = ([
    "message in": "MessageIn",
    "msgin": "MessageIn",
    "message out": "MessageOut",
    "msgout": "MessageOut",
    "magical message in": "MagicalMessageIn",
    "mmsgin": "MagicalMessageIn",
    "magical message out": "MagicalMessageOut",
    "mmsgout": "MagicalMessageOut",
    "message home": "MessageHome",
    "home message": "MessageHome",
    "message clone": "MessageClone",
    "clone message": "MessageClone",
    "home location": "HomeLocation",
    "starting location": "StartLocation",
    "title": "Title",
    "pretitle": "Pretitle",
    "short": "short",
    "short description": "short",
    "description": "description",
    "long description": "description",
]);

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        CommandType = "Wizard";
        addCommandTemplate("set [-p ##Value##] [-v ##Value##]");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("set"))
    {
        string parameter = 0;
        string value = 0;
        
        if (sizeof(regexp(({ command }), "^set .*-p *[^-]+( -.*|$)")))
        {
            parameter = regreplace(command, "^set .*-p *([^-]+)( -.*|$)", "\\1");
            command = regreplace(command, "(^set *.*)( -p *[^-]+)( -.*|$)", "\\1\\3");
        }
        if (sizeof(regexp(({ command }), "^set .*-v *.+( -p.*|$)")))
        {
            value = regreplace(command, "^set .*-v *(.+)( -p.*|$)", "\\1");
        }

        if (member(parametersToFunction, parameter) && parameter && value)
        {
            ret = 1;
            call_other(initiator, parametersToFunction[parameter], value);
            tell_object(initiator, sprintf("You have set your '%s' to '%s'.\n",
                parameter, value));
        }
        else
        {
            notify_fail(sprintf("The '%s' parameter is not valid.\n", parameter || "???"));
        }
    }
    return ret;
}
